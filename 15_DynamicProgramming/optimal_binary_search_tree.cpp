#include <iostream>
#include <stdio.h>

using namespace std;

int mymin(int a,int b){
	return (a<b)?a:b;
}

void release(int **A,int m){
	for(int i=0;i<m;i++){
		delete []A[i];
	}
}
void compute_w(int *p,int *q,int n,int **w){
	int i,j;
	for(i=1;i<=n;i++){
		j = i-1;
		w[i][j] = q[i-1];
		for(j=i;j<=n;j++){
			w[i][j] = w[i][j-1] + p[j] +q[j];
		}
	}
}

void optimal_BST(int *p,int *q,int n){
	int **DP = new int*[n+2];		//n+2 挺特殊的，计算DP[n][n]时用到 DP[n][n-1] + DP[n+1][n] +w[n][n];
	for(int i=0;i<=n+1;i++){
		DP[i] = new int[n+1];
	}

	int **w = new int*[n+1];
	for(int i=0;i<=n;i++){
		w[i] = new int[n+1];
	}

	compute_w(p,q,n,w);

	//DP[i,j] = 	q[j]				j=i-1
	//				(i<=k<=j) min{DP[i,k-1] + DP[k+1,j] + w[i,j] }	j>=i
	for(int i=1;i<=n+1;i++){
		DP[i][i-1] = q[i-1];
	}

	// for(int i=0;i<=n;i++){			//print w
	// 	for(int j=0;j<=n;j++){
	// 		printf("%12d",w[i][j]);
	// 	}
	// 	cout<<endl;
	// }
	// cout<<endl;

	// for(int i=0;i<=n;i++){			//print DP
	// 	for(int j=0;j<=n;j++){
	// 		printf("%12d",DP[i][j]);
	// 	}
	// 	cout<<endl;
	// }
	// cout<<endl;

	int i,j,l,k;
	for(l=1;l<=n;l++){
		for(i=1;i<=n-l+1;i++){
			j = l + i -1;

			k = i;
			DP[i][j] = DP[i][k-1] + DP[k+1][j] + w[i][j];
			for(k=i+1;k<=j;k++){
				DP[i][j] = mymin(DP[i][j],DP[i][k-1] + DP[k+1][j] + w[i][j]);
			}
		}
	}

	cout<<"min cost: "<<DP[1][n]<<endl;
	for(int i=0;i<=n;i++){			//print DP
		for(int j=0;j<=n;j++){
			printf("%12d",DP[i][j]);
		}
		cout<<endl;
	}
	cout<<endl;

	release(DP,n+2);
	release(w,n+1);
}

int lookup(int **DP,int i,int j,int *p,int *q,int n,int **w){
	if(DP[i][j]>=0){
		;
	}
	else if(j==i-1){
		DP[i][j] = q[i-1];
	}
	else{
		int k = i;
		DP[i][j] = lookup(DP,i,k-1,p,q,n,w)+lookup(DP,k+1,j,p,q,n,w)+w[i][j];
		for(k=i+1;k<=j;k++){
			DP[i][j] = mymin(DP[i][j],lookup(DP,i,k-1,p,q,n,w)+lookup(DP,k+1,j,p,q,n,w) + w[i][j]);
		}
	}
	return DP[i][j];
}

void memorized_optimal_BST(int *p,int *q,int n){
	int **DP = new int*[n+2];
	for(int i=0;i<=n+1;i++){
		DP[i] = new int[n+1];
	}

	int **w = new int*[n+1];
	for(int i=0;i<=n;i++){
		w[i] = new int[n+1];
	}

	compute_w(p,q,n,w);
	
	//initial DP with -1
	for(int i=0;i<=n+1;i++){
		for(int j=0;j<=n;j++){
			DP[i][j]=-1;
		}
	}

	cout<<"min cost: "<<lookup(DP,1,n,p,q,n,w)<<endl;
	for(int i=0;i<=n;i++){			//print DP
		for(int j=0;j<=n;j++){
			printf("%12d",DP[i][j]);
		}
		cout<<endl;
	}
	cout<<endl;

	release(DP,n+2);
	release(w,n+1);
}

int main(){
	int p[6] = {0,15,10,5,10,20};
	int q[6] = {5,10,5,5,5,10};
	int n = 5;

	optimal_BST(p,q,n);
	memorized_optimal_BST(p,q,n);

	return 0;
}