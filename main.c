#include "lcd_ctrl.h"

int main(void)
{
	int color;
	printf("please input the color:\n");
	scanf("%x",&color);

	lcd_init();

	lcd_draw_clear(color);

	lcd_uninit();
}

