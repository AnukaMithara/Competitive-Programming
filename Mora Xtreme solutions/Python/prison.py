
from collections import defaultdict

def compute(N, F, visited, longest_len_from_prisoner, first_prisoner_in_a_circle_from_prisoner):
    for i in xrange(N):
        if i not in visited:
            cur, length = i, 0
            while cur not in visited:
                length += 1
                visited.add(cur)
                cur = F[cur]

            visited_prisoner = cur
            is_visited_prisoner_uninitiated = (longest_len_from_prisoner[visited_prisoner] == 0)
            if is_visited_prisoner_uninitiated:  
                first_prisoner_in_a_circle_from_prisoner[visited_prisoner] = visited_prisoner

            cur, is_before_the_circle = i, True
            while (is_visited_prisoner_uninitiated and is_before_the_circle) or \
                  cur != visited_prisoner:
              
                if cur == visited_prisoner:
                    is_before_the_circle = False
               
                if is_before_the_circle:
                    first_prisoner_in_a_circle_from_prisoner[cur] = \
                                    first_prisoner_in_a_circle_from_prisoner[visited_prisoner]
                    longest_len_from_prisoner[cur] = \
                                    length + longest_len_from_prisoner[visited_prisoner]
                    length -= 1
                else: 
                    first_prisoner_in_a_circle_from_prisoner[cur] = cur
                    longest_len_from_prisoner[cur] = length
                cur = F[cur]


def compute2(N, F, visited, longest_len_from_prisoner, first_prisoner_in_a_circle_from_prisoner):
    for i in xrange(N):
        visited = set()
        cur, length = i, 0
        while cur not in visited:
            length += 1
            visited.add(cur)
            cur = F[cur]
        longest_len_from_prisoner[i], first_prisoner_in_a_circle_from_prisoner[i] = length, cur


def calc():
    N = input()
    F = map(lambda c: int(c) - 1, raw_input().strip().split())

    longest_len_from_prisoner = [0] * N

    first_prisoner_in_a_circle_from_prisoner = [0] * N

    visited = set()
    compute(N, F, visited, longest_len_from_prisoner, first_prisoner_in_a_circle_from_prisoner)

    longest_len_to_first_prisoner_in_a_circle = defaultdict(int)
    for i in xrange(N):
        cur = first_prisoner_in_a_circle_from_prisoner[i]
        longest_len_to_first_prisoner_in_a_circle[cur] = \
            max(longest_len_to_first_prisoner_in_a_circle[cur], \
                longest_len_from_prisoner[i] - longest_len_from_prisoner[cur] + 1)

    chains, circle = 0, 0
    visited = set()
    for i in xrange(N):

        if i not in visited and first_prisoner_in_a_circle_from_prisoner[i] == i:
            lens, cur = [], i
            while cur not in visited:
                visited.add(cur)
                lens.append(longest_len_to_first_prisoner_in_a_circle[cur])
                cur = F[cur]

            if len(lens) == 2:
                chains += lens[0] + lens[1]

            circle = max(circle, len(lens))

    return max(chains, circle)


for case in xrange(input()):
    print calc()