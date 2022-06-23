#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init(char *, int *);
void read_data(char *, int *, int, int, int);   // データの読み込み
void swap(int *, int, int);
void quick(int *, int, int);

int main(int argc, char *argv[]) {
   int i, n, upper, lower;
   long start_time, end_time;
   int *a;
   double time;

   // 引数は２つあるか
   if(argc < 2){
      puts("Parameter Error");
      return 0;
   }

   // データの要素数を取得
   init(argv[1], &n);

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
      else if(lower < 0){
         printf("error: The index of the lower limit for splitting data is out of range \n");
         printf("Change the lower limit to 0\n");
         lower = 0;
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

   printf("lower: %d, upper: %d, n: %d\n", lower, upper, n);

   // 動的にメモリを確保
   a = (int *)malloc(sizeof(int)*((upper-lower)+1));
   if(a == NULL) return 1;

   printf("a");

   // ファイルを開ける
   read_data(argv[1], a, n, lower, upper);

   printf("b");

   start_time = clock();   
   // クイックソート
   quick(a, 0, (upper-lower));
   end_time = clock();

   time = (double)(end_time-start_time)/CLOCKS_PER_SEC;

   // 結果を表示
   printf("\n");
   for(i=0; i<(upper-lower)+1; i++){
      printf("%d ", *(a+i));
   }
   printf("\n");
   printf("実行時間: %.10lf(s)\n", time);

   // メモリの解放
   free(a);
   return 0;
}

// 要素数, 最小値, 最大値の取得
void init(char *fname, int *n){
   FILE *fp;
   int data;

   *n = 0;  // 要素数の初期化

   if((fp = fopen(fname, "r")) == NULL){
      perror("File Open Error \n");
      exit(EXIT_FAILURE);
   }

   // 要素数, 最小値, 最大値の取得
   while(fscanf(fp, "%d", &data) != EOF){
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

void swap(int *a, int i, int j) {
   int tmp;
   tmp = a[i];
   a[i] = a[j];
   a[j] = tmp;
}

/* クイックソートを行う関数 */
void quick(int a[], int left, int right) {
   // static int count = 0;
   int i = left;
   int j = right;
   int pivot = a[left];
   int k;

   // count++;
   // printf("[%d]", count);

   // 終了条件
   if(left >= right) return;

   while(1) {
      // 並び順がおかしいところまで検索
      while ((a[i] < pivot) && (i < j)) i++;
      while ((a[j] > pivot) && (i < j)) j--;

      // 終了条件
      if (i >= j) break;
      
      // 入れ替え
      swap(a, i, j);
   }

   // pivotよりも小さい値のソート
   quick(a, left, i-1);
   
   // 大きい数字を集めた範囲に対してソート */
   quick(a, j+1, right);
}