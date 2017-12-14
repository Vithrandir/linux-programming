#include "fcntl.h"

int s;							//setting
s = fcntl(fd,F_GETFL);			//get flags
s |= O_APPEND;					//set APPEND bit
result = fcntl(fd,F_SETFL,s);	//set flags
if (result == -1)				//if error
{								
	perror("setting APPEND");	//report
}
else{
	write(fd,&rec,1);			//write record at end
}