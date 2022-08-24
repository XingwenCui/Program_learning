// typing1b.c
/* 一个字符串的键盘打字练习（其二：消去已输入的字符）*/

#include <time.h>
#include <stdio.h>
#include <string.h>
#include "getputch.h"

int main(void)
{
    int     i;
    char    *str = "How do you do?";    /* 要输入的字符串,pointer指向str，用指针是因为好访问值 */
    int     len = strlen(str);          /* 字符串str的字符数量 */
    clock_t start, end;                 /* 开始时间和结束时间 */
    init_getputch();
    printf("请照着输入。\n");
    start = clock();                    /* 开始时间 */
    for (i = 0; i < len; i++) {
        /* 显示str[i]以后的字符并把光标返回到开头 */
        printf("%s \r", &str[i]); //这里&str[i]是取第i个开头的string，因为地址是从第一个开始
        fflush(stdout);
        while (getch() != str[i])
            ;
    }
    end = clock();                      /* 结束时间 */
    printf("\r用时%.1f秒。\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("Quit by type whiteblock");
    while (getch() != ' ')
        ;
    term_getputch();
    return 0;
}