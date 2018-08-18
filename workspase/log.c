#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <wiringPi.h>

#define TEST_OK  0     /* テスト関数戻り値 */
#define LOG_FILE     "LOG/buriLog.txt"        /* ログディレクトリ */
#define GPIO7 7

FILE *log_file;        /* 通常ログ */
//FILE *err_log_file;    /* 異常ログ */

/* 関数プロトタイプ宣言 */
void LOG_PRINT(char log_txt[256], ...);        /* 通常ログ出力関数  */

int main(void)
{
        int ret = TEST_OK;
        int flag;
        if(wiringPiSetupGpio() == -1) return 1;
                pinMode(digitalRead(GPIO7), INPUT);
                while(1){
                        if(digitalRead(GPIO7) == HIGH){
LOG_PRINT("NFCID012345/buri,RaspPiのID6789AB/テキトー
                                sleep(1);
                        }
                        else(digitalRead(GPIO7) == LOW)
                }
}

void LOG_PRINT(char log_txt[256], ...)
{
        time_t timer;
        struct tm *date;
        char str[256];

        /* 時間取得 */
        timer = time(NULL);
        date = localtime(&timer);

        strftime(str, sizeof(str), "%m/%d,%H:%M:%S," , date);
        if ((log_file = fopen(LOG_FILE, "a")) == NULL) {
                exit(EXIT_FAILURE);        /*
エラーの場合は通常、異常終了する $
        }

        /* 文字列結合 */
        strcat(str, log_txt);

        fputs(str, log_file);
        fclose(log_file);

        return;

}
