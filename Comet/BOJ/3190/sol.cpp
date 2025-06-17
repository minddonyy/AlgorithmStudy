using namespace std;
#include <iostream>
#include <vector>
#include <queue>
const int apple = 1;
const int snake = 2;
int result = 0;
int length, num_apple, apple_y, apple_x, num_command, c_time, c_rotate, y = 0, x = 0;
int tempy, tempx, pointer = 0;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
int turn_left[4] = { 3, 0, 1, 2 };
int turn_right[4] = { 1, 2, 3, 0 };
int direc = 0;
void solve() {
	cin >> length >> num_apple;
	vector<vector<int>> board(length, vector<int>(length, 0));
	queue<pair<int, int>> que;
	
	que.push(make_pair(y, x));
	board[0][0] = snake;
	pair<int, int> cur;
	for (int i = 0; i < num_apple; i++) {
		cin >> apple_y >> apple_x; board[apple_y - 1][apple_x - 1] = apple;
	}
	cin >> num_command;
	vector<pair<int, char>> commands(num_command, { 0, ' ' });
	for (int i = 0; i < num_command; i++) {
		cin >> commands[i].first >> commands[i].second;
	}
	while (true)
	{	
		result++;
		cur = que.back();
		tempy = cur.first + dy[direc];
		tempx = cur.second + dx[direc];
		if (tempy >= 0 && tempy < length && tempx >= 0 && tempx < length && (board[tempy][tempx] == 0 || board[tempy][tempx] == apple)) {
			que.push(make_pair(tempy, tempx));
			
			if (board[tempy][tempx] != apple) {
				cur = que.front(); que.pop();
				board[cur.first][cur.second] = 0;
			}
			board[tempy][tempx] = snake;
		}
		else {
			break;
		}
		if (pointer < num_command && commands[pointer].first == result) {
			if (commands[pointer].second == 'L') {
				direc = turn_left[direc];
			}
			else
			{
				direc = turn_right[direc];
			}
			pointer++;
		}
	}

	return;
}

int main() {
	solve();
	cout << result << '\n';
	return 0;
}
