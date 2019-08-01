## ManualNameMangling.cpp
```
#include <stdio.h>

namespace myname{
    int var = 42;
}

// extern "C" int _ZN6myname3varE;

int main(){
    printf("%d\n", _ZN6myname3varE);
    return 0;
}
```  

需要把其中`extern "C" int _ZN6myname3varE;`一句给注释掉，不然编译报错。
编译语句：
```
g++ ManualNameMangling.cpp -o ManualNameMangling  
./ManualNameMangling
```