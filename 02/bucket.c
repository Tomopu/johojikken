#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init(char *, int *, int *, int *);      // 要素数, 最小値, 最大値の取得
void read_data(char *, int *, int, int, int);          // データの読み込み
double bucket(int *, int *, int, int, int);  // バケットソート

int main(int argc, char *argv[]){
   int i, n, upper, lower, min, max;
   int *a, *bkt;
   double time = 0;

   // 引数は２つあるか
   if(argc < 2){
      puts("Parameter Error");
      return 0;
   }

   init(argv[1], &n, &min, &max);

   // 上限と下限の初期化
   lower = 0;
   upper = n-1;
      
   // 引数の文字列を整数に変換
   if(argc >= 3){
      lower = atoi(argv[2]);
      if(lower > n-1){
         printf("error: The index of the lower limit for splitting data is out of range \n");
         printf("Change the lower limit to %d\n", n-1);
         lower = n-1;
      }
   }

   if(argc >= 4){
      upper = atoi(argv[3]);
      if(upper > n-1){
         printf("error: The index of the lower limit for splitting data is out of range. \n");
         printf("Change the upper limit to %d\n", n-1);
         upper = n-1;
      }else if(upper < lower){
         printf("error: The upper limit is less than the lower limit. \n");
         printf("Change the upper limit to %d\n", lower);
         upper = lower;
      }
   }

   // 動的にメモリを確保
   a = (int *)malloc(sizeof(int)*(upper-lower)+1);
   if(a == NULL) return 1;

   bkt = (int *)malloc(sizeof(int)*((max-min)+1));
   if(bkt == NULL) return 1;

   // ファイルを開ける
   read_data(argv[1], a, n, lower, upper);

   // バケットソート
   time = bucket(a, bkt, (upper-lower)+1, min, max);

   // 結果を表示
   // for(i=0; i<(upper-lower)+1; i++){
   //    printf("%d ", *(a+i));
   // }
   // printf("\n");

   // printf("実行時間: %.10lf(s)\n", time);
   printf("%.10lf\n", time);


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
void read_data(char *fname, int *a, int n, int lower, int upper){
   FILE *fp;
   int i, j, data;

   if((fp = fopen(fname, "r")) == NULL){
      puts("File Open Error"); 
      exit(EXIT_FAILURE);
   }

   // インデックスを初期化
   j = 0;

   for(i=0; i<n; i++){
      fscanf(fp, "%d", &data);
      if(lower <= i && i <= upper){
         *(a+j) = data;
         j++;
      } 
   }

   fclose(fp);
   return;
}

// バケットソート
double bucket(int *a, int *bkt, int n, int min, int max){
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