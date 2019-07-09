# -
基于gec6818开发板   ubantu    CRT

1.项目开发环境：
	搭建好交叉开发环境的Ubuntu系统
	交叉编译命令：arm-linux-gcc
	代码调试、运行平台：GEC6818开发板，采用ARM公司Cortex-A53为处理器芯片
						处理器架构源于三星公司S5P6818

2.项目的编译及运行过程：
	1）进入	Project/src/

	2) 使用下列命令，编译文件
		arm-linux-gcc  lcd_ctrl.c main.c read_bmp.c -o target  -I../inc  -L../lib

		其中：
			-I../inc :指定头文件的搜索路径，告知编译器去哪找自己编写的.h文件
						../inc表示 上级目录下的inc目录
			-L../lib :指定第三方库文件的搜索路径，一般需要与 -llibname连用
						-llibname指定第三方库的名称

			target   ：编译后生成的程序文件名

	3）下载
			rx  target  
	4）运行
			chmod 0777 target
			./target

