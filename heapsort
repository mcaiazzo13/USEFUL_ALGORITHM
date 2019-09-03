//---------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- HEAPSORT ----------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int n;

//------------------------------------------------- LEFTSON FUNCTION
int leftson(int node){
	return 2*node;
}
//------------------------------------------------- RIGHTSON FUNCTION
int rightson(int node){
	return 2*node+1;
}
//------------------------------------------------- SWAP FUNCTION
void swap(int x,int y,int *abr[]){
	int *temp;
	temp = abr[x];
	abr[x] = abr[y];
	abr[y] = temp;
}

//------------------------------------------------- HEAPIFY FUNCTION
void heapify(int *abr[],int node){
	int i,l,r,m,max;
	m = n-1;
	l = leftson(node);
	r = rightson(node);

	if(l <= m && *abr[l] > *abr[node]){
		max = l;
	}else{
		max = node;
	}
	if(r <= m && *abr[r] > *abr[max]){
		max = r;
	}
	if(max != node){	
		swap(node,max,abr);
		heapify(abr,max);
	}
}
//------------------------------------------------- HEAPSORT FUNCTION
void heapsort(int *abr[],int node){
	
	int i;
	for(i=n-1;i>=1;i--){
		swap(0,i);
		m = m-1;
		heapify(abr,i);
	}
}


//------------------------------------------------- MAIN
int main(int argc,char *argv[]){
int i,r;
n = atoi(argv[1]);
int *abr[n];



for(i=0;i<n;i++)
	abr[i] = (int*)calloc(1,sizeof(int));

srand((unsigned)time(NULL));
for(i=0;i<n;i++){
	r = rand()%50;
	*abr[i] = r;
}

printf("\nBEFORE\n");
for (i = 0; i < n; i++){
	printf("%d \n",*abr[i]);
}

for(i=n-1;i>0;i--)
    heapify(abr,i-1);

printf("\nAFTER\n");
for (i = 0; i < n; i++){
	printf("%d \n",*abr[i]);
}

// USING HEAPSORT
	heapsort(abr,0);	

printf("\nAFTER (2)\n");
for (i = 0; i < n; i++){
	printf("%d \n",*abr[i]);
}
	return 0;
}
