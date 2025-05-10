# Raspi用 SPIKE制御開発環境「RasPike-ART（ラスパイクアート）」

2024/12/22 RasPike-ARTを正式リポジトリとして公開しました。
それに伴い、旧ytoi/RasPike-ARTリポジトリはETrobocon/libraspike-artリポジトリに移りました。

## はじめに

この環境はETロボコン用にraspberryPiとLEGO(R)のSPIKE Prime(R)を接続して動作させるためのものです。raspberry側のEV3RT互換環境と、SPIKE側の制御ソフトからなります。

EV3RTのベースとなるraspberry-Pi用aspシミュレータはMac OS X用のシミュレータをraspi用に修正したものとなっています。
https://www.toppers.jp/asp3-e-download.html

また、linux用の変更やsetjmp/longjmpのmangleに関しては
https://qiita.com/morioka/items/a186fff4db1eabb7e7de
を参考にしています。

本SWはmaosxシミュレータの成果物および、TOPPERS様の「箱庭」プロジェクトでのathrillの成果物を多く使用しています。感謝いたします。

RasPike-ARTはSPIKE側にSPIKE-RTで作られた受信ソフトウェア[libraspike](https://github.com/ETrobocon/libraspike-art)を利用したものです。
旧来のRasPike(https://github.com/ETrobocon/RasPike)と比較して、以下のような特徴があります。

- SPIKE側のプログラムがmicro pythonではなく、SPIKE-RTを使用しており、リアルタイム性が高まっている
　RasPikeのデータ送信周期は30msecほどかかっていましたが、RasPike-ARTでは10msecとなっています（もう少し早くなる可能性あり)
- USB接続を用いているので、ポートがA-F全て利用可能
- RasPikeはETロボコン用として決まった構成（ポートと繋ぐもの）に限定されていましたが、任意のデバイスをつなげて利用することができます
- EV3RTのAPIではなく、SPIKE-RTのAPIを使うことができるため、SPIKEから得られる情報量が多いです
　ジャイロは３軸の情報が取れますし、Hubのディスプレイ、スピーカーなども利用できます


# 構成

RasPike-ARTの構成は以下のようになります。
**注意！）USBケーブルは充電専用のケーブルでは動作しません。通信ができるUSBケーブルを使う必要があります。**

![RasPike-ART構成](https://github.com/user-attachments/assets/0f806598-9e91-4606-ba27-edb468259ecf)


# 使い方

## 使用できるRaspberryPiとOS

現在確認しているのはRasPi4とRaspberry OS(64bit)のみです。従来RasPikeで使用していたBullseye 32bitでは動作しないので、注意してください。

下記の環境で動作確認をしています。
```Linux raspberrypi 6.6.51+rpt-rpi-v8 #1 SMP PREEMPT Debian 1:6.6.51-1+rpt3 (2024-10-08) aarch64 GNU/Linux```


## ファイルの取得

RasberryPiの任意のディレクトリで必要なファイルを取得します。

```
git clone --recursive https://github.com/ETrobocon/RasPike-ART.git
cd RasPike-ART
```

## SPIKEへのプログラム書き込み

### 書き込み環境のセットアップ
SPIKEヘの書き込みにはpythonを使うため、その環境をセットアップします。

```
cd sdk/workspace
make -f ../common/Makefile.raspike-art setup_spike_env
```

ちょっと時間がかかりますが、これでRasPike-ART/toolsにpythonの仮想環境が作成されます。同時にUSBで通信するのに必要な環境を持ってきます。

この作業は一度やればそのあとやる必要はありません。

### SPIKEへの書き込み

SPIKEの電源を落としてUSBを抜き、Bluetoothボタンを押したまま再度差し込みます。ボタンがカラフルに変化するまで押し続けます。これがDFUモードに入った状態です。
[https://afrel.co.jp/product/spike/technology-spike/basic/software-basic/54122/](https://afrel.co.jp/product/spike/technology-spike/basic/software-basic/54122/)　の「Connect your Hub in Update Mode」の説明も参考にしてください。

この状態で、
```
make -f ../common/Makefile.raspike-art update_spike
```

と打ち込みます。

```
Writing memory...
0x08008000  130600 [=========================] 100% 
Exiting DFU...
Finished
+ rm -rf firmware.dfu
```

のような表示が出たら書き込み終了です。
この作業はSPIKE側のプログラムが更新された場合に毎回行う必要があります。

## RaspberryPi側のプログラムのコンパイル

サンプルでsample_c5のspike版sample_c5_spikeがありますので、それをコンパイルしてみます。

SPIKEのAPIを使うには、

```
#include "spike/pup/motor.h"
#include "spike/pup/colorsensor.h"
```

のような記述でSPIKE-RTと同じAPIを使うことが可能です。

makeは

```
make img=sample_c5_spike
```

とすることで、必要なライブラリ(RasPike-ART)が結合されます。(2025/5/10よりsample_c5_spikeはフォースセンサーのスタートで走り出すようになっています）

### サンプルのポート割り付け

| ポート | センサ・モーター |
| ---- | --- |
|A|右モーター|
|B|左モーター|
|E|カラーセンサー|

## プログラムの実行

SPIKEのセンターボタンを長押しして、一度電源を切ります。USBで接続しているときはSPIKEのディスプレイには3x3の四角が表示された状態になります。
そこで、再度センターボタンを押すと、「∞」のマークが表示されます。
その状態で、workspaceで

```
make start
```

とすることでプログラムが実行され、初期通信後「ET」の文字が現れて、SPIKE側の受けが準備できていることを知らせます。

## プログラムの停止

ctrl+cでプログラムを停止します。その後SPIKEのセンターボタンを長押しして電源を切ります。

再度やる場合はSPIKEのON->RasPiのプログラム実行

の順でやります。この順がずれたり、他の機器をUSBで繋いでいる場合には接続がうまくいかないことがあります。
（この辺りの制限は[https://github.com/ETrobocon/libraspike-art](https://github.com/ETrobocon/libraspike-art.git)の「通信用のAPI」を参照ください）

# APIの対応

SPIKE-RTのAPIがほぼ使えます。
[https://spike-rt.github.io/spike-rt/en/html/index.html](https://spike-rt.github.io/spike-rt/en/html/index.html)

制限などは下記を参照して下さい。
[https://github.com/ETrobocon/libraspike-art](https://github.com/ETrobocon/libraspike-art)


# EV3RT（もとのRasPike含む）からの移植について

EV3に関するAPI（モーターとかセンサー、ブロックに関するもの）は使えません。SPIKE APIに置き換えてください。

また、
```
#include "ev3api.h"
```
は
```
#include "spikeapi.h"
```
に置き換えてください。


# RasPike-ARTの更新

RasPike-ARTが更新される場合があります。
その場合、以下のようにして更新をしてください。
(今sdk/workspaceにいるとします)

```
cd ../../
git submodule update --remote 
cd sdk/workspace
make clean_art
make clean
```

RasPike-ARTが更新された場合、spikeのバイナリも更新されていることがあるため、SPIKEのプログラムの更新を行なってください。

# SPIKEファームの戻し方
元の教育用ファームに戻したい場合、以下のページを参考にファームをダウンロードしてください。
RasPikeを使う場合にはSPIKEファームのver2系を入れてください。ver3では動作しません。

https://www.learningsystems.co.jp/products/Robotics/Spike/SPIKE_support.html

