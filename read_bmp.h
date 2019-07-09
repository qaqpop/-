#ifndef __READ_BMP_H__
#define __READ_BMP_H__

/*
	read_bmp 用来解析bmp文件
		@file  bmp文件名
	返回值：
		0  表示解析成功
		-1 表示解析失败
*/
int read_bmp(char *file);

#endif