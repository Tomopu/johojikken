#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init(char *, int *, int *, int *);      // 要素数, 最小値, 最大値の取得
void read_data(char *, int *, int);          // データの読み込み
double bucket(int *, int *, int, int, int);  // バケットソート

int main(int argc, char *argv[]){
   int i, n, min, max;
   int *a, *bkt;
   double time;

   // 引数は２つあるか
   if(argc != 2){
      puts("Parameter Error");
      return 0;
   }

   init(argv[1], &n, &min, &max);

   // 動的にメモリを確保
   a = (int *)malloc(sizeof(int)*n);
   if(a == NULL) return 1;

   bkt = (int *)malloc(sizeof(int)*((max-min)+1));
   if(bkt == NULL) return 1;

   // ファイルを開ける
   read_data(argv[1], a, n);

   // バケットソート
   time = bucket(a, bkt, n, min, max);

   // 結果を表示
   for(i=0; i<n; i++){
      printf("%d ", *(a+i));
   }
   printf("\n");
   printf("実行時間: %.10lf(s)\n", time);

   // メモリの解放
   free(a);
   free(bkt);

   return 0;
}

// 要素数, 最小値, 最大値の取得
void init(char *fname, int *n, int *min, int *max){
   FILE *fp;
   int data;

   *n = 0;  // 要素数の初期化

   if((fp = fopen(fname, "r")) == NULL){
      perror("File Open Error \n");
      exit(EXIT_FAILURE);
   }

   // 要素数, 最小値, 最大値の取得
   while(fscanf(fp, "%d", &data) != EOF){
      if(*n == 0){
         *min = *max = data;
      }

      if(data < *min) *min = data;
      if(data > *max) *max = data;

      (*n)++;
   }

   fclose(fp);
   return;
}

// データの読み込み
void read_data(char *fname, int *a, int n){
   FILE *fp;
   int i, data;

   if((fp = fopen(fname, "r")) == NULL){
      puts("File Open Error"); 
      exit(EXIT_FAILURE);
   }

   for(i=0; i<n; i++){
      fscanf(fp, "%d", &data);
      *(a+i) = data;
   }

   fclose(fp);
   return;
}

// バケットソート
double bucket(int *a, int *bkt, int n, int min, int max){
   int buf[n];
   int i, j, k;
   long start_time, end_time;

   start_time = clock();

   for(i=0; i<n; i++){
      bkt[a[i]-min]++;
   }

   k = 0;
   for(i=0; i<(max-min)+1; i++){
      for(j=0; j<bkt[i]; j++){
         a[k] = i + min;
         k++;
      }
   }

   end_time = clock();

   return (double)(end_time-start_time)/CLOCKS_PER_SEC;
}