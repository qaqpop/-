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
			perror: ������ӡ������Ϣ
					�������ԭ�򣬴�ӡ��ָ�����ַ�������
		*/
		perror("open file error");
		return -1;
	}
	printf("open file success\n");

	
	/*д������*/
	unsigned int color_nei = 0x00ffffff;
	unsigned int color_wai = 0x00000000;
	int x,y;
	int a=400,b=240,r=200;//(400,240)�뾶200��Բ
	for(y=0;y<480;y++)      //�ܹ�480��
	{
		for(x=0;x<800;x++) //һ����800�����ص�
		{
			if((x-a)*(x-a)+(y-b)*(y-b)<=r*r)//Բ
			{
				write(fd,&color_nei,4); //д����һ����ɫ
			}
			else
			{
				write(fd,&color_wai,4);
			}
		}
		//usleep(10000); //��ʱ 10000us == 10ms
	}
	return 0;


	close(fd);
}
