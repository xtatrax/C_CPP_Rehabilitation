
/***********************************************************
 * ■【C言語】Linuxでのkbhit関数（キーイベントの取得）
	https://hotnews8.net/programming/tricky-code/c-code03
	
■Unixにリアルタイムキー処理をプログラミングする。（C言語　kbhit） 
	http://i2blog.matrix.jp/index.php?UID=1479357418
************************************************************/
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <chrono>

# include <sys/ioctl.h>
# include <unistd.h>

static size_t line_length = 80;

/************************************************************
************************************************************/

/******************************
******************************/
int kbhit(void)
{
	struct termios oldt, newt;
	int ch;
	int oldf;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

	ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);

	if (ch != EOF) {
		ungetc(ch, stdin);
		return 1;
	}

	return 0;
}

/******************************
******************************/
int main(void)
{
	struct winsize ws;
    // get terminal size
    if( ioctl( STDOUT_FILENO, TIOCGWINSZ, &ws ) != -1 ) {
        printf("terminal_width  =%d\n", ws.ws_col);
        printf("terminal_height =%d\n", ws.ws_row);
        if( 0 < ws.ws_col && ws.ws_col == (size_t)ws.ws_col ) {
            line_length = ws.ws_col;
        } 
    }

	auto start = std::chrono::system_clock::now();

	char key=0;
	char status=0;
	while (1) {
		if(status==0){
			printf("please input any key > ");
			status++;
		}else if(status==1)
		{
			if (kbhit()) {
				printf("\n");
				printf("the key was : %c\n", key = getchar());
				if(key == 'q'){
					break;
				}
				status=0;
			}
		}
		auto now = std::chrono::system_clock::now();
		auto dur = now - start;        // 要した時間を計算
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		auto sec = std::chrono::duration_cast<std::chrono::seconds>(dur).count();
		auto min = std::chrono::duration_cast<std::chrono::minutes>(dur).count();
		char buf[64]="";
		sprintf(buf,"%d:%d.%d",min,sec,msec);
		int wsw = strlen(buf);
		printf("\e[%dG%s",ws.ws_col-wsw,buf);
		// sleep(1); // sec
		usleep(10 * 1000);
	}

	return 0;
}