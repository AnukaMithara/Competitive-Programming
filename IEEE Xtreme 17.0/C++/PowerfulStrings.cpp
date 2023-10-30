#include <iostream>
#include <string>
#include <unordered_map>

const long long MOD = 998244353;

long long power(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    int N, M;
    std::cin >> N >> M;
    std::unordered_map<std::string, int> occurrences;

    for (int i = 0; i < M; ++i) {
        std::string s;
        std::cin >> s;
        occurrences[s]++;
    }

    long long total_power = 0;

    for (const auto &occurrence : occurrences) {
        long long count = occurrence.second;
        long long string_power = power(2, count);
        total_power = (total_power + string_power) % MOD;
    }

    long long result = power(total_power, N);
    std::cout << result << std::endl;

    return 0;
}

/* \
You are given an integer N and M strings  S(i) ​ with lowercase, English letters. Consider a string of length N with lowercase, English letters. The power of that string is computed as 2^k where k is the total number of occurrences of strings from S. For example let M=2, S 1 ​ = ab and S 2 ​ = c. The power of ababccca is equal 2^5 = 32 because S (1) ​ occurs twice and S (2) ​ occurs three times. Your task is to calculate the sum of powers of all strings of lengthN modulo 998244353. 

Constraints and notes
1≤N≤10^18
1≤M≤100,
for all 1≤i≤M, the length of S(i) is not greater than 20

give me the optimized pyhton code for above senario according to user inputs

Sample input: 
3 2
ab
ba

Sample Output:
17682

Explanation: In the first example there are two strings aba and bab with power 4, exactly100 strings with power 2 and 17474 strings with power 1.
*/
