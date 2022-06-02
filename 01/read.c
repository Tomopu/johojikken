#include <stdio.h>

#define N 30

int main(int argc, char *argv[]){
   FILE *fp;   // 変数定義
   int a[N];
   int i,data;

   // 引数は２つあるか
   if(argc != 2){
      puts("Parameter Error");
      return 0;
   }

   // ファイルは存在するか
   if((fp = fopen(argv[1],"r")) == NULL){
      puts("File Open Error"); 
      return 0;
   }

   for(i=0;i<N;i++){
      fscanf(fp, "%d", &data);
      a[i] = data;
   }

   fclose(fp);
   return 0;
}






