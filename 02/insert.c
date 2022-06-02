#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init(char *, int *);              // 要素数, 最小値, 最大値の取得
void read_data(char *, int *, int);    // データの読み込み
double insert(int *, int);             // インサートソート

int main(int argc, char *argv[]){
   int i, n;
   int *a;
   double time;

   // 引数は２つあるか
   if(argc != 2){
      puts("Parameter Error");
      return 0;
   }

   init(argv[1], &n);

   // 動的にメモリを確保
   a = (int *)malloc(sizeof(int)*n);
   if(a == NULL) return 1;

   // ファイルを開ける
   read_data(argv[1], a, n);

   // バケットソート
   time = insert(a, n);

   // 結果を表示
   for(i=0; i<n; i++){
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

// インサートソート
double insert(int *a, int n){
   int i, j, temp, k;
   int flag = 0;
   long start_time, end_time;

   start_time = clock();

   for(i=0; i<n; i++){
      for(j=i; j>0; j--){
         if(a[j-1] > a[j]){
            temp = a[j];
            a[j] = a[j-1];
            a[j-1] = temp;
         }else{
            break;
         }
      }
   }

   end_time = clock();

   return (double)(end_time-start_time)/CLOCKS_PER_SEC;
}