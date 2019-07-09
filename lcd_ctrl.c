
/*
	引用头文件
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>

/*
	定义宏和全局变量
*/
int lcd_fd; //用来保存lcd屏的文件描述符
unsigned int *plcd = NULL; //用来保存映射屏幕的内存地址


/*
	lcd_init  初始化lcd屏函数:打开屏幕文件，并映射
		@void   不需要参数
	返回值：NONE
*/
void lcd_init(void)
{
	lcd_fd = open("/dev/fb0",O_RDWR);
	if(-1 == lcd_fd)
	{
		/*
			perror: 用来打印出错信息
					将出错的原因，打印在指定的字符串后面
		*/
		perror("open file error");
	}
	printf("open file success\n");

	plcd = mmap(NULL,1536000,PROT_READ | PROT_WRITE ,MAP_SHARED,lcd_fd,0);
}


/*
	lcd_uninit 用于解除LCD屏：解除映射，关闭屏幕文件
		@void  不需要参数
	返回值：NONE
*/
void lcd_uninit(void)
{
    lcd_fd = munmap(plcd,1536000);
    close(lcd_fd);
}

/*
	lcd_draw_point 用于在LCD屏上画点
		@x		像素点的横坐标
		@y		像素点的纵坐标 （x,y）
		@color  像素点的颜色值
	返回值：NONE
*/
void lcd_draw_point(int x,int y,unsigned int color)
{
	*(plcd+800*y+x) = color;
}

/*
	lcd_draw_clear 用于将整个LCD屏，清空为指定颜色
			@color
	返回值：NONE
*/
void lcd_draw_clear(unsigned int color)
{
	int x,y;
	for(y=0;y<480;y++)
	{
		for(x=0;x<800;x++)
		{
			lcd_draw_point(x,y,color);
		}
	}
}


