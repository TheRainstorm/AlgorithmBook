#include <iostream>

using namespace std;
#define NUM 100

void simple_string_match(char *T,char *P,int n,int m){
	int s;
	for(s=0;s<=n-m;s++){
		int i;
		for(i=0;i<m;i++){
			if(T[s+i]!=P[i]){
				break;
			}
		}
		if(i>=m){
			cout<<"one s occupy at: "<<s<<endl;
		}
	}
}

int main(){
	char T[NUM] = "ababac";
	char P[NUM] = "aba";
	int n=5,m=3;

	simple_string_match(T,P,n,m);

	return 0;
}