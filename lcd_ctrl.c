
/*
	����ͷ�ļ�
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>

/*
	������ȫ�ֱ���
*/
int lcd_fd; //��������lcd�����ļ�������
unsigned int *plcd = NULL; //��������ӳ����Ļ���ڴ��ַ


/*
	lcd_init  ��ʼ��lcd������:����Ļ�ļ�����ӳ��
		@void   ����Ҫ����
	����ֵ��NONE
*/
void lcd_init(void)
{
	lcd_fd = open("/dev/fb0",O_RDWR);
	if(-1 == lcd_fd)
	{
		/*
			perror: ������ӡ������Ϣ
					�������ԭ�򣬴�ӡ��ָ�����ַ�������
		*/
		perror("open file error");
	}
	printf("open file success\n");

	plcd = mmap(NULL,1536000,PROT_READ | PROT_WRITE ,MAP_SHARED,lcd_fd,0);
}


/*
	lcd_uninit ���ڽ��LCD�������ӳ�䣬�ر���Ļ�ļ�
		@void  ����Ҫ����
	����ֵ��NONE
*/
void lcd_uninit(void)
{
    lcd_fd = munmap(plcd,1536000);
    close(lcd_fd);
}

/*
	lcd_draw_point ������LCD���ϻ���
		@x		���ص�ĺ�����
		@y		���ص�������� ��x,y��
		@color  ���ص����ɫֵ
	����ֵ��NONE
*/
void lcd_draw_point(int x,int y,unsigned int color)
{
	*(plcd+800*y+x) = color;
}

/*
	lcd_draw_clear ���ڽ�����LCD�������Ϊָ����ɫ
			@color
	����ֵ��NONE
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


