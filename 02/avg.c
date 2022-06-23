#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_DATA 7
#define NUM_OF_SPLIT 10

void read_data(char *, double *, int);
void avgs(double *, int);

int main(int argc, char *argv[]){
   int i, split;
   double *a;

   // 引数は２つあるか
   if(argc < 3){
      puts("Parameter Error");
      return 0;
   }
   
   // 分割する場所（試行回数)
   split = atoi(argv[2]);
   
   // 動的にメモリを確保
   a = (double *)malloc(sizeof(double)*(split*NUM_OF_SPLIT*NUM_OF_DATA));
   if(a == NULL) return 1;
   
   // ファイルを開ける
   read_data(argv[1], a, (split*NUM_OF_SPLIT*NUM_OF_DATA));

   avgs(a, split);

   // メモリの解放
   free(a);

   return 0;
}


// データの読み込み
void read_data(char *fname, double *a, int n){
   FILE *fp;
   int i;
   double data;

   if((fp = fopen(fname, "r")) == NULL){
      puts("File Open Error"); 
      exit(EXIT_FAILURE);
   }

   for(i=0; i<n; i++){
      fscanf(fp, "%lf", &data);
      *(a+i) = data;
   }

   fclose(fp);
   return;
}

void avgs(double *a, int split){
   int d, i, j, c;
   double avg;
   c = 0;
   for(d=0; d<NUM_OF_DATA; d++){
      printf("----data%d.dat----------------\n", d+1);
      for(i=0; i<NUM_OF_SPLIT; i++){
         avg = 0;
         for(j=c; j < c+split; j++){
            avg += a[j];
         }
         printf("%.10lf, ", avg/(double)split);
         c+=split;
      }
      printf("\n");
   }

   return;
}