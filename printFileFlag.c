#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int
main(int argc, char * argv[])
{
	int val;
	if(argc!=2){
		printf("incorrect arguments number!\n");
		return -1;
	}
	if((val=fcntl(atoi(argv[1]),F_GETFL,0))<0){
		printf("cannot get file flag!\n");
		return -1;
	}
	switch(val & O_ACCMODE) /* TO TEST THE ACCESS MODE OF THE FILE*/
	{
		case O_RDONLY:
			printf("FILE FLAG: Read Only ~~");
			break;
		case O_WRONLY:
			printf("FILE FLAG: Write Only ~~");
			break;
		case O_RDWR:
			printf("FILE FLAG: Read & Write ~~");
			break;
		default:
			printf("error: unknown file access flag!");
	}

	if(val & O_APPEND) printf(", append");
	if(val & O_NONBLOCK) printf(", nonblocking");
	if(val & O_SYNC) printf(", synchronous writes");

	putchar('\n');
	exit(0); /* declaration in stdlib.h */
}
