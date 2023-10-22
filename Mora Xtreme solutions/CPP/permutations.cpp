#include<bits/stdc++.h>
using namespace std;
 
const long long N = 2e5+7;
int a[N];
bool b[N];
int n;
 
bool check(int m) {
    for (int i=1; i<2*n; i++)   b[i] = a[i] > m;
 
    int closest[2] = {N, N};
    for (int i=1; i<2*n; i++) {
        if (i > 1 && b[i] == b[i-1])              closest[b[i]] = min(closest[b[i]], abs(n-i));
        if (i + 1 < 2*n && b[i] == b[i+1])        closest[b[i]] = min(closest[b[i]], abs(n-i));
    }
 
    if (closest[0] == closest[1]) {
        assert(closest[0] == N);
        return (1-n%2)^b[n];
    }
    else if (closest[0] > closest[1])   return 1;
    else    return 0;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    cin>>n;
    for (int i=1; i<2*n; i++) cin>>a[i];
 
    int lo = 1, hi = 2*n-1;
    while (lo < hi) {
        int mid = (lo+hi)/2;
        if (check(mid))     lo = mid+1;
        else                hi = mid;
    }
    cout<<lo<<endl;
 
}