#include "iodefine.h"

static void sci0_init(void)
{
	// SCR.TIE, RIE, TE, RE, TEIEビットを0に設定
	SCIF0.SCSCR = 0x0000;

	// GPIO
	// P2_14:TX
	// P2_15:RX
	// PM 0:出力モード 1:入力モード
	GPIO.PM2 = 0x8000;

	// PMC 0:ポート 1:兼用モード
	GPIO.PMC2 = 0xC000;

	// SMR、SCMR、SEMRレジスタに送信/受信フォーマットを設定

	// BRRレジスタに値を設定

	// SCR.TE, REビットを“1”に設定、およびSCR.TIE, RIEビットを設定
}
