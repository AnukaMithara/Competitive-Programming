#include <iostream>

using namespace std;


int gcd(int a, int b) {
    if(b == 0)
        return a;
    else
        return gcd(b, a%b);
}

int main() {
    int a, b;
    cin >> a >> b;   
    cout << gcd(a, b); 
    return 0;
}

// Both ways are correct, but Euclidean algorithm is more efficient

/*
#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    
    int min = a < b ? a : b;

    for (int i = min; i >= 1; i--) {
        if (a % i == 0 && b % i == 0) {
            cout << i;
            break;
        }
    }    
    return 0;
}
*/