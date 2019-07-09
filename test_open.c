#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>


int main(void)
{
	int fd = open("/dev/fb0",O_RDWR);
	if(-1 == fd)
	{
		/*
			perror: 用来打印出错信息
					将出错的原因，打印在指定的字符串后面
		*/
		perror("open file error");
		return -1;
	}
	printf("open file success\n");

	
	/*写入数据*/
	unsigned int color_nei = 0x00ffffff;
	unsigned int color_wai = 0x00000000;
	int x,y;
	int a=400,b=240,r=200;//(400,240)半径200的圆
	for(y=0;y<480;y++)      //总共480行
	{
		for(x=0;x<800;x++) //一行有800个像素点
		{
			if((x-a)*(x-a)+(y-b)*(y-b)<=r*r)//圆
			{
				write(fd,&color_nei,4); //写入了一个绿色
			}
			else
			{
				write(fd,&color_wai,4);
			}
		}
		//usleep(10000); //延时 10000us == 10ms
	}
	return 0;


	close(fd);
}
