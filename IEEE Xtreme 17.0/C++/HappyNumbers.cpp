#include <iostream>
#include <unordered_set>
#include <cstdint>

int64_t get_next(int64_t n) {
    int64_t total_sum = 0;
    while (n > 0) {
        int64_t d = n % 10;
        n /= 10;
        total_sum += d * d;
    }
    return total_sum;
}

bool is_happy(int64_t n) {
    int64_t slow = n;
    int64_t fast = n;
    do {
        slow = get_next(slow);
        fast = get_next(get_next(fast));
    } while (slow != fast);

    return slow == 1;
}

int count_happy_numbers(int64_t start, int64_t end) {
    int count = 0;
    for (int64_t num = start; num <= end; ++num) {
        if (is_happy(num)) {
            count++;
        }
    }
    return count;
}

int main() {
    int64_t start, end;
    std::cin >> start >> end;
    std::cout << count_happy_numbers(start, end) << std::endl;
    return 0;
}
