#ifndef __LCD_CTRL_H__
#define __LCD_CTRL_H__
/*
	声明全局变量
		extern外部声明修饰词，表示被修饰的定义，是定义在其他文件中的
*/
extern int lcd_fd; //用来保存lcd屏的文件描述符
extern unsigned int *plcd; //用来保存映射屏幕的内存地址


/*
	lcd_init  初始化lcd屏函数:打开屏幕文件，并映射
		@void   不需要参数
	返回值：NONE
*/
extern void lcd_init(void);


/*
	lcd_uninit 用于解除LCD屏：解除映射，关闭屏幕文件
		@void  不需要参数
	返回值：NONE
*/
extern void lcd_uninit(void);

/*
	lcd_draw_point 用于在LCD屏上画点
		@x		像素点的横坐标
		@y		像素点的纵坐标 （x,y）
		@color  像素点的颜色值
	返回值：NONE
*/
extern void lcd_draw_point(int x,int y,unsigned int color);

/*
	lcd_draw_clear 用于将整个LCD屏，清空为指定颜色
			@color
	返回值：NONE
*/
extern void lcd_draw_clear(unsigned int color);


#endif