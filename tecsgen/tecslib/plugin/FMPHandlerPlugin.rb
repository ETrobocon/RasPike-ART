# coding: utf-8
#
#  TECS Generator
#      Generator for TOPPERS Embedded Component System
#  
#   Copyright (C) 2019-2020 by TOPPERS Project
#--
#   上記著作権者は，以下の(1)〜(4)の条件を満たす場合に限り，本ソフトウェ
#   ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
#   変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
#   (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
#       権表示，この利用条件および下記の無保証規定が，そのままの形でソー
#       スコード中に含まれていること．
#   (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
#       用できる形で再配布する場合には，再配布に伴うドキュメント（利用
#       者マニュアルなど）に，上記の著作権表示，この利用条件および下記
#       の無保証規定を掲載すること．
#   (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
#       用できない形で再配布する場合には，次のいずれかの条件を満たすこ
#       と．
#     (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
#         作権表示，この利用条件および下記の無保証規定を掲載すること．
#     (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
#         報告すること．
#   (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
#       害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
#       また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
#       由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
#       免責すること．
#  
#   本ソフトウェアは，無保証で提供されているものである．上記著作権者お
#   よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
#   に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
#   アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
#   の責任を負わない．
#  
#  $Id: FMPHandlerPlugin.rb 3203 2021-02-06 12:27:30Z okuma-top $
#++

