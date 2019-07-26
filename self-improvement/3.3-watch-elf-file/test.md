### 挖掘 SimpleSection.o
1. 编写程序代码SimpleSection.c
2. 使用gcc来进行编译  
编译语句为：gcc -c SimpleSection.c
3. 查看SimpleSection.o的文件内容，发现有7段信息  

它们分别是代码段.text、数据段.data、BSS段.bss、只读数据段.rodata、注释信息段.comment、堆栈提示段.note.GNU-stack。

Size是段长度，File Offset是段所在位置