MOD = 998244353

def power_sum(N, M, strings):
    total_power = 0
    for i in range(1 << (N * 2)):
        current_string = ''.join(chr((i >> (2 * j)) & 3) + 'a' for j in range(N))
        power = 1
        for string in strings:
            count = 0
            for j in range(N - len(string) + 1):
                if current_string[j:j+len(string)] == string:
                    count += 1
            power = (power * pow(2, count, MOD)) % MOD
        total_power = (total_power + power) % MOD
    return total_power

N, M = map(int, input().split())
strings = [input().strip() for _ in range(M)]

print(power_sum(N, M, strings))
