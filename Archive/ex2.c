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


int is_permutations(char str[], char pool_str[]) {
    int str_freq[256] = {0}, pool_freq[256] = {0};
    int str_len = strlen(str);
    int pool_len = strlen(pool_str);

    if (str_len != pool_len) return 0;

    for (int i = 0; i < str_len; i++) {
        str_freq[str[i]]++;
        pool_freq[pool_str[i]]++;
    }

    for (int i = 0; i < 256; i++) {
        if (str_freq[i] != pool_freq[i]) return 0;
    }

    return 1;
}

int match_count(char str[], char pool[][11], int pool_size){
    int counter = 0;
    for(int curr_pool_str = 0; curr_pool_str<pool_size ;curr_pool_str++){
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
    
    // {
    //     eof = scanf("%10s", pool[pool_size]);
    //     pool_size++;
    // } while (pool_size < 20 && eof >= 0);

    while (pool_size < 20) {
        // Read a line up to 10 characters (including spaces)
        if (scanf("%10[^\n]%*c", pool[pool_size]) == 1) {
            // If a non-empty line is read, process it
            // printf("Line %d: %s\n", line_count + 1, buffer);
            pool_size++;
        } else {
            // Handle empty lines explicitly
            int ch = getchar(); // Consume the newline character
            if (ch == '\n') {
                // printf("Line %d: [Empty Line]\n", line_count + 1);
                pool_size++;
            } else if (ch == EOF) {
                break; // Exit loop on EOF
            }
        }
    }

    //lower case all
    lower_str(str);
    lower_lst(pool, pool_size);

    //print result
    printf("Number of permutations of \"%s\" in the strings pool is: %d\n",str2print , match_count(str, pool, pool_size));

    return 0;
}