/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2017 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 * 
 *  上記著作権者は，以下の(1)〜(4)の条件を満たす場合に限り，本ソフトウェ
 *  ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
 *  変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *      また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
 *      由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
 *      免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
 *  に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
 *  アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
 *  の責任を負わない．
 * 
 *  $Id: target_kernel.h 789 2017-04-01 07:28:08Z ertl-hiro $
 */

/*
 *		kernel.hのターゲット依存部（Mac OS X用）
 *
 *  このインクルードファイルは，kernel.hでインクルードされる．他のファ
 *  イルから直接インクルードすることはない．このファイルをインクルード
 *  する前に，t_stddef.hがインクルードされるので，それらに依存してもよ
 *  い．
 */

#ifndef TOPPERS_TARGET_KERNEL_H
#define TOPPERS_TARGET_KERNEL_H

/*
 *  ターゲット依存部でサポートできる機能
 */
#define TOPPERS_TARGET_SUPPORT_DIS_INT		/* dis_int */
#define TOPPERS_TARGET_SUPPORT_ENA_INT		/* ena_int */
#define TOPPERS_TARGET_SUPPORT_RAS_INT		/* ras_int */
#define TOPPERS_TARGET_SUPPORT_PRB_INT		/* prb_int */
#define TOPPERS_TARGET_SUPPORT_OVRHDR		/* オーバランハンドラ */

/*
 *  高分解能タイマのタイマ周期
 *
 *  タイマ周期が2^32の場合には，このマクロを定義しない．
 */
#undef TCYC_HRTCNT

/*
 *  高分解能タイマのカウント値の進み幅
 */
#define TSTEP_HRTCNT	1U

/*
 *  割込み優先度の範囲
 *
 *  TMIN_INTPRIの定義を変更することで，どのレベルよりも高い割込み優先度
 *  を持つものをカーネル管理外の割込みとするかを変更できる．
 *
 *  TMIN_INTPRIに設定できる値は，-6〜-1の範囲である．例えばTMIN_INTPRI
 *  を-5に設定すると，レベル7（NMI）とレベル6の割込みがカーネル管理外と
 *  なる．TMIN_INTPRIを-6に設定すると，レベル7の割込み（NMI）以外にカー
 *  ネル管理外の割込みを設けないことになる．
 */
#ifndef TMIN_INTPRI
#define TMIN_INTPRI		(-6)		/* 割込み優先度の最小値（最高値）*/
#endif /* TMIN_INTPRI */
#define TMAX_INTPRI		(-1)		/* 割込み優先度の最大値（最低値） */

#if defined(__aarch64__)
/* 64bitではタスクのスタックからdispatchされた場合にスタックが不足するので、強制的に加算する
 kernel.hの定義を上書きする
 本来はkernel_target_impl.hで定義したいが、impl.hを読まないパスもあるのでここで定義する

*/
#define TOPPERS_COUNT_SZ(sz, unit)	((((sz)+20480) + (unit) - 1) / (unit))
#define TOPPERS_ROUND_SZ(sz, unit)	((((sz)+20480) + (unit) - 1) & ~((unit) - 1))
#endif




#endif /* TOPPERS_TARGET_KERNEL_H */
