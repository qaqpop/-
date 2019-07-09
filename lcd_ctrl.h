#ifndef __LCD_CTRL_H__
#define __LCD_CTRL_H__
/*
	����ȫ�ֱ���
		extern�ⲿ�������δʣ���ʾ�����εĶ��壬�Ƕ����������ļ��е�
*/
extern int lcd_fd; //��������lcd�����ļ�������
extern unsigned int *plcd; //��������ӳ����Ļ���ڴ��ַ


/*
	lcd_init  ��ʼ��lcd������:����Ļ�ļ�����ӳ��
		@void   ����Ҫ����
	����ֵ��NONE
*/
extern void lcd_init(void);


/*
	lcd_uninit ���ڽ��LCD�������ӳ�䣬�ر���Ļ�ļ�
		@void  ����Ҫ����
	����ֵ��NONE
*/
extern void lcd_uninit(void);

/*
	lcd_draw_point ������LCD���ϻ���
		@x		���ص�ĺ�����
		@y		���ص�������� ��x,y��
		@color  ���ص����ɫֵ
	����ֵ��NONE
*/
extern void lcd_draw_point(int x,int y,unsigned int color);

/*
	lcd_draw_clear ���ڽ�����LCD�������Ϊָ����ɫ
			@color
	����ֵ��NONE
*/
extern void lcd_draw_clear(unsigned int color);


#endif