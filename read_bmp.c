#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "lcd_ctrl.h"
int find_pix_start(char *bmp_file)
{
    unsigned char eh[4]={0};
    int bmp_fd = open(bmp_file,O_RDWR);
	int pix_start=eh[3]<<24|eh[2]<<16|eh[1]<<8|eh[0];
	lseek(bmp_fd,0x0a,SEEK_SET);
    read(bmp_fd,pix_start,4);
    return pix_start;
}
int find_width(char *bmp_file)
{   
	unsigned char ch[4]={0};
    int bmp_fd = open(bmp_file,O_RDWR);
	int width=ch[3]<<24|ch[2]<<16|ch[1]<<8|ch[0];
	lseek(bmp_fd,0x12,SEEK_SET);
	read(bmp_fd,width,4);
    return width;
}
int find_hight(char *bmp_file)
{
     unsigned char ah[4]={0};
	 int bmp_fd = open(bmp_file,O_RDWR);
	 int hight=ah[3]<<24|ah[2]<<16|ah[1]<<8|ah[0];
     lseek(bmp_fd,0x16,SEEK_SET);
	 read(bmp_fd,hight,4);
     return hight;
}	
int find_pix_bits(char *bmp_file)
{
    unsigned char bh[4]={0};
    int bmp_fd = open(bmp_file,O_RDWR);
	int pix_bits=bh[1]<<8|bh[0];
    lseek(bmp_fd,0x1c,SEEK_SET);
	read(bmp_fd,pix_bits,2);
	return pix_bits;
}
int show_bmp(int x0,int y0,char *bmp_file)
{
    unsigned char pix_array[800*480*4] = {0};
	int bmp_fd = open(bmp_file,O_RDWR);
	if(-1 == bmp_fd)
	{
		perror("open bmp error");
		return -1;
	}
	find_pix_start(*bmp_file);
	int width=find_width(*bmp_file);
	int hight=find_hight(*bmp_file);
	int pix_bits=find_pix_bits(*bmp_file);
    if(x0+width<800&&y0+hight<480)
	{
	 unsigned char a,r,g,b;
	 unsigned int color;
	 int i=0;
	 int x,y;
	 for(y=x0;y<hight;y++)
	 {
		 for(x=y0;x<width;x++)
		 { 
			 b = pix_array[i++];
			 g = pix_array[i++];
			 r = pix_array[i++];
			 a = pix_bits==32?pix_array[i++]:0;
			 color = a<<24 | r<<16 | g<<8 | b;
			 lcd_draw_point(x,hight<0?y:(hight-1-y),color);
		 }
	 }
	}
	else
	{
	printf("you are bitch");
	}
	    close(bmp_fd);
        return 0;
}
