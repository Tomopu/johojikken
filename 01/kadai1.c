#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10           // データの総数

void read_data(char *, int *);
double ranking(int *, int *);

int main(int argc, char *argv[]){
   int a[N];
   int rank[N];
   int i;
   double time;

   // 引数は２つあるか
   if(argc != 2){
      puts("Parameter Error");
      return 0;
   }

   // ファイルを開ける
   read_data(argv[1], a);

   // ランキング付け
   time = ranking(a, rank);

   // 結果を表示
   for(i=0; i<N; i++){
      printf("%6d %6d \n", a[i], rank[i]);
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

double ranking(int *a, int *rank){
   int i, j, data, juni;
   long start_time, end_time;

   start_time = clock();

   for(i=0; i<N; i++){
      data = a[i];
      juni = 1;
      for(j=0; j<N; j++){
         if(data < a[j]){
            juni++;
         }
         rank[i] = juni;
      }
   }

   end_time = clock();

   return (double)(end_time-start_time)/CLOCKS_PER_SEC;
}






