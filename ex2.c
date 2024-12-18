#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//lower case entire string
void lower_str(char str[]){
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower(str[i]);
    }
    
}
//lower case entire lst - pool
void lower_lst(char pool[][11],int pool_size){
    for(int i =0 ; i<pool_size ; i++){
        lower_str(pool[i]);
    }

}


int is_permutations(char str[], char pool_str []){
    int matches = 0;
    int str_len = strlen(str);
    if (str_len == strlen(pool_str))
    {
        for (int i = 0; i < str_len-1; i++)
        {
         for (int j = 0; j < sizeof(pool_str)-1; j++)
          {
            if (str[i] == pool_str[j])
            {
                matches++;
                pool_str[j] = '\0';
                break;
            }
          }
        
        }
        if(matches == str_len) return 1;
    }
    return 0;   
}

int match_count(char str[], char pool[][11], int pool_size){
    int counter = 0;
    for(int curr_pool_str ; curr_pool_str<pool_size ;curr_pool_str++){
        if ( is_permutations(str , pool[curr_pool_str]) ) counter++;
    }
    return counter;
}

int main(){
    char str [11]; 
    char pool [20][11];

    // enter the your string
    printf("Enter the search string:\n");
    scanf("%10s", str);

    //replicate the str
    char str2print [11];
    memmove(str2print, str, sizeof(str));

    //enter your pool
    int eof;
    int pool_size = 0;
    printf("Enter the strings pool:\n");
    do
    {
        eof = scanf("%10s", pool[pool_size]);
        pool_size++;
    } while (pool_size < 20 && eof >= 0);

    //lower case all
    lower_str(str);
    lower_lst(pool, pool_size);

    //print result
    printf("Number of permutations of \"%s\" in the strings pool is: %d\n",str2print , match_count(str, pool, pool_size));

    return 0;
}