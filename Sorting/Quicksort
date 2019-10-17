//-------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------- QUICKSORT -----------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int n;
//------------------------------------------------- SWAP FUNCTION
void swap(int x,int y,int *array[]){
  int *temp;
  temp = array[x];
  array[x] = array[y];
  array[y] = temp;
}
//------------------------------------------------- PARTITION FUNCTION
int partition(int *array[],int inizio,int fine){
  int pivot,i,j,k;
  pivot = *array[fine];
  i = inizio-1;
  
  for(j=inizio;j<=fine-1;j++){
    if(*array[j] < pivot){
      i++;
      swap(i,j,array);
    }
  }
  swap(i+1,fine,array);
  return i+1;
}
//------------------------------------------------- QUICKSORT FUNCTION
void quicksort(int *array[],int inizio,int fine){
  int m;
  if(inizio < fine){
    m = partition(array,inizio,fine);
    quicksort(array,inizio,m-1);
    quicksort(array,m+1,fine);
  }
}
//------------------------------------------------- MAIN
int main(int argc,char *argv[]){
  n = atoi(argv[1]);
  int i,r;
  int *array[n];
  for(i=0;i<n;i++)
    array[i] = (int*)calloc(1,sizeof(int));
  srand((unsigned)time(NULL));
  for(i=0;i<n;i++){
    r = rand()%50;
    *array[i] = r;
  }

  printf("\nPRIMA\n");
  for(i=0;i<n;i++)
    printf("%d\n",*array[i]);
  
  quicksort(array,0,n-1);

  printf("\nDOPO\n");
  for(i=0;i<n;i++)
    printf("%d \n",*array[i]);
  return 0;
}
