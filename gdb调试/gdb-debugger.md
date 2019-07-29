# GDB调试的基本使用
gdb调试：启动程序准备调试`GDB yourprogram`or`GDB`+`file yourprogram`  
然后使用`run`或者`r`命令开始程序的执行。  

## 参数列表
|序号  |指令  |来源  |含义  |
|:---|:---|:---|:---|
|1  |l  |list  |显示多行源代码  |
|2  |b  |break  |设置断点  |
|3 |i  |information  |描述程序的状态  |
|4  |r  |run  |开始运行程序  |
|5  |disp  |dispay  |跟踪查看某个变量  |
| 6 |s  |step  |执行下一步，会进入函数内部  |
| 7 |n  |next  |执行下一条，不会进入函数内部  |
|8  |p  |print  |打印内部变量值  |
| 9 |c  |continue  |继续程序的运行  |
|10  |set  |set var=v |设置变量的值  |
| 11 |st  |start  |开始执行程序  |
|12  |file  |  |装入需要调试的程序  |
|13  |k  |kill  |终止正在调试的程序  |
| 14 |watch  |  |监测变量值的变化  |
| 15 |bt  |backtrace  |查看函数调用信息  |
| 16 |f  |frame  |查看栈帧  |
| 17 |q  |quit  |退出GDB环境  |

参考的csdn博客：[gdb调试的基本使用](https://blog.csdn.net/zdy0_2004/article/details/80102076)