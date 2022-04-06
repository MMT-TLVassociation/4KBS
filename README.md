# 4K BS/CS recorder

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



誰でも自由に入手、使用、改変、再頒布可能です。
GNU General Public License version 3.0（GPL v3.0）

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 3
of the License, or any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see http://www.gnu.org/licenses/.
