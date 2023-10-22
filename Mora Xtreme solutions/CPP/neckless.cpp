#include <iostream>
#include <fstream>

using namespace std;
int n,m;
int removing[100000+2];
string colSeq;
string original;

bool isValid(int k){

    int subI =0; // mapping indices of array to colSeq
    for(int i=0;i<n;i++){
       // cout<<removing[i]<<" < ?"<<k<<endl;
        if(removing[i]<=k)
            continue;
        if(colSeq[subI]==original[i]) subI++;
        if(subI>=m) return true;
    }
   //out<< subI<<colSeq<<endl;
    return false;
}

int binSearch(){

    int a = 0, b = n-1;
    while (a <= b) {
        int k = (a+b)/2;
        if (!isValid(k)) b = k-1;
        else a = k+1;
        //cout<<isValid(k)<<"is valid "<<k<<endl;
    }

    return b;
}
int main(){

    cin>>original;
    cin>>colSeq;

    n=original.length();
    m=colSeq.length();

    for(int i=0;i<n;i++){
        int a; cin>>a;
        removing[a-1]=i;
    }
  //  for(int i=0;i<=n-1;i++)
     //   cout<<isValid(i)<<endl;
    cout<<binSearch()+1<<endl;

    return 0;
}