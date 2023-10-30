#include <iostream>
#include <queue>
#include <map>
#include <sstream>

using namespace std;

int main() {
    map<char, int> card_values = {{'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}, {'A', 14}};
    int n;
    cin >> n;
    while(n--) {
        queue<int> player1_cards, player2_cards;
        string line, card;

        getline(cin, line);
        stringstream ss(line);
        while(ss >> card) {
            player1_cards.push(card_values[card[0]]);
        }
        
        getline(cin, line);
        stringstream ss2(line);
        while(ss2 >> card) {
            player2_cards.push(card_values[card[0]]);
        
        while(!player1_cards.empty()){
        cout<<" "<<player1_cards.front();
        player1_cards.pop();
        }
        cout<<endl;
        while(!player2_cards.empty()){
		cout<<" "<<player2_cards.front();
		player2_cards.pop();
	    }
        

      while(!player1_cards.empty() && !player2_cards.empty()) {
            int card1 = player1_cards.front();
            player1_cards.pop();
            int card2 = player2_cards.front();
            player2_cards.pop();

            if(card1 > card2) {
                player1_cards.push(card2);
            } else if(card2 > card1) {
                player2_cards.push(card1);
            } else {
                player1_cards.push(card1);
                player2_cards.push(card2);
            }
        }

        if(player1_cards.empty()) {
            cout << "player 2" << endl;
        } else if(player2_cards.empty()) {
            cout << "player 1" << endl;
        } else {
            cout << "draw" << endl;
        }
    }
    return 0;
}
