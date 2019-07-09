#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

void f_open();
void f_write();



void f_open()
{
	int fd = open("/dev/fb0",O_RDWR);	
	if(-1 == fd)
	{
		perror("error");			
	}
	else
	{
		printf("success...");
	}
	

}

void f_write()
{
	int fd = open("/dev/fb0",O_RDWR);
	unsigned int color1 = 0x00000000;
	unsigned int color2 = 0x00ffffff;
	int x,y;
	for(x=0;x<480;x++){
		for(y=0;y<800;y++){
			if((x-a)*(x-a)+(x-b)(x-b)<=r*r&&)
			else
			{
				write(fd,&color1,4);
			}
		}
	}



}

int main()
{
	int fd = open("/dev/fb0",O_RDWR);
	f_open();
	f_write();

	return 0;

	close(fd);

}

