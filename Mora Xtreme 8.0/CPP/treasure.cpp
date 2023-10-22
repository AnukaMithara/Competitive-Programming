#include <iostream>
#include<bits/stdc++.h>
#include <vector>
#include <cmath>
using namespace std;

int find_nth_ast(int n, int prime)
{
    int limit = 100000;
    while(true) {
        vector<bool> prime_vec(limit+1, true);
        prime_vec[0] = prime_vec[1] = false;
        for (int p=2; p*p<=limit; p++) {
            if (prime_vec[p] == true) {
                for (int i=p*p; i<=limit; i += p)
                    prime_vec[i] = false;
            }
        }
        vector<int> primes;
        for(int i=2; i<=limit; i++) {
            if(prime_vec[i])
                primes.push_back(i);
        }
        auto it = lower_bound(primes.begin(), primes.end(), prime);
        if(distance(it, primes.end()) >= n) {
            int val = *(it+n-1);
            return val * prime;
        }
        limit *= 2;
    }
}

int main()
{
    int n, prime;
    cin >> n >> prime;
    cout << find_nth_ast(n-1, prime) << endl;
    return 0;
}
