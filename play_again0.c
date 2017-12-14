#include "stdio.h"
#include "termios.h"
#include "fcntl.h"
#include "string.h"

#define QUESTION "Do you want another transaction"
#define TRIES 3
#define SLEEPTIME 2
#define BEEP putchar('\a')

int get_reponse(char *);

int main(int argc, char const *argv[])
{
	int response;
	tty_mode(0);
	set_cr_noecho_mode();
	set_nodelay_mode();
	response = get_response(QUESTION);
	tty_mode(1);
	return response;
}

int get_response(char * question){
	printf("%s (Y/N)?\n",question);
	fflush(stdout);
	while(1){
		sleep(SLEEPTIME);
		input = tolower(get_ok_char());
		switch(input){
			case 'y':return 0;
			case 'Y':
			case 'n':return 1;
			case 'N':
		}
		if (maxtries-- == 0 )
		{
			return 2;
		}
		BEEP;
	}
}

get_ok_char(){
	int c;
	while((c = getchar()) != EOF && strchr("yYnN",c) == NULL){
		;
	}
	return c;
}
set_cr_noecho_mode(){
	struct termios ttystate;
	tcgetattr(0,&ttystate);
	ttystate.c_lflag &= ~ICANON;
	ttystate.c_lflag &= ~ECHO;
	ttystate.c_cc[VMIN] = 1;
	tcsetattr(0,TCSANOW,&ttystate);
}
set_nodelay_mode(){
	int termflags;
	termflags = fcntl(0,F_GETFL);
	termflags |= O_NDELAY;
	fcntl(0,F_SETFL,termflags);
}
set_crmode(){
	struct termios ttystate;
	tcgetattr(0,&ttystate);
	ttystate.c_lflag &= ~ICANON;
	ttystate.c_cc[VMIN] = 1;
	tcsetattr(0,TCSANOW,&ttystate);
}

tty_mode(int how){
	static struct termios original_mode;
	if(how == 0){
		tcgetattr(0,&original_mode);
	}
	else{
		return tcsetattr(0,TCSANOW,&original_mode);
	}
}