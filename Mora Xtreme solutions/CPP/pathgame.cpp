#include <bits/stdc++.h>
using namespace std;
int N,M;


vector<int> solve(){
    cin>>N>>M;
    char s[N+2];
    vector<int> prev(N+1,-1);
    cin>>s;
    vector<int> nn;
    nn.push_back(-1);
    if(s[0]=='1') return nn;
    if(s[N]=='1') return nn;
    prev[0] = 0;
    int a = 0;
    for(int j = 1; j<=N;j++){
        if(s[j]=='1') continue;
        int st = j-a;
        if(st>M){
            int found = 0;
            for(int q = j-M;q<j;q++){
                if(s[q]=='0'){
                    a = q;
                    found = 1;
                    break;
                }
            }
            if(!found){
                return nn;
            }
        }
        prev[j] = a;
    }
    vector<int> numbers;
    int sta = N;
    while(sta!=0){
        numbers.push_back(sta-prev[sta]);
        sta = prev[sta];
    }

    return numbers;

}
int main(){
   vector<int> x = solve();
   for(int j = x.size()-1;j>=0;j--){
        cout<<x[j]<<" ";
   }
    
}