# SyulimeTracker_BNO08x

AdafruitのBNO08x用ライブラリ、`Adafruit_BNO08x`を改造したものです。

# 変更点

デフォルトではこのライブラリ単体によってI2Cのピンを変更出来ません。  
しかし、ESP32は内部のGPIO MatrixによってI2Cのピンを変更する事ができます。  
(ArduinoでもソフトウェアI2Cを用いる事で変更可能である。)

そこで、通常はI2Cアドレスを渡すコンストラクタにSDA、SCLピンの番号を渡すようにしました。  
内部的には`<Wire>.begin`に対してピン番号を渡しているだけになります。  
(もっと正確にいうとこのライブラリ自体はI2Cの通信をしていないので、BusIOに渡しているだけである。)

# 依存関係

このライブラリを使用するには、元ライブラリである`Adafruit_BNO08x`とほぼ同じ依存関係を解決する必要があります。  
ただし、`Adafruit_BNO08x`自体は必要なく、`Adafruit_BusIO`ライブラリの代わりにカスタマイズされた専用ライブラリを使用する必要があります。  

# インストール

もし嫌でないなら、以下の方法を使ってインストールするのを推奨します。

1. Arduinoディレクトリ内の`libraries'ディレクトリにこのレポジトリをCloneします。  
  通常、Arduinoディレクトリはユーザーのドキュメントディレクトリにあります。
2. 同様に、[`nattyan-tv/SyulimeTracker_BusIO`](https://github.com/nattyan-tv/SyulimeTracker_BusIO)レポジトリもCloneします。
3. Arduino IDEを開き、パッケージマネージャーから`Adafruit BNO08x`をインストールします。  
  正常に動作させるためのそのほかの依存関係が必要なので、依存関係までインストールしてください。
