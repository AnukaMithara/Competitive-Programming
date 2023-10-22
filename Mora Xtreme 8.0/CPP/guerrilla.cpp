#include<bits/stdc++.h>
using namespace std;

#define ll long long

pair<ll,ll> spy[250], camp[250];
ll dist[250];

bool check(ll mid, ll n, ll m, ll k) {
    ll cnt = 0;
    for(ll i=0; i<n; i++) {
        for(ll j=0; j<m; j++) {
            if(dist[j] <= mid) {
                cnt++;
                dist[j] = 1e18;
                break;
            }
        }
    }
    return (cnt >= k);
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    for(ll i=0; i<n; i++)
        cin >> spy[i].first >> spy[i].second;

    for(ll i=0; i<m; i++)
        cin >> camp[i].first >> camp[i].second;

    ll l = 0, r = 4e18;
    while(r - l > 1) {
        ll mid = (l + r) / 2;

        for(ll i=0; i<m; i++) {
            dist[i] = 1e18;
            for(ll j=0; j<n; j++) {
                ll d = (spy[j].first - camp[i].first)*(spy[j].first - camp[i].first) + (spy[j].second - camp[i].second)*(spy[j].second - camp[i].second);
                dist[i] = min(dist[i], d);
            }
        }

        sort(dist, dist+m);
        if(check(mid, n, m, k)) r = mid;
        else l = mid;
    }

    cout << r << "\n";
    return 0;
}
