#include "lazypcscfelicalite.h"

using LazyPCSCFelicaLite::PCSCFelicaLite;
using LazyPCSCFelicaLite::PCSCErrorException;
using LazyPCSCFelicaLite::PCSCIllegalStateException;
using LazyPCSCFelicaLite::PCSCCommandException;
using LazyPCSCFelicaLite::PCSCFatalException;
using LazyPCSCFelicaLite::PCSCCryptographicException;
using LazyPCSCFelicaLite::FelicaErrorException;
using LazyPCSCFelicaLite::FelicaFatalException;
using LazyPCSCFelicaLite::PCSCCardRemovedException;

#define ID1 0x010101144C0F0802
#define ID2 0x01140214690F0009
#define ID3 0x0114B3F33A13B31B

int main()
{
	PCSCFelicaLite f = PCSCFelicaLite();
	printf("かざしてください...\n");
	while (1)
	{
		printf("CARD ON \r");
		//カードに自動接続
		//カードがかざされるのを無限に待つ
		f.autoConnectToFelica(INFINITE);

		//カードのUID(IDm)を取得
		uint8_t uid[256] = { 0 };
		int len = f.readUID(uid);
		for (int i = 0; i < len; i++)
				printf("%d", uid[256]);
				printf("\n");
				Sleep(1000);
			if (len == ID1)
			{
				printf("スタートの処理");
			}
			if (len == ID2)
			{
				printf("折り返し地点の処理");
			}
			if (len == ID3)
			{
				printf("ゴールの処理");
			}
			/*if (len )
			{
				printf("条件を満たしていない時のゴールの処理");
			}*/
				else {
					printf("CARD OFF\r");
				}
	}
}