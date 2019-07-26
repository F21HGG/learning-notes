## gcc部分参数与选项
CFLAGS表示用于C编译器的选项，指定头文件（.h文件）的路径，比如：CFLAGS=-I/usr/include -I/path/include  

LDFLAGS表示gcc等编译器会用到的一些优化参数，也可以在里面指定库文件的位置。比如：LDFLAGS=-L/usr/lib -L/path/to/your/lib  

LIBS告诉链接器要链接哪些库文件，如LIBS=-lpthread -liconv

### gcc总体选项列表
|序号  |选项  |含义  |
|:--- |:--- |:--- |
|1  |-S  |只是编译不汇编，生成汇编代码  |
|2  |-E  |只进行预编译，不做其他处理  |
|3  |-g  |在可执行程序中包含标准调试信息  |
|4  |-o file  |把输出文件输入到file里  |
|5  |-v  |打印出编译器内部编译各过程的命令行信息和编译器的版本  |
|6  |-I dir  |在头文件的搜索路径列表中添加dir目录  |
|7  |-L dir  |在库文件的搜索路径列表中添加dir目录  |
|8  |-static  |链接静态库  |
|9  |-l library  |链接名为library的库文件  |
|10  |-c  |只编译源文件，但不链接  |

### makefile文件

**VPATH**:指定文件位置的关键字，设置全局访问路径  
比如：VPATH = src:../headers  
即指定了两个搜索目录，"src"和"../hearders"，当然当前目录仍然是默认值  
**vpath**:可为不同类型的文件(一般根据文件名区分)指定不同的搜索目录。比如：  
vpath %.c src  
vpath %.h include  
分别指定.c和.h文件的路径是src和include 

1. 第一种makefile文件（显示规则）
```
#目标文件:依赖文件
#	指令
#文件生成类似于递归关系，第一个文件为最终所得
#
#目录下包含了main.c add.c divide.c minus.c multiply.c这些源文件
#
#rm -rf test *.o
#伪目标  .PHONY

test:main.o add.o divide.o minus.o multiply.o
	gcc main.o add.o divide.o minus.o multiply.o -o test

main.o:main.c
	gcc -c main.c -o main.o

add.o:add.c
	gcc -c add.c -o add.o

divide.o:divide.c
	gcc -c divide.c -o divide.o

minus.o:minus.c
	gcc -c minus.c -o minus.o

multiply.o:multiply.c
	gcc -c multiply.c -o multiply.o

.PHONY:
clearall:
	rm -rf test *.o
clear:
	rm -rf *.o 
```

2. 第二种（变量）
```
#第二层： 变量 = (替换)  +=(追加)  :=(恒等于)
#使用变量 $(变量名)
TAR = test
OBJ = main.o add.o divide.o minus.o multiply.o
CC := gcc

$(TAR):$(OBJ)
	$(CC) $(OBJ) -o $(TAR)

main.o:main.c
	$(CC) -c main.c -o main.o

add.o:add.c
	$(CC) -c add.c -o add.o

divide.o:divide.c
	$(CC) -c divide.c -o divide.o

minus.o:minus.c
	$(CC) -c minus.c -o minus.o

multiply.o:multiply.c
	$(CC) -c multiply.c -o multiply.o

.PHONY:
clearall:
	rm -rf test *.o
clear:
	rm -rf *.o 
```

3. 第三种
```
#第三层：隐含规则   %.c  %.o  即任意的.c和任意的.o   *.c  *.o所有的.c .o
#	100个.c文件怎么办，使用通配符

TAR = test
OBJ = main.o add.o divide.o minus.o multiply.o
CC := gcc

$(TAR):$(OBJ)
	$(CC) $(OBJ) -o $(TAR)

#这里表示只要有任意 .c就生成对应.o文件
%.o:%.c
	$(CC) -c %.c -o %.o

.PHONY:
clearall:
	rm -rf test *.o
clear:
	rm -rf *.o 
```

4. 第四种
```
#第四层：通配符  $^所有的依赖文件  $@所有的目标文件   $<所有的依赖文件的第一个文件  
#	$%	仅当目标是函数库文件中，表示规则中的目标成员名
#例如，如果一个目标是“foo.a(bar.o)”，那么，“$%”就是“bar.o”，“$@”就是“foo.a”

TAR = test
OBJ = main.o add.o divide.o minus.o multiply.o
CC := gcc
RMRF := rm -rf

$(TAR):$(OBJ)
	$(CC) $^ -o $@

#这里表示只要有任意 .c就生成对应.o文件
%.o:%.c
	$(CC) -c $^ -o $@

.PHONY:
clearall:
	$(RMRF) $(OBJ) $(TAR)
clear:
	$(RMRF) $(OBJ)
```