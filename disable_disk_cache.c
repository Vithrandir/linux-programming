#include "fcntl.h"

int s;							//setting
s = fcntl(fd,F_GETFL);			//get flags
s |= 0_SYNC;					//set SYNC bit
result = fcntl(fd,F_SETFL,s);	//set flags
if(result == 1){				//if error
	perror("setting SYNC");		//report
}