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
