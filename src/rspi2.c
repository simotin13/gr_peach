#include "iodefine.h"

void rspi2_init()
{
	// SPI2 無効化
	RSPI2.SPCR = 0x00;

	// 端子制御レジスタ（SPPCR）
	// TODO
	// RSPI2.SPPCR


	// 制御レジスタ(SPCR)
	// 7: SPRIE  受信割り込み許可 ON
	// 6: SPE    SPI有効 ON
	// 5: SPTIE  送信割り込み許可 ON
	// 4: SPEIE  エラー割り込み許可 ON
	// 3: MSTR   マスタモード(0: スレーブモード 1: マスタモード) マスターモード
	// 2: MODFEN モードフォルト有効 ON
	// 1: 0固定
	// 0: 0固定
	RSPI2.SPCR = 0xFC;

	// スレーブセレクト極性レジスタ(SSLP)
	// 0x00: 0:SSL信号は0アクティブ 1:SSL信号は１アクティブ
	RSPI2.SSLP = 0x00;


	// データレジスタ（SPDR）


	// ビットレートレジスタ（SPBR）

}
