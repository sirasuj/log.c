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
	printf("�������Ă�������...\n");
	while (1)
	{
		printf("CARD ON \r");
		//�J�[�h�Ɏ����ڑ�
		//�J�[�h�����������̂𖳌��ɑ҂�
		f.autoConnectToFelica(INFINITE);

		//�J�[�h��UID(IDm)���擾
		uint8_t uid[256] = { 0 };
		int len = f.readUID(uid);
		for (int i = 0; i < len; i++)
				printf("%d", uid[256]);
				printf("\n");
				Sleep(1000);
			if (len == ID1)
			{
				printf("�X�^�[�g�̏���");
			}
			if (len == ID2)
			{
				printf("�܂�Ԃ��n�_�̏���");
			}
			if (len == ID3)
			{
				printf("�S�[���̏���");
			}
			/*if (len )
			{
				printf("�����𖞂����Ă��Ȃ����̃S�[���̏���");
			}*/
				else {
					printf("CARD OFF\r");
				}
	}
}