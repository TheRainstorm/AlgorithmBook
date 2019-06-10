#include <iostream>
#include <stdio.h>
using namespace std;

int partition(int *A,int p,int r){
	int i,j,temp;
	i=p-1,j=r;

	int x=A[r];			//select A[r] as pivot

	while(1){
		while(A[--j]>=x);
		while(A[++i]<x);
		
		if(i<j){
			temp = A[i];A[i]=A[j];A[j]=temp;
		}
		else{
			break;
		}
	}
	//swap A[r] and A[i]
	temp = A[r];A[r]=A[i];A[i]=temp;

	// cout<<"partition: ";
	// for(int k=p;k<=r;k++){
	// 	cout<<A[k]<<" ";
	// }
	// cout<<endl;

	return i;
}

void quick_sort(int *A,int p,int r){
	int pivot,tmp,k;
	if(p<r){
		k= rand()%(r-p+1)+p;
		tmp = A[k];A[k]=A[r];A[r]=tmp;
		pivot = partition(A,p,r);
		quick_sort(A,p,pivot-1);
		quick_sort(A,pivot+1,r);
	}
}

int main(){
	int A[16] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	int n=16;
	
	//cout<<partition(A,0,n-1)<<endl;
	quick_sort(A,0,n-1);
	for(int i=0;i<n;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;

	return 0;
}