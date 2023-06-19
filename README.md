# c_samples

c samples

# struct

# C预处理器

- `#define`：明示常量（符号常量），每行`#define`由3部分组成：
  - 第一部分是`#define`本身
  - 第二部分是宏
  - 第三部分是替换列表（替换体）
  - `define`中使用参数：类函数宏`#define SQUARE(X) X*X`
    - 变参宏：`...`和`__VA_ARGS__`
- `#include`：文件包含
  - `#include <stdio.h>`：尖括号告诉预编译处理器在标准系统目录中查找该文件
  - `#include "some.h"`：双引号告诉预编译处理器首先在当前目录中查找该文件，如果找不到再查找系统标准目录
- `#undef`：取消已经定义的`#define`指令
- `#ifdef`、`#else`、`#endif`：条件编译，使用这些指令告诉编译器根据编译时的条件执行或者忽略信息
- `#ifndef`：判断后面的标识符是否是未定义的
- `#if`、`#elif`
- `#line`：重置`__LINE__`和`__FILE__`宏报告的行号和文件名
- `#error`：让预处理器发出一条错误消息，该消息包含指令中的文本
- `#pragma`：把编译器指令放入源码中