def count_occurrences(message):
    message = message.lower()  
    counts = {'a': 0, 'b': 0, 'c': 0, 'd': 0, 'e': 0, 'f': 0, 'g': 0}    
    for char in message:
        if char in counts:
            counts[char] += 1    
    max_letter = max(counts, key=counts.get)
    return max_letter.upper()  
n = int(input())
for _ in range(n):
    message = input()
    max_recipe = count_occurrences(message)
    print(max_recipe)
