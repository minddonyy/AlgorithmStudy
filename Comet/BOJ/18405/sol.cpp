using namespace std;
#include <iostream>
#include <vector>
#include <unordered_map>
struct yx
{
	int y, x;
};
int length, num;

int sec, targety, targetx;
unordered_map<int, vector<yx>> dict;

int time, tempy, tempx;
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };
yx cur;


void delta(vector<vector<int>>& arr, vector<yx>& vec,int val) {
	vector<yx> memo;

	int len = vec.size();
	for (int i = 0; i < len; i++) {
		cur = vec[i];
		for (int j = 0; j < 4; j++) {
			tempy = cur.y + dy[j]; tempx = cur.x + dx[j];
			if (tempy >= 0 && tempy < length && tempx >= 0 && tempx < length && arr[tempy][tempx] == 0) {
				memo.push_back({ tempy, tempx });
				arr[tempy][tempx] = val;
			}
		}
	}
	vec = memo;
}
void solve() {
	
	cin >> length >> num;
	vector<vector<int>> arr(length, vector<int>(length));
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			cin >> arr[i][j];
			if (arr[i][j]) {
				dict[arr[i][j]].push_back({ i, j });
			}
		}
	}
	cin >> sec >> targety >> targetx;
	while (time < sec)
	{
		time++;
		for (int i = 1; i <= num; i++) {
			delta(arr, dict[i], i);
		}
	}
	
	//for (int i = 0; i < length; i++) {
	//	for (int j = 0; j < length; j++) {
	//		cout << arr[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}
	cout << arr[targety - 1][targetx - 1] << '\n';
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}