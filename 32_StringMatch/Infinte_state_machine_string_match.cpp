#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;
#define NUM_N 1000
#define NUM_M 100

#define NUM_CHAR 95
//0x20 ~ 0x7e 
char character_set[NUM_CHAR+1]=" !\"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";

// #define NUM_CHAR 3
// char character_set[NUM_CHAR+1]="abc";

int transfer[NUM_M+1][NUM_CHAR];

void compute_prefix_function(char *P,int m,int *prefix){
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

void compute_transfer_function(char *P,int m){
    int * prefix = new int[m+1];
    compute_prefix_function(P,m,prefix);

    for(int q=0;q<=m;q++){
        for(int i=0;i<NUM_CHAR;i++){
            int k=q;
            while(k!=0 && P[k+1-1]!=character_set[i]){
                k=prefix[k];
            }

            // if(q==0){
            //     cout<<"i: "<<i<<endl;
            //     cout<<"k: "<<k<<endl;
            //     cout<<"P[k+1]: "<<P[k+1]<<"\n"<<"character_set[i]: "<<character_set[i]<<endl;
            // }

            if(P[k+1-1]==character_set[i]){
                k=k+1;
            }

            transfer[q][i]=k;
        }
    }
}

void print_transfer_matrix(char *P,int m){
    //first line
    cout<<"  ";
    for(int i=0;i<NUM_CHAR;i++){
        cout<<character_set[i]<<" ";
    }
    cout<<endl;

    for(int q=0;q<=m;q++){
        //left 
        if(q==0){
            cout<<"  ";
        }
        else{
            cout<<P[q-1]<<" ";
        }
        //body
        for(int i=0;i<NUM_CHAR;i++){
            cout<<transfer[q][i]<<" ";
        }
        cout<<endl;
    }
}

void infite_state_machine(char *T,char *P,int n,int m){
    int state = 0;
    for(int i=0;i<n;i++){
        state = transfer[state][int(T[i]-character_set[0])];
        if(state == m){
            cout<<"s occupy at: "<<i+1-m<<endl;
            //cout<<"i: "<<i<<endl;
        }
    }
}

int main(){
	char T[NUM_N] = "entire Pro Git book, written by Scott Chacon and Ben Straub and published by Apress, is available here. All content is licensed under the Creative Commons Attribution Non Commercial Share Alike 3.0 license. Print versions of the book are available on Amazon.com. ";
	char P[NUM_M] = "entire ";
    // char T[NUM_N] = "ababac";
	// char P[NUM_M] = "aba";
	int n,m;
    n = strlen(T);
    m = strlen(P); 

    compute_transfer_function(P,m);
    print_transfer_matrix(P,m);

    infite_state_machine(T,P,n,m);

	return 0;
}