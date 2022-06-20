#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define DENO 77776
#define TIMES 400

double dice_prob(void);

int main(int argc, char *argv[]){
    int i, times;
    double prob = 0;

    if(argc == 0) times = 1;
    else times = atoi(argv[1]);

    // 乱数の設定
    srand((unsigned int)time(NULL));

    for(i=0; i<times; i++){
        prob += dice_prob();
    }

    printf("%d回平均: %.10lf\n", times, prob/(double)times);

    return 0;
}

double dice_prob(void){
    int i, j, dice, last;
    int same = 0;   // ゾロ目になった回数

    for(i=0; i<DENO*TIMES; i++){
        for(j=0; j<6; j++){
            dice = rand()%6+1;
            if(j == 0) last = dice;
            if(last == dice){
                if(j == 5) same++;
            }
            else break;
        }
    }

    return (double)same/(double)(DENO*TIMES);   
}