#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T,N,V;
    cin>>T;
    
    for(int t=0;t<T;t++){
        cin>>N>>V;
        
        int vEdges=0;
        for(int i=0;i<N-1;i++){
            int n1,n2; cin>>n1>>n2;
            if(n1==V || n2==V)  vEdges++;
        }
        if(vEdges ==1) cout<<"Hitland"<<endl;
        else cout<< (N%2==0? "Hitland":"Stalind")<<endl;
    
    }    
    return 0;
}
