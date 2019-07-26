# Linux指令学习
## linux基础知识
指令常规格式：指令 选项 路径  
指令ls显示的颜色：<label style="color:blue">蓝色</label>：文件夹，<label style="color:black">黑色</label>：文件，<label style="color:green">绿色</label>：权限为所有  
重定向：  >:覆盖输出  >>:追加输出  
***********
## Linux基础指令
|序号|指令   |  来源   |  含义  |  选项  |举例|
|:---|:----  |:----   |:-----  |:-----|:----|
|1  |man   |manual   |指令帮助   |    |`man ls`   |
|2  |ls     |   list    |  列出文件|-a(全部文件，含隐藏)<br>-l(详细信息)<br>-lh(列表形式)|`ls -la f21h`|
|3  |pwd      |print woking directory|打印当前目录        |             | `pwd` |
|4  |cd   |change directory| 切换当前路径||`cd /usr/local`|
|5  |mkdir|make directory|创建文件夹|-p(多层创建) |`mkdir -p learnLinux/a/b/c/d` |
|6  |touch | touch|创建文件|  创建多个文件    | ` touch linux.txt`  |
|7  | cp  |copy    |复制文件或文件夹到某路径  | -r(递归)    |`cp linux.txt ./a/linux.txt`  |
|8  |  mv    |  move    | 移动文件的位置  |  可以用于重命名   | `mv linux.txt ../linux.txt`      |
|9  |rm    |remove     |删除文件   | -r(递归删除)<br> -f(无需确认)    | `rm -rf aa`  |
|10  |cat  | catenate |查看文件  合并文件|      |  `cat linux.txt linux1.txt linux2.txt linux3.txt >result.txt`      |
|11  |> >>  |       |标准输出   |>覆盖重定向<br>>>追加重定向 |`ls >test.txt`<br>`ls >>test.txt` |
|12  |2> 2>>  |       |标准错误输出   |>覆盖重定向<br>>>追加重定向 |        |
## Linux进阶指令
|序号 |指令   |  来源   |  含义  |  选项  |举例|
|:--- |:----  |:----   |:-----  |:-----|:----|
|1  |df    |disk free  |查看硬盘空间 |-h(human-readable)<br>带单位     |`df -h` |
|2  |free  |    |查看内存情况 |-m(以mb为单位)<br>-g(以gb为单位)<br>-h     |`free -h`    |
|3  |head |    |查看文件前部  |-n(前n行)     |`head -5`  |
|4  |tail    |    |查看文件尾部    |-n(后n行)     |`tail -7`  |
|5  |less  |     |简洁查看文件     |     |`less main.cpp`     |
|6  |wc  |word count  |统计文件  |-l(lines)<br>-w(words)<br> -c(bytes)  |`wc -l main.cpp`  |
|7  |clear   |    |清屏    |    |`clear`  |
|8  |grep|general regular<br>expression print |过滤   |  |`ls |grep a`<br>`ls /|grep o`|
## Linux高级指令
|序号  |指令   |  来源   |  含义  |  选项  |举例|
|:---|:----  |:----   |:-----  |:-----|:----|
|1  |hostname |    |输出主机名  |-f(权限定域名) |`hostname -f`|
|2  |id |    |查看用户信息  |     |`id 1000`  |
|3  |whoami  |    |显示当前登录用户名|     |`whoami`  |
|4  |ps -ef |processes status |查看进程信息  |-e(全部进程)<br>-f(全部列) |`ps -ef`  |
|5  |top  |  |查看服务器进程占用资源 |q(退出)  |`top`  |
|6  |du  |disk usage  |查看目录真实大小  |-s(summaries)<br>-h(human-readable) |`du -sh /root` |
|7  |find |  |查找文件  |-name<br>-type |`find /home -name main`  |
|8  |service  |  |控制软件的服务  |  |`service httpd star`  |
|9  |kill<br>killall |  |杀死进程  |  |`kill 30924`<br>`killall firefox`|
********
## 文本操作
|序号  |指令   |  来源   |  含义  |  选项  |举例|
|:--- |:----  |:----   |:-----  |:-----|:----|
|1  |grep  |general regular<br>expression print|全局正则表达式匹配 |-c(count)<br>-w(word)<br>-n(number)<br>-i(忽略大小写)<br>-f(关键词搜索)<br>-v(反选)  |`grep -nf PAL.txt *`  |
|2  |sort  |  |排序  |-n(数字排序)<br>-r(反序)<br>-k(关键字)  |`sort -r num.txt`  |
|3  |sed  |  |处理文本文件  |-e(指定语句处理)<br>-f(指定文件处理)<br>-n(仅显示处理结果)  |`sed -e 4a\newLine testfile`   |
|4  |awk  |Aho Welnberger Kemlghan  |一个行文本处理工具 |-F(指定分隔符)<br>-f(文件读取awk)<br>-W help(打印帮助)  |`awk -F '[ ,]'  '{print $1,$2,$5}'   log.txt`  |
************
## 正则表达式
正则表达式(regular expression)描述了一种字符串匹配的模式（pattern），可以用来检查一个串是否含有某种子串、将匹配的子串替换或者从某个串中取出符合某个条件的子串等。 
### 非打印字符 
|序号 |字符  |描述  |序号  |字符  |描述  |
|:--- |:--- |:---  |:---  |:---|:---|
|1 |`\cx`  |由x指明的控制字符 |2  |`\f`  |换页符  |
|3  |`\n`  |换行符 |4   |`\r`  |回车符  |
|5  |`\s`  |任何空白字符  |6  |`\S`  |任何非空白字符  |
|7  |`\t`  |一个制表符  |8  |`\v`  |一个垂直制表符  |
### 特殊字符 
|序号  |字符  |描述 |序号 |字符  |描述  |
|:--- |:--- |:---  |:---  |:---|:---|
|1  |`$` |字符串的结尾，要匹配$本身，使用`\$`  |2  |`()`  |标记子表达式的开始结束，要匹配()本身，使用`\(`和`\)`，下同  |
|3  |`*`  |前面的子表达式零次或多次  |4  |`+`  |前面子表达式一次或多次  |
|5  |`.`  |除了\n之外的任何单字符  |6  |`[`  |标记中括号表达式的开始  |
|7  |`?`  |前面子表达式零次或一次，或指明一个非贪婪限定符  |8  |`\`  |转义字符  |
|9  |`^`  |字符串的开始位置，除非在方括号表达式中  |10  |`{`  |标记限定符表达式的开始  |
|11  |`|`  |指明两项之间的一个选择  |  |  |  |
### 限定字符 
|序号 |字符  |描述  |序号 |字符  |描述  |
|:--- |:--- |:---  |:---  |:---|:---|
|1  |`*`  |匹配前面的子表达式零次或多次。例如，zo* 能匹配 "z" 以及 "zoo"。* 等价于{0,}  |2  |`+`  |匹配前面的子表达式一次或多次。例如，'zo+' 能匹配 "zo" 以及 "zoo"，但不能匹配 "z"。+ 等价于 {1,}  |
|3  |`?`  |匹配前面的子表达式零次或一次。例如，"do(es)?" 可以匹配 "do" 、 "does" 中的 "does" 、 "doxy" 中的 "do" 。? 等价于 {0,1}  |4  |`{n}`  |n 是一个非负整数。匹配确定的 n 次。例如，'o{2}' 不能匹配 "Bob" 中的 'o'，但是能匹配 "food" 中的两个 o  |
|5  |`{n,}`  |n 是一个非负整数。至少匹配n 次。例如，'o{2,}' 不能匹配 "Bob" 中的 'o'，但能匹配 "foooood" 中的所有 o。'o{1,}' 等价于 'o+'。'o{0,}' 则等价于 'o*'  |6  |`{n,m}`  |m 和 n 均为非负整数，其中n <= m。最少匹配 n 次且最多匹配 m 次。例如，"o{1,3}" 将匹配 "fooooood" 中的前三个 o。'o{0,1}' 等价于 'o?'。请注意在逗号和两个数之间不能有空格。  |
### 定位符
|序号  |字符  |描述  |序号  |字符  |描述  |
|:--- |:--- |:--- |:--- |:--- |:--- |
|1  |`^`  |匹配输入字符串开始的位置。如果设置了 RegExp 对象的 Multiline 属性，^ 还会与 \n 或 \r 之后的位置匹配  |2  |`$`  |匹配输入字符串结尾的位置。如果设置了 RegExp 对象的 Multiline 属性，$ 还会与 \n 或 \r 之前的位置匹配  |
|3  |`\b`  |匹配一个单词边界，即字与空格间的位置  |4  |`\B`  |非单词边界匹配  |
****************
## 参考资料：  
[Linux从入门到精通](https://www.bilibili.com/video/av23360560?from=search&seid=4402409279384273262)  
[Linux常用命令全拼](https://www.runoob.com/w3cnote/linux-command-full-fight.html)  
[Linux命令大全](http://man.linuxde.net/)
[正则表达式-菜鸟教程](https://www.runoob.com/regexp/regexp-tutorial.html)

