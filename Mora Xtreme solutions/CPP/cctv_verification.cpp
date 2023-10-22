#include<bits/stdc++.h>
using namespace std;


 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T,H,W;
    cin>>T>>H>>W;
    for(int cases = 0;cases<T;cases++){
        int N,R;
        cin>>N>>R;
        vector<int> xs(N);
        for(int j =0;j<N;j++){
            cin>>xs[j];
        }
        vector<int> ys(N);
        for(int j=0;j<N;j++){
            cin>>ys[j];
        }
        vector<vector<int> > conn(N+2);
        for(int j =0;j<N;j++){
            if(abs(xs[j])<=R){
                conn[j].push_back(N);
                conn[N].push_back(j);
            }
            if(abs(xs[j]-W)<=R){
                conn[j].push_back(N+1);
                conn[N+1].push_back(j);

            }
            for(int i =0;i<j;i++){
                long long a1 = ((1LL*(xs[i]-xs[j]))*(xs[i]-xs[j]))+((1LL*(ys[i]-ys[j]))*(ys[i]-ys[j]));
                long long b1 = (1LL*R)*R*4;
                if(a1<=b1){
                    
                    conn[j].push_back(i);
                    conn[i].push_back(j);
                }
                
            }
        }
        int current = N;
        queue<int> q;
        q.push(current);
        vector<int> visited(N+2,0);
        visited[current] =1;
//        for(int j =0;j<N+2;j++){
//            for(int i =0;i<conn[j].size();i++){
//                cout<<conn[j][i]<<' ';
//            }
//            cout<<'\n';
//        }
        int flg = 0;
        while(!q.empty()){
            current = q.front();
            q.pop();
            for(int j = 0;j<conn[current].size();j++){
                int p = conn[current][j];
                if(!visited[p]){
                    if(p==N+1){
                        flg = 1;
                        break;
                    }
                    visited[p] = 1;
                    q.push(p);
                    
                }
            }
            if(flg) break;
            
        }
        if(flg){
            cout<<"CAN'T"<<'\n';
        }
        else{
            cout<<"CAN"<<'\n';
        }
    }
    
 
}