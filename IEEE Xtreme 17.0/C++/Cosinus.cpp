#include <iostream>
#include <cmath>
#include <climits>

#define PI 3.14159265

int main() {
    int T;
    std::cin >> T;
    while(T--) {

        float a;
        std::cin >> a;
        a = a * PI / 180.0; // convert to radians
        
        double min_val = INT_MAX;
        int min_n = 1;


        for(int n = 1; n <= 360; ++n) {
            double val = std::abs(std::cos(n * a));
            if(val < min_val) {
                min_val = val;
                min_n = n;
            }
        }
        std::cout << min_n << std::endl;
    }
    return 0;
}
