#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;   
    cout << gcd(a, b); 
    return 0;
}

int gcd(int a, int b) {
    if(a == 0)
        return b;
    else
        return gcd(a % b, a);
}