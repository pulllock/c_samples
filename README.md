# c_samples

c samples

# 指定初始化器（Designated Initializer）

- [指定初始化数组元素](./designated_initializer_array/main.c)
- [指定初始化结构体成员](./designated_initializer_struct/main.c)

# 语句表达式（Statement Expression）

- [语句表达式](./statement_expression/main.c)：允许在一个表达式里内嵌语句，格式如下：`({表达式1; 表达式2; 表达式3})`，语句表达式的值为内嵌语句中最后一个表达式的值
- [在宏定义中使用语句表达式](./statement_expression_macro/main.c)

# 获取变量或表达式的类型（typeof）

- [获取变量或表达式的类型](./typeof/main.c)

# 变长数组（Variable Length）和零长度数组（Length Zero）

- [变长数组](./variable_length_array/main.c)
- [零长度数组](./length_zero_array/main.c)

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

# 存储类别

可用存储期来描述对象，存储期是指对象在内存中保留了多长时间。

## 作用域

作用域描述程序中可访问标识符的区域，C变量的作用域可以是：

- 块作用域
- 函数作用域：仅用于goto语句的标签
- 函数原型作用域：用于函数原型中的形参名
- 文件作用域

## 链接

C变量有三种链接属性：

- 外部链接：具有文件作用域的变量可以是内部链接或外部链接，外部链接变量可以在多个文件程序中使用
- 内部链接：具有文件作用域的变量可以是内部链接或外部链接，内部链接变量只能在一个翻译单元中使用，static声明的文件作用域变量具有内部链接
- 无链接：具有块作用域、函数作用域、函数原型作用域的变量都是无链接变量，这意味着变量属于定义它们的块、函数或原型私有

## 存储期

C对象有4种存储期：

- 静态存储期：对象在程序执行期间一直存在，文件作用域变量具有静态存储期；块作用域变量也能具有静态存储期，变量声明在块中并且加上static关键字
- 线程存储期：用于并发程序设计，程序执行可被分为多个线程。具有线程存储期的对象，从被声明到线程结束一直存在
- 自动存储期：块作用域的变量通常都具有自动存储期；变长数组的存储期从声明处到块的末尾。
- 动态分配存储期

## 存储类别

存储类别有5种：

| 存储类别   | 存储期 | 作用域 | 链接  | 声明方式              |
| ------ | --- | --- | --- | ----------------- |
| 自动     | 自动  | 块   | 无   | 块内                |
| 寄存器    | 自动  | 块   | 无   | 块内，使用关键字register  |
| 静态外部链接 | 静态  | 文件  | 外部  | 所有函数外             |
| 静态内部链接 | 静态  | 文件  | 内部  | 所有函数外，使用关键字static |
| 静态无链接  | 静态  | 块   | 无   | 块内，使用关键字static    |

## 自动变量

属于自动存储类别的变量具有自动存储期、块作用域、无链接。默认情况下声明在块或函数头中的变量都属于自动存储类别。

`auto`关键字是存储类别说明符，显式的说明是一个自动变量

## 寄存器变量

寄存器变量和自动变量一样，都是块作用域、无链接、自动存储期。

`register`可声明寄存器变量

## 块作用域的静态变量

静态变量的意思是该变量在内存中原地不动，并不是说它的值不变。

块作用域的局部变量使用`static`来声明

## 外部链接的静态变量

外部链接的静态变量具有文件作用域、外部链接、静态存储期。把变量的定义声明放在所有函数外面就创建了外部变量，为了在函数中指出使用了外部变量，可在函数中用关键字`extern`来声明；如果一个源码文件使用的外部变量定义在另一个源码文件中，则必须使用`extern`关键字在该文件中声明该变量。

## 内部链接的静态变量

内部链接的静态变量具有静态存储期、文件作用域和内部链接，在所有函数外部使用`static`来声明

## 存储类别和函数

函数也有存储类别：

- 外部函数（默认）：可以被其他文件的函数访问
- 静态函数：只能用于定义函数的文件
- 内联函数

# 分配内存

- `malloc()`：该函数接受一个参数：所需的内存字节数
- `free()`：该函数的参数是`malloc()`函数返回的地址，用于释放`malloc()`分配的内存
- `calloc()`：该函数也可以分配内存，会把块中所有位都设置为0