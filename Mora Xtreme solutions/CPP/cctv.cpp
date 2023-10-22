#include<iostream>
#include <fstream>
#include <vector>

using namespace std;
#define MAXN 1005

long long X[MAXN],Y[MAXN],N,R,W,H;
vector <int> adj[MAXN];
int ff[MAXN];// flood fill

bool isConnected(int i,int j){

    if(i>1 && j>1) // both are circles
        return (X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]) <= 4*R*R;

    if((i==0 && j==1)||(i==1 && j==0)) // left and right walls
        return false;
    if(i==0)
        return X[j]<=R;
    if(j==0)
        return X[i]<=R;
    if(i==1)
        return X[j]+R>=W;
    if(j==1)
        return X[i]+R>=W;

    return false;

}
void make_adjList(){

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(isConnected(i,j)){
                adj[i].push_back(j);
              //  cout<<i<<" and "<<j<<" are conected"<<endl;
            }

}

void flood_fill(int x){

    ff[x]=5;
    for(auto u:adj[x]){
        if(ff[u]!=5) flood_fill(u);
    }
}

int main(){

    int T;
    cin>>T;cin>>H>>W;


    for(int i=0;i<T;i++){
        cin>>N>>R;
        N+=2; // 0 left wall 1- right wall

        for(int j=0;j<N;j++){ adj[j].clear(); ff[j]=0;}

        for(int j=2;j<N;j++) cin>>X[j];
        for(int j=2;j<N;j++) cin>>Y[j];

        make_adjList();

        flood_fill(0);

        if(ff[1]==5){ cout<<"CAN'T"<<endl;}
        else { cout<<"CAN"<<endl;}
    }
    return 0;
}
