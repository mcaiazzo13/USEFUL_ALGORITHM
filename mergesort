//------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------MERGESORT--------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int n;
//------------------------------------------------- MERGE FUNCTION
void merge(int a[],int inizio,int m,int fine){
  int i,j,k;
  int b[100];
  i = inizio;
  j = m+1;
  k = 0;

  while(i<= m && j<= fine){
    if(a[i] <= a[j]){
      b[k] = a[i];
      i++;
    }else{
      b[k] = a[j];
      j++;
    }
    k++;
  }
  while(i <= m){
    b[k] = a[i];
    i++;
    k++;
  }
  while(j <= fine){
    b[k] = a[j];
    j++;
    k++;
  }
  for(k=inizio;k<=fine;k++)
    a[k] = b[k-inizio];
}
//------------------------------------------------- MERGESORT FUNCTION
void mergeSort(int array[],int inizio,int fine){
  int i,j,k,m;
  int b[n];

  if(inizio < fine){
    m = (inizio+(fine-1))/2;
    mergeSort(array,inizio,m);
    mergeSort(array,m+1,fine);
    merge(array,inizio,m,fine);
  }
}


//------------------------------------------------- MAIN
int main(int argc,char *argv[]){
  int i,r;
  n = atoi(argv[1]);
  int array[n];

  srand((unsigned)time(NULL));
  for(i=0;i<n;i++){
    r = rand()%50;
    array[i] = r;
  }

  printf("\nPRIMA\n");
  for(i=0;i<n;i++)
    printf("%d \n",array[i]);

  mergeSort(array,0,n-1);
  
  printf("\nDOPO\n");
  for(i=0;i<n;i++)
    printf("%d \n",array[i]);
  return 0;
}
