#include <iostream>

using namespace std;

int max_sum(int *A,int n){
	int result,sum;

	result = sum = A[0];
	for(int j=1;j<n;j++){
		if(sum>0){
			sum +=A[j];
		}
		else{
			sum = A[j];
		}

		if(result < sum){
			result = sum;
		}
	}
	return result;
}

int max_sum_place(int *A,int n){
	int result,sum;
	int p,q,p_tmp;

	result = sum = A[0];
	p_tmp = 0;
	for(int j=1;j<n;j++){
		//sum[j] = max{ sum[j-1]+A[j], A[j]};
		if(sum>0){
			sum +=A[j];
		}
		else{
			sum = A[j];
			p_tmp = j;
		}

		if(result < sum){
			result = sum;
			p = p_tmp;
			q = j;
		}
	}
	
	for(int i=p;i<=q;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
	cout<<"p: "<<p+1<<"\n"<<
		  "q: "<<q+1<<"\n"<<
		  "sum: "<<result<<endl;

	return result;
}
int main(){
	int A[16] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	int n=16;

	//cout<<max_sum(A,n)<<endl;
	max_sum_place(A,n);

	return 0;
}