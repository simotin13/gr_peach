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

    // CKE[1:0] SCKは汎用入出力ポートとして使用(0を指定)

    // SMR、SCMR、SEMRレジスタに送信/受信フォーマットを設定
    // b0 - b1 CKS[1:0] 0:P1Φ, 1:P1Φ/4 2:P1Φ/16 3:P1Φ/64 設定値はBRRのnの値になる
    // b2 MP    0: マルチプロセッサ通信モードを禁止 1: マルチプロセッサ通信モードを許可
    // b3 STOP  0: 1ストップビット 1: 2ストップビット
    // b4 PM    0: 偶数パリティ 1: 奇数パリティ
    // b5 PE    0: パリティ無効 1: パリティ有効
    // b6 CHR   0: 8ビットデータ 1: 7ビットデータ
    // b7 CM    0: クロック同期式モード 1: クロック非同期式モード
    SCIF0.SCSMR = 0x00;

    // BRRレジスタに値を設定
    // SEMR.ABCS
    // 0:基本クロック 16サイクルの期間が1ビット期間となる
    // 1:基本クロック 8サイクルの期間が1ビット期間となる
    SCIF0.SCEMR = 0x00;

    // SEMR.ABCS: 0, CKE[1:0]:0, B(ボーレート): 115200
    SCIF0.SCBRR = 0x11;

    // SCR.TE, REビットを1に設定、およびSCR.TIE, RIEビットを設定
    // b1-b0:CKE :0
    // b2:TEIE   0:送信終了割り込みを禁止 1:送信終了割り込みを許可
    // b3:MPIE  0:マルチプロセッサ通信モードの割り込みを禁止 1:マルチプロセッサ通信モードの割り込みを許可
    // b4:RE     0:受信を禁止 1:受信を許可
    // b5:TE     0:送信を禁止 1:送信を許可
    // b6:RIE    0:受信割り込みを禁止 1:受信割り込みを許可
    // b7:TIE    0:送信割り込みを禁止 1:送信割り込みを許可
    SCIF0.SCSCR = 0x34;
}

static uint8_t tx_buf[256];
static uint8_t tx_len;
static uint8_t tx_cnt;
static uint8_t rx_buf[256];
static uint8_t rx_len;

int sci0_send(uint8_t *buf, uint32_t len)
{
    // SCFSR.TENDビットが1になるまで待つ
    // b2 TEND 0:送信中 1:送信終了
    if ((SCIF0.SCFSR & 0x04) == 0)
    {
        // 送信中
        return -1;
    }
    if (tx_len < len)
    {
        // 送信サイズが大きい
        return -1;
    }

    memcpy(tx_buf, buf, len);

    // TEビット, TIEビットを1に設定
    SCIF0.SCSCR |= 0xA0;
    return 0;
}

