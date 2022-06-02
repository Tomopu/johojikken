#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N   50000       // データの総数
#define MIN -20000
#define MAX 20000

//0.0002270000

void read_data(char *, int *);   
double ranking(int *, int *);    // 戻り値(実行時間[s])

int main(int argc, char *argv[]){
   int a[N];
   int i, data;
   double time;
   int juni[(MAX-MIN)+2] = {};

   // 順位配列の初期化
   juni[0] = 1;

   // 引数は２つあるか
   if(argc != 2){
      puts("Parameter Error");
      return 0;
   }

   // ファイルを開ける
   read_data(argv[1], a);

   // ランキング付け
   time = ranking(a, juni);

   // 実行結果の表示
   for(i=0; i<N; i++){
      printf("%6d %6d \n", a[i], juni[a[i]-MIN]);
   }

   printf("実行時間: %.10lf(s)\n", time);

   return 0;
}

// データの読み込み
void read_data(char *fname, int *a){
   FILE *fp;
   int i, data;

   if((fp = fopen(fname, "r")) == NULL){
      puts("File Open Error"); 
      exit(EXIT_FAILURE);
   }

   for(i=0; i<N; i++){
      fscanf(fp, "%d", &data);
      *(a+i) = data;
   }

   fclose(fp);
   return;
}

// ランキング付け 戻り値(実行時間)
double ranking(int *a, int *juni){
   int i;
   const int diff = 1-MIN; 
   long start_time, end_time;

   start_time = clock();

   for(i=0; i<N; i++){
      juni[a[i]+diff]++;
   }

   for(i=0; i<(MAX-MIN)+1; i++){
      juni[i+1] += juni[i];
   }

   end_time = clock();

   return (double)(end_time-start_time)/CLOCKS_PER_SEC;
}