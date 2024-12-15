#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int match_count( char str[], char pool[][11]){
    int counter = 0;
    return counter;
}

int main(){
    char str [11]; 
    char pool [20][11];
    
    

    // enter the your string
    printf("Enter the search string:\n");
    scanf("%10s", str);

    //enter your pool
    int eof;
    int pool_size = 0;
    do
    {
        eof = scanf("%10s", pool[pool_size]);
        pool_size++;
    } while (pool_size < 20 && eof >= 0);

    printf("Number of permutations of "%s" in the strings pool is: %d",str , match_count(str, pool));

    return 0;
}