#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFSIZE 4096

int main (int argc, char *argv[])
{
	int n;
	char buf[BUFFSIZE];
	
	while((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
	{
		if(write(STDOUT_FILENO,buf,n) != n)
		{
			puts("write error");
			exit (0);
		}
	}
	
	if(n < 0)
	{
		puts("read error");
		exit (0);
	}
	return 0;
}
