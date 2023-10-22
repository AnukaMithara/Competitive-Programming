def smallest_prime_factor(n):

  divisor = 2
  while divisor <= n ** 0.5:
    if n % divisor == 0:
      return divisor
    divisor += 1
  return n

def ast(coin, prime):

  return coin // smallest_prime_factor(coin)

def nth_coin(n, prime):

  return n * smallest_prime_factor(prime)

def challenge(n, prime):

  coin_value = nth_coin(n, prime)
  ast_value = ast(coin_value, prime)

  if ast_value > 109:
    return "zero"
  else:
    return ast_value

n, prime = map(int, input().split())
print(challenge(n, prime))
