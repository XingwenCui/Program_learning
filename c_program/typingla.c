/*A type exercise platform，只能输入 */

#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "getputch.h"
 
int main(void)
{
    int i;
    char *str = "How do you do?"; //which string will type
    int len = strlen(str); //len of string
    clock_t start,end; // store the time. clock_t in time.h and return a long int
 
    init_getputch(); //A function in getputch.h
    printf("Please type this");
    printf("%s",str); //Output the typed sentence
 
    fflush(stdout); //clear cache to output
    start = clock(); //save a start time
    for (i=0; i<len; i++){
        int ch; 
        do{ 
            ch = getch(); //read one char
            if(isprint(ch))
            {   
                putch(ch); //output char
                if (ch != str[i])
                    putch(''); //if type wrong char, backtrack one char
            }
        }while(ch != str[i]); //when all char are type that means the input over
    }   
    end =clock();
    printf("You cost %.1f s", (double)(end-start)/CLOCKS_PER_SEC);
    term_getputch();
    return 0;

    
}