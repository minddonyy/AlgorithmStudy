using namespace std;
#include <iostream>
#include <vector>

int row, col;
int box[1000][1000];
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };
struct yx
{
	int y, x;
};
vector<yx> tomatos;

bool find() {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (box[i][j] == 0) {
				return 0;
			}
		}
	}
	return 1;
}
int main() {
	cin >> col >> row;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cin >> box[i][j];
			if (box[i][j] == 1) {
				tomatos.push_back({ i, j });
			}
		}
	}
	int tempy, tempx, cnt = 0;
	while (!tomatos.empty())
	{
		vector<yx> newtomatos;
		for (const auto& tomato : tomatos) {
			for (int i = 0; i < 4; ++i) {
				tempy = tomato.y + dy[i]; tempx = tomato.x + dx[i];
				if (tempy < 0 || tempy >= row || tempx < 0 || tempx >= col || box[tempy][tempx] != 0) continue;
				newtomatos.push_back({ tempy, tempx });
				box[tempy][tempx] = 1;
			}
		}
		swap(tomatos, newtomatos);
		cnt++;
	}
	if (find()) {
		cout << cnt - 1 << '\n';
	}
	else {
		cout << -1 << '\n';
	}
	return 0;
}