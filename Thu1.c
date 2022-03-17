#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define MAX 4096

char *getword(char *input, char *word) {
    char *ptr = input;
    char *qtr = word;

    while (isalnum(*ptr) == 0 && *ptr != '-' && *ptr) {
        ptr++;
    }
    while ((isalnum(*ptr) || *ptr == '-') && *ptr) {
        *qtr = *ptr;
        ptr++;
        qtr++;
    }
    *qtr = '\0';
    if (word == qtr) {
        return 0;
    }
    return ptr;
}

// int findupper(char *replacestr){
//     int j;
//     for (j = 0; j < strlen(replacestr); j++){
//         if(isupper(replacestr[j])){
//             return 1;
//             break;
//         }
//     }
//     return 0;
// }

char *replacement(char *input, char *targetstr, char *replacestr) {
    char *ptr = input;
    char *sstr;

    sstr = strstr(input, targetstr);

    while (ptr != sstr) {
        printf("%c", *ptr);
        ptr++;
    }
    printf("%s", replacestr);
    ptr = sstr + strlen(targetstr);
    return ptr;
}

char *replacement_clean(char *input, char *compare, char *cleantargetstr, char *replacestr) {
    char *ptr = input;
    char *qtr = compare;
    char *sstr;

    sstr = strstr(compare, cleantargetstr);

    while (qtr != sstr) {
        printf("%c", *ptr);
        qtr++;
        ptr++;
    }
    printf("%s", replacestr);
    ptr = ptr + strlen(cleantargetstr);
    return ptr;
}

int main() {
    char input[MAX];
    char str[MAX];         // Read the input string  by getword()
    char targetstr[MAX];   // as the name suggest
    char replacestr[MAX];  // --
    char parameter[MAX];   // --
    int i = 1;             // The i th number strings
    int j = 1;             // just for count

    fgets(input, MAX, stdin);  // 判斷想要的模式   //1.讀文章 2.getword 3.Case: nonsensitive || sensitive || error
    char *ptr = input;
    // printf("Enter pattern, replacement, and at most one parameter: ");
    while (ptr = getword(ptr, str)) {
        if (i <= 3) {
            if (i == 1) {
                strncpy(targetstr, str, strlen(str));
                targetstr[strlen(str)] = '\0';
            } else if (i == 2) {
                strncpy(replacestr, str, strlen(str));
                replacestr[strlen(str)] = '\0';
            } else {
                strncpy(parameter, str, strlen(str));
                parameter[strlen(str)] = '\0';
            }
        }
        i++;
    }
    // printf("i:%d\n", i);               //For test
    // printf("1.%s\n", targetstr);
    // printf("2.%s\n", replacestr);
    // printf("parameter:%s\n", parameter);

    char *ptr2 = NULL;         //  a pointer given after replacement() ,points to a target-skipping string
    char cleanstr[MAX];        //  all lower article
    char cleantargetstr[MAX];  //  all lower target

    if (i == 3) {  //沒有大小寫設定                              // 1.讀文章 2.getword 3.replace&printf
        // printf("Enter the article:\n");
        while (fgets(input, MAX, stdin)) {
            char *ptr = input;

            while (ptr = getword(ptr, str)) {
                if (strstr(str, targetstr)) {
                    ptr2 = replacement(str, targetstr, replacestr);
                    printf("%s\n", ptr2);
                }
            }
        }
    } else if (i == 4) {  //有大小寫設定                           //1.讀文章 2.getword 3.大小寫replace

        if (!strcmp(parameter, "-i")) {  //測資十guess replacestr要有大寫wrong  && findupper()
            // printf("Enter the article:\n");                                                   
            while (fgets(input, MAX, stdin)) {                                                  
                char *ptr = input;              

                while (ptr = getword(ptr, str)) {  

                    for (j = 0; j < strlen(str); j++) {  //讀進的article全換小寫       
                        cleanstr[j] = tolower(str[j]);   
                    }                                    
                    cleanstr[strlen(str)] = '\0';        

                    for (j = 0; j < strlen(targetstr); j++) {  //讀進的target全換小寫  <<--right
                        cleantargetstr[j] = tolower(targetstr[j]);
                    }
                    cleantargetstr[strlen(targetstr)] = '\0';

                    if (strstr(cleanstr, cleantargetstr)) {
                        ptr2 = replacement_clean(str, cleanstr, cleantargetstr, replacestr);
                        printf("%s\n", ptr2);
                    }
                }  
            }
        } else {
            printf("The input format: string1 string2 [parameter]");
        }
    } else {
        printf("The input format: string1 string2 [parameter]");
    }

    return 0;
}