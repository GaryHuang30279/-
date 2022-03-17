#include <stdio.h>
#include <string.h>
#include <ctype.h>

char TOLOWER(char *input){
    for (int i = 0; i < strlen(input); i++) {  //讀進的article全換小寫
        input[i] = tolower(input[i]);   
    }                                    
    input[strlen(input)] = '\0';
}

int main(){
    int option;
    int num;   //讀入幾次
    int i,j;
    int count_same;
    int outputnum = 0;
    scanf("%d\n", &option);
    //if(option!=1 && option!=2) return 0;
    scanf("%d", &num);
    

    char input[num-1][100];  //read string

    
    
    if(option==1){

        for(i=0;i<num;i++){
            scanf("%s", input[i]);
        }

        for(i=0;i<strlen(input[i]);i++){  
            for(j=0;j<num;j++){     //because the 1st string(j=0) 是拿來當對照組的
                if( input[j][i] == input[0][i] && j!=0 ){
                    count_same++;  
                }
            }
            if(count_same==num-1){     //重複次數等於全部組-對照本身
                printf("%c", input[0][outputnum]);
                outputnum++;
                count_same = 0;
            }
            else{
                if(i==0) printf("No longest common prefix");
                break;
            }
        }
        
        
    }
    else if(option==2){

        for(i=0;i<num;i++){
            scanf("%s", input[i]);
            TOLOWER(input[i]);
            // printf("%s", input[i]);
        }

        for(i=0;i<strlen(input[i]);i++){  
            for(j=0;j<num;j++){     //because the 1st string(j=0) 是拿來當對照組的
                if(input[j][i]==input[0][i] && j!=0){
                    count_same++;  
                }
            }
            if(count_same==num-1){     //重複次數等於全部組-對照本身
                printf("%c", input[0][outputnum]);
                outputnum++;
                count_same = 0;
            }
            else{
                if(i==0) printf("No longest common prefix");
                break;
            }
        }

    }
    

    return 0;
    
} 