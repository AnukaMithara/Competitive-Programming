from collections import deque

def game_of_war():
    card_values = {str(i): i for i in range(2, 10)}
    card_values.update({'T': 10, 'J': 11, 'Q': 12, 'K': 13, 'A': 14})

    n = int(input().strip())
    for _ in range(n):
        player1 = deque(input().strip().split())
        player2 = deque(input().strip().split())
        history = set()

        while player1 and player2:
            state = (tuple(player1), tuple(player2))
            if state in history:
                print('draw')
                break
            history.add(state)

            card1 = player1.popleft()
            card2 = player2.popleft()

            if card_values[card1] > card_values[card2]:
                player1.append(card2)
            elif card_values[card1] < card_values[card2]:
                player2.append(card1)
            else:
                player1.append(card1)
                player2.append(card2)
        else:
            print('player 2' if not player1 else 'player 1')

game_of_war()


#Got all points