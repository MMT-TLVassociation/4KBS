# 4KBS

本アプリでは、ISDB-S3対応のBon driverを使用。
https://github.com/MMT-TLVassociation/BonDriver_BDA


コマンドライン専用のBonRecTestと上記ISDB-S3対応のBon driverを使用すると、4K BS/CSの TLVストリームを保存できる。
https://github.com/rndomhack/BonRecTest

使用方法は、Windowsのコマンドプロンプトで、下記のように実行すると、CH000 (CH000=1,11842.560,R,0,BS01/TS0,0x1,0xB070)にチューニングする。
BonRecTest --driver BonDriver_BDA.dll --output hoge.ts --space 0 --channel 0

NHK BS8Kの場合は、CH009なので、
BonRecTest --driver BonDriver_BDA.dll --output hoge.ts --space 0 --channel 9
を実行すると、8K放送のTLVストリームを保存できる。


本アプリはBonRecTestにGUI(Windows MFC)を実装し、さらに2チャンネル同時に受信記録できるようにしたものである。

![4K](https://user-images.githubusercontent.com/59105039/161933298-fb768867-fa30-4c81-81c2-efe5880b2c2e.png)

番組表機能、Decoderなどは未実装。
