#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int countSteps(long long n){
    
    if(n==1) return 0;
    
    if(n%2==0) return countSteps(n/2)+1;
    return countSteps(3*n+1)+1;
    
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int t;
    long long a,b;
    cin>>t;
    
    for(int i=0;i<t;i++){
        cin>>a>>b;
        
        int aCount = countSteps(a);
        int bCount = countSteps(b);
        
        if(aCount<bCount) cout<<"Kapila"<<endl;
        if(aCount>bCount) cout<<"Kalpa"<<endl;
        if(aCount==bCount) cout<<"-"<<endl;
    }
    
    
    return 0;
}
