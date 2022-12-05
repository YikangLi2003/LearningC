#include <stdio.h>
#define PAGES 336
#define WORDS 65618

int main(void)
{
    short num = PAGES;
    short mnum = -PAGES;

    printf("num as short and unsigned short: %hd %hu\n", num, num); // 336 336
    /* 不论有无符号 336都在表示数字本身的范围内 所以有无符号的解释方法 都可正常输出 */

    printf("-num as short and unsigned short: %hd %hu\n", mnum, mnum); // -336 65200
    /* 系统采用“二进制补码”表示有符号整数 [0, 32767]表示数字本身 [32768, 65535]表示负数
       65535表示-1 65534表示-2 以此类推 65200表示-336 
       因此以有符号形式可以正常解释为-336 无符号形式将-336的位组合解释为65200*/

    printf("num as int and char: %d %c\n", num, num); // 336 P
    /* 以int类型转换方式翻译short类型的值 可以得到正常输出
       short int 的宽度肯定比 char 的宽度大 
       如果当前系统 short int 宽度为2字节 而 char 宽度为1字节
       用char的转换说明时会只取 short int 的后八字节视作 ASCII 码值转换为 ASCII 字符
       336的二进制表示：0000000101010000
       336的二进制只取后八位： 01010000 = 80 = 'P' */

    /* 计算截断后的值的一种算法：
       1. 计算截断后的位组合宽度内能表示几种组合 
       2. 以能表示的不同组合的个数为除数
       3. 以原先未被截断的数为被除数
       4. 此除法运算的余数即截断后的值
       
       求将336的二进制位组合截断至1字节宽度后的值
       1字节内能表示256种不同的组合 则以256为除数 以336为被除数
       336 % 256 = 80 除法运算的余数为80
       由此可得截断后的值为80 */

    printf("WORDS as int, short, and char: %d %hd %c\n", WORDS, WORDS, WORDS); // 65618 82 R
    /* 在此系统中65618被存储为4字节 int 类型的值 使用%d转换说明可以获得正常输出
       而%hd对应长度为2字节的 short int 类型 此时编译器只取65618的二进制位组合的后8位
       65618：00000000000000010000000001010010 
       65618取后2字节: 0000000001010010 = 82
       65618取后1字节: 01010010 = 82 = 'R' */

    return 0;
}