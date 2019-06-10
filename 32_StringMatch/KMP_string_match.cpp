#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;
#define NUM 1000

int prefix[NUM];

void compute_prefix_function(char *P,int m){
    prefix[0]=0;
    prefix[1]=0;

    int k=0;
    for(int q=2;q<=m;q++){
        while(k!=0 && P[k+1-1]!=P[q-1]){
            k=prefix[k];
        }
        if(P[k+1-1]==P[q-1]){
            k=k+1;
        }
        prefix[q]=k;
    }
}

void KMP_match_my(char *T,char *P,int n,int m){
    compute_prefix_function(P,m);

    int q=0;
    for(int s=0;s<=n-m;){
        while(q<m && T[s+q]==P[q]){
            q++;
        }

        if(q==m){
            cout<<"find one s occupy at: "<<s<<endl;
        }

        if(q==0){
            s = s + 1;
        }
        else{
            s = s + (q-prefix[q]);
            q = prefix[q];
        }
    }
}

// void KMP_match(char *T,char *P,int n,int m){
//     compute_prefix_function(P,m);


// }

int main(){
	char T[NUM] = "The entire Pro Git book, written by Scott Chacon and Ben Straub and published by Apress, is available here. All content is licensed under the Creative Commons Attribution Non Commercial Share Alike 3.0 license. Print versions of the book are available on Amazon.com. ";
	char P[NUM] = "entire";
	int n,m;
    n = strlen(T);
    m = strlen(P); 

    KMP_match_my(T,P,n,m);
    //compute_prefix_function(P,m);

    // for(int i=0;i<m;i++){
    //     cout<<prefix[i+1]<<endl;
    // }
	return 0;
}