#include "stdio.h"
#include "termios.h"

#define QUESTION "Do you want another transaction"

int get_reponse(char *);

int main(int argc, char const *argv[])
{
	int response;
	response = get_response(QUESTION);
	return response;
}

int get_response(char * question){
	printf("%s (Y/N)?\n",question);
	while(1){
		switch(getchar()){
			case 'y':
			case 'Y':return 0;
			case 'n':
			case 'N':
			case EOF:return 1;
		}
	}
}