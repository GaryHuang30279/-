#include <stdio.h>

int main() {
    int num;
    int i=0;
    scanf("%d", &num);

    while (num != 1) {
        for (i = 1; i <=num; i++) {
            if (num % i == 0 && i != 1) {
                printf("%d ", i );
                num = num / i;
                break;
            }
        } 
    }
}