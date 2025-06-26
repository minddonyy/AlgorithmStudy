using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>

vector<string> arr;
int row, col;
const char target = 'E';
const char tera = 'T';
const char hole = 'H';
const char rock = 'R';
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };
struct yx
{
	int y, x, time;
};
struct compare {
	bool operator()(const yx& a, const yx& b) {
		return a.time > b.time;
	}
};
yx startPoint, endPoint;
//시작점 끝점 찾기
void find_start() {
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (arr[i][j] == tera) {
				startPoint = { i, j, 0 };
			}
			else if (arr[i][j] == target) {
				endPoint = { i, j, 0 };
			}
		}
	}
}

//다익스트라
int dijk(yx& start, yx& end) {
	vector<vector<int>> dist(row, vector<int>(col, INT_MAX));
	priority_queue<yx, vector<yx>, compare> dq; dq.push({ start.y, start.x, 0 });
	dist[start.y][start.x] = 0;
	yx cur;
	int tempy, tempx, val;
	while (!dq.empty())
	{
		cur = dq.top(); dq.pop();
		
		for (int i = 0; i < 4; ++i) {
			tempy = cur.y, tempx = cur.x; val = dist[cur.y][cur.x];
			while (true)
			{
				tempy += dy[i]; tempx += dx[i];
				if (tempy < 0 || tempy >= row || tempx < 0 || tempx >= col) break;
				if (arr[tempy][tempx] == target) {
					if (dist[tempy][tempx] > val) {
						dist[tempy][tempx] = val;
					}
					break;
				}
				else if (arr[tempy][tempx] == hole) {
					break;
				}
				else if (arr[tempy][tempx] == rock) {
					if (dist[tempy - dy[i]][tempx - dx[i]] > val) {
						dist[tempy - dy[i]][tempx - dx[i]] = val;
						dq.push({ tempy - dy[i], tempx - dx[i], val });
					}
					break;
				}
				else {
					val += arr[tempy][tempx] - '0';
				}
			}
		}

	}
	
	if (dist[endPoint.y][endPoint.x] == INT_MAX) {
		return -1;
	}
	return dist[endPoint.y][endPoint.x];
}

int main() {
	cin >> col >> row;
	arr.resize(row);
	// 입력받기
	int result;
	for (int i = 0; i < row; ++i)
	{
		cin >> arr[i];
	}
	// 시작 지점 찾기.
	find_start();
	//탐색 시작.
	arr[startPoint.y][startPoint.x] = '0';

	result = dijk(startPoint, endPoint);
	cout << result << '\n';
	return 0;
}