class FMPHandlerPlugin < CelltypePlugin
  @@handler_list = {
    "INT_REQUEST"   =>
        [:InClass,    "CFG_INT( {{interruptNumber}}, { {{attribute}}, {{interruptPriority}} })"],
    "INT_SERVICE_ROUTINE" =>
        [:InClass,    "CRE_ISR( {{id}}, { {{attribute}}, $cbp$, {{interruptNumber}}, tISR_start, {{isrPriority}} })"],
    "INT_HANDLER"   =>
        [:InClass,    "DEF_INH( {{interruptHandlerNumber}}, { {{attribute}}, $id$_start})"],
    "CPU_EXCEPTION_HANDLER" =>
        [:InClass,    "DEF_EXC( {{cpuExceptionHandlerNumber}}, { {{attribute}}, $id$_start})"],
    "INIT_ROUTINE"  =>   # InClassの場合、初期化ルーチン、OutOfClassの場合、グローバル初期化ルーチン
        [:Any,        "ATT_INI({ {{attribute}}, $cbp$, tInitializeRoutine_start })"],
    "TERM_ROUTINE"  =>   # InClassの場合、終了ルーチン、OutOfClassの場合、グローバル終了ルーチン
        [:Any,        "ATT_TER({ {{attribute}}, $cbp$, tTerminateRoutine_start })"],
  }

  #celltype::     Celltype        セルタイプ（インスタンス）
  def initialize( celltype, option )
    super
    @celltype = celltype
    # @class_name = option.gsub( /\A"(.*)/, '\1' )    # 前後の "" を取り除く
    # @class_name.sub!( /(.*)"\z/, '\1' )
    @class_name = CDLString.remove_dquote option
    # p "FMPHandler: " + @class_name
    @cell_list = []
  end

  #=== 新しいセル
  #cell::        Cell            セル
  #
  # celltype プラグインを指定されたセルタイプのセルが生成された
  # セルタイププラグインに対する新しいセルの報告
  def new_cell( cell )
    @cell_list << cell
    if @@handler_list.has_key?(@class_name) == false
      # this will be caused by wrong celltype definition in kernel.cdl.
      raise "FMPHandlerPlugin: #{@class_name} is unknown"
    end
    root = cell.get_owner.get_class_root
    if root then
      class_type = root.get_class_type
      if class_type == nil then
        cdl_error2( cell.get_locale, "FMH9999 $1: is placed in root region. Handlers must be placed in CLS_PRC1, CLS_ALL_PRC1 specified region. Processos number can be varied.", cell.get_name )
        return
      end
      dbgPrint "FMPHandlerPlugin: new_cell #{cell.get_name} #{class_type.get_option} #{@@handler_list[@class_name][0]}\n"
      if class_type == nil then
        # このエラーは起きないハズ
        cdl_error2( cell.get_locale, "FMH9999 $1: not in class region or no class specified region exists.", cell.get_name )
      elsif @@handler_list[@class_name][0] == :InClass then
        # puts "FMPHandlerPlugin: OutOfClass needed: #{class_type.get_option}"
        # if class_type.get_option != "OutOfClass" then
        #   cdl_error2( cell.get_locale, "FMP9999 $1: not be placed out of class region", cell.get_name )
        # end
        if class_type.get_option[0] == :global then
          cdl_error2( cell.get_locale, "FMH9999 $1: is placed global region. Kernel objects (not handlers) must be placed in CLS_PRC1, CLS_ALL_PRC1 specified region. Processos number can be varied.", cell.get_name )
        end
      end
    else
      raise "root is nil"
    end
  end

  #=== FMPObjectPlugin#print_cfg_cre
  # CRE_XXXの出力
  # file:: FILE:     出力先ファイル
  # indent :: string:   インデント用のtab
  def print_cfg_cre(file, cell, indent)
    # p "print_cfg_cre: #{cell.get_name} #{@class_name}"
    file.print indent, "/* FMPHandlerPlugin: #{cell.get_name} */\n"
    if @@handler_list.has_key?(@class_name) == false
      raise "#{@class_name} is unknown"
    else
      cfg_str = @@handler_list[@class_name][1]
      file.print indent
    end

    celltype   = cell.get_celltype
    name_array = celltype.get_name_array cell

    # {{attribute}} の置換
    cfg_str2 = cfg_str.gsub(/\{\{([a-zA-Z0-9_]*?)\}\}/) { |match|
      # p "match: #{match}"
    	name = $1.to_sym
      celltype.get_cell_attr_var_init_str( cell, name_array, name )
		}

    # $xxx$ の置換
    cfg_str3 = celltype.subst_name( cfg_str2, name_array )

    file.print cfg_str3, ";\n"
  end

  def val attr
    return @celltype.get_cell_attr_var_init_str( @cell, @name_array, attr )
  end

  #=== tCelltype_factory.h に挿入するコードを生成する
  # file 以外の他のファイルにファクトリコードを生成してもよい
  # セルタイププラグインが指定されたセルタイプのみ呼び出される
  def gen_factory file
    f = AppFile.open( "#{$gen}/tecsgen.cfg" )
    f.print "/* Generated by FMPHandlerPlugin */\n"
    option_prev = nil
    indent = ""
    @cell_list.each{ |cell|
      root = cell.get_owner.get_class_root

      class_type = root.get_class_type
      if class_type.get_plugin.get_PU_attr[ :locality ] == "only" then
        option = class_type.get_plugin.get_PU_attr[:class_name] # 処理単位用のクラス指定を使用
        comment = ""
      else
        prc_id = class_type.get_plugin.get_PU_attr[ :processorID ]
        option = FMPPlugin.get_prc_only( prc_id )
        dbgPrint "FMPHandlerPlugin: get_only prc_id=#{prc_id}\n"
        comment = "       // class is changed from '#{class_type.get_plugin.get_PU_attr[:class_name]}' to processor restricted class '#{option}'"
      end
      if option != option_prev then
        if option_prev != nil then
          if option_prev != :root then
            f.print "}\n"
          end
        end
        if option != :root then
          f.print "CLASS(#{option}){#{comment}\n"
          indent = "  "
        else
          indent = ""
        end
        option_prev = option
      end
      print_cfg_cre f, cell, indent
    }
    if option_prev != nil then  # 実際のところ nil になることはないハズ
      if option_prev != :root then
        f.print "}\n"
      end
    end
    f.close
  end

end


  
