#include<stdio.h>
#include<stdint.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"

int main(){
    int32_t width,height,number;
    printf("Please enter the card size (width,height): ");
    
    if(scanf("%d,%d", &width, &height)!=2 || width<7 ||
    width>40 || height<4 || height>10){
        printf("Invalid input\n");
        return 0;
    }

    printf("Please enter the card number: ");
    if(scanf("%d", &number)!=1 || number<1 || number>40){
        printf("Invalid input\n");
        return 0;
    }

    int32_t left[40]={0};
    for(int32_t i=number;i>=1;i--){
        for(int32_t j=1;j<=i-1;j++)
            printf(" ");
        
        int32_t cur_color=i%4;
        if(cur_color==0){
            printf(BLUE "+");
            for(int32_t j=0;j<width-2;j++){
                printf("-");
            }
            printf("+" RESET);
        }
        else if(cur_color==1){
            printf(RED "+");
            for(int32_t j=0;j<width-2;j++){
                printf("-");
            }
            printf("+" RESET);
        }
        else if(cur_color==2){
            printf(YELLOW "+");
            for(int32_t j=0;j<width-2;j++){
                printf("-");
            }
            printf("+" RESET);
        }
        else{
            printf(GREEN "+");
            for(int32_t j=0;j<width-2;j++){
                printf("-");
            }
            printf("+" RESET);
        }

        left[i-1]=height-1;
        for(int32_t j=i;j<number;j++){
            if(left[j]>0){
                int32_t left_color=(j+1)%4;
                switch(left_color){
                    case 0:
                        printf(BLUE);
                        break;
                    case 1:
                        printf(RED);
                        break;
                    case 2:
                        printf(YELLOW);
                        break;
                    case 3:
                        printf(GREEN);
                        break;
                }

                if(left[j]==1)  printf("+");
                else   printf("|");

                left[j]--;
                printf(RESET);

            }
        }

        printf("\n");

    }

    left[0]=0;
    for(int32_t i=1;i<height;i++){
        printf(RED);
        if(i!=height-1) printf("|");
        else    printf("+");

        if(i!=height-1)
            for(int j=0;j<width-2;j++){
                printf(" ");
            }
        else
            for(int j=0;j<width-2;j++){
                printf("-");
            }

        if(i!=height-1) printf("|");
        else    printf("+");
        printf(RESET);

        for(int32_t j=0;j<number;j++){
            if(left[j]>0){
                int32_t left_color=(j+1)%4;
                switch(left_color){
                    case 0:
                        printf(BLUE);
                        break;
                    case 1:
                        printf(RED);
                        break;
                    case 2:
                        printf(YELLOW);
                        break;
                    case 3:
                        printf(GREEN);
                        break;
                }

                if(left[j]==1)  printf("+");
                else   printf("|");

                left[j]--;
                printf(RESET);

            }
        }

        printf("\n");
    }

}