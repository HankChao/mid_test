#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char number1[4], number2[4], number3[6];
    
    printf("Please enter the first operand: ");
    if(scanf("%3s", number1) != 1) {
        printf("error\n");
        return 0;
    }
    printf("Please enter the second operand: ");
    if(scanf("%3s", number2) != 1) {
        printf("error\n");
        return 0;
    }
    printf("Please enter the product: ");
    if(scanf("%5s", number3) != 1) {
        printf("error\n");
        return 0;
    }

    char temp1[4], temp2[4], temp3[6];
    int32_t sol_cur = 0;

    
    for(int32_t a = 0; a < 10; a++) {
        
        strcpy(temp1, number1);
        for(int i = 0; temp1[i]; i++) {
            if(temp1[i] == 'a') temp1[i] = a + '0';
        }
        
        for(int32_t b = 0; b < 10; b++) {
            
            strcpy(temp2, number2);
            for(int i = 0; temp2[i]; i++) {
                if(temp2[i] == 'b') temp2[i] = b + '0';
            }
            
            int32_t n1 = atoi(temp1);
            int32_t n2 = atoi(temp2);
            int32_t product = n1 * n2;
            
            for(int32_t c = 0; c < 10; c++) {
                for(int32_t d = 0; d < 10; d++) {
                    
                    strcpy(temp3, number3);
                    for(int i = 0; temp3[i]; i++) {
                        if(temp3[i] == 'c') temp3[i] = c + '0';
                        if(temp3[i] == 'd') temp3[i] = d + '0';
                    }
                    
                    int32_t expected = atoi(temp3);
                    
                    if(product == expected) {
                        if(!sol_cur) {
                            printf("Solutions:\n");
                        }
                        sol_cur++;
                        printf("%03d x %03d = %d\n", n1, n2, product);
                    }
                }
            }
        }
    }
    
    if(!sol_cur) {
        printf("No solutions\n");
    }
    
    return 0;
}