#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Task {
  int score;
  int index;
};

bool operator<(const Task& a, const Task& b) {
  return a.score > b.score;
}

int main() {
  int N, K;
  cin >> N >> K;

  vector<Task> tasks(N);
  for (int i = 0; i < N; i++) {
    cin >> tasks[i].score;
    tasks[i].index = i;
  }

  sort(tasks.begin(), tasks.end());

  priority_queue<Task> pq;
  for (int i = 0; i < N; i++) {
    pq.push(tasks[i]);
  }

  vector<vector<int>> schedule;
  while (!pq.empty()) {
    vector<int> day;
    for (int i = 0; i < K && !pq.empty(); i++) {
      day.push_back(pq.top().index);
      pq.pop();
    }
    schedule.push_back(day);
  }

  int totalScore = 0;
  for (size_t  i = 0; i < schedule.size(); i++) {
    int maxScore = 0;
    for (size_t  j = 0; j < schedule[i].size(); j++) {
      maxScore = max(maxScore, tasks[schedule[i][j]].score);
    }
    totalScore += maxScore;
  }

  cout << totalScore << endl;

  return 0;
}


// You are assigned a series of tasks to complete over N days, with each task numbered from 1 to N and must be completed in this order. 

// You can accomplish a maximum of K tasks per day and aim to complete the tasks in the shortest time possible. While adhering to these constraints, you seek a schedule that ensures a balanced workload each day. More precisely, each task i is associated with a specific score a. For a given schedule, each day's score is determined by the maximum score of all the tasks completed on that day. 

// Finally, the scores of each day are summed to give the total score of the schedule. The objective is to find the maximum possible total score of the schedule while minimizing the number of days required to complete all the tasks

// Input Format
// The first line contains two space-separated integers N and K (1 ≤ K ≤ N ≤ 10⁶).
// The next line contains N space separated integers aᵢ (1 ≤ aᵢ ≤ 10⁹).

// Output Format
// Output a single integer, the maximum possible total score.

// Sample Input 0
// 5 3
// 2 5 7 1 4

// Sample Output 0
// 12
