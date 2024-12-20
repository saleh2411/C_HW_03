#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//lower_case_string
void lower_str(char str[]){
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower(str[i]);
    }
    
}

//lower_case_pool
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

    for (int i = 0; i < 255; i++) {
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
    char str[11];
    char pool[20][11];
    int pool_size = 0;
    printf("Enter the search string:\n");
    if (fgets(str, sizeof(str), stdin) != NULL) {
        str[strcspn(str, "\n")] = '\0';
    }
    // replicate str
    char str2print[11];
    memmove(str2print, str, sizeof(str));
    str2print[10] = '\0'; //null-termination

    // pool
    printf("Enter the strings pool:\n");
while (pool_size < 20) {
    if (fgets(pool[pool_size], sizeof(pool[pool_size]), stdin) != NULL) {
        pool[pool_size][strcspn(pool[pool_size], "\n")] = '\0';
        pool_size++;
    } else if (feof(stdin)) {
        printf("\n");
        break;
    }
}
    //lower_case_all
    lower_str(str);
    lower_lst(pool, pool_size);
    //print
    printf("Number of permutations of \"%s\" in the strings pool is: %d\n",str2print , match_count(str, pool, pool_size));

    return 0;
}
