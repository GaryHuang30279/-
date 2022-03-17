#include <stdio.h>
#include <string.h>
#define MAX 100000
#define TOUPPER(c) ('a'<=(c) && (c)<='z' ? (c)- 'a' +'A':(c))
#define TOLOWER(c) ('A'<=(c) && (c)<='Z' ? (c)- 'A' +'a':(c))

int main(){
    char input[MAX];
    char output[MAX];
    int mode = 0;
    int i = 0;

    fgets(input, MAX, stdin);  
    input[strlen(input)] = 0;

    scanf("%d", &mode);
    
    if(mode == 1){
        for(i=0;i<strlen(input);i++){
            // if(input[i]>='a' && input[i] <='z'){
            //     output[i] = input[i];
            // }
            // else if(input[i]>='A' && input[i] <= 'Z'){
            //     output[i] = input[i] - 'A' +'a';
            //}
            printf("%c", TOUPPER(input[i]));
        }


    }
    else if(mode == 2){
        for(i=0;i<strlen(input);i++){
            printf("%c", TOLOWER(input[i]));
        }
    }
    else if(mode == 3){
        for(i=0;i<strlen(input);i++){
            
            printf("%c", (i%2==0 ? TOUPPER(input[i]) : TOLOWER(input[i])));
        }
    }


}