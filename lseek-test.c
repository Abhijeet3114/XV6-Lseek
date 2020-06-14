#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h> 
#include <sys/types.h> 

int main(int argc, char *argv[]) {

	int fd = open(argv[1], O_CREATE | O_RDWR);
	char* str;
	char buf[40];
	str = argv[2];
	printf("%s\n",str);
	lseek(fd, 0, SEEK_CUR);
	if(fd == -1){
		printf("Error\n");
	}
	else if(read(fd, buf, strlen(argv[2]))){
		if(strcmp(str,buf) == 0){
			printf("Matched\n");
		}
		else{
			printf("Unmatched\n");
		}
	}   
	close(fd);
	exit(0);
}
