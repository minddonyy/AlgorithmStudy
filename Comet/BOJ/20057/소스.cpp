using namespace std;
#include <iostream>
#include <vector>
int length;
int arr[500][500];
int result = 0;
struct dydx
{
	int dy, dx, div;
};
vector<vector<dydx>> dyx = {
	{{-1, -1, 10}, {1, -1, 10}, {-1, 0, 7}, {1, 0, 7}, {-1, 1, 1}, {1, 1, 1}, {-2, 0, 2}, {2, 0, 2}, {0, -2, 5}, {0, -1, 0} },
	{{1, 1, 10}, {1, -1, 10}, {0, -1, 7}, {0, 1, 7}, {-1, -1, 1}, {-1, 1, 1}, {0, -2, 2}, {0, 2, 2}, {2, 0, 5}, {1, 0, 0} },
	{{-1, -1, 1}, {1, -1, 1}, {-1, 0, 7}, {1, 0, 7}, {-1, 1, 10}, {1, 1, 10}, {-2, 0, 2}, {2, 0, 2}, {0, 2, 5}, {0, 1, 0} },
	{{1, 1, 1}, {1, -1, 1}, {0, -1, 7}, {0, 1, 7}, {-1, -1, 10}, {-1, 1, 10}, {0, -2, 2}, {0, 2, 2}, {-2, 0, 5}, {-1, 0, 0} },
};
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };
void move(int y, int x, int direc) {
	if (arr[y][x] == 0) return;
	int tempy, tempx, sand = arr[y][x], tempsand;
	for (auto& loc : dyx[direc]) {
		if (loc.div == 0) break;
		tempy = y + loc.dy; tempx = x + loc.dx; tempsand = (arr[y][x] * loc.div) / 100;
		sand -= tempsand;
		if (tempy < 0 || tempy >= length || tempx < 0 || tempx >= length) {
			result += tempsand;
			continue;
		}
		arr[tempy][tempx] += tempsand;
	}
	tempy = y + dyx[direc][9].dy; tempx = x + dyx[direc][9].dx;
	if (tempy < 0 || tempy >= length || tempx < 0 || tempx >= length) {
		result += sand;
	}
	else {
		arr[tempy][tempx] += sand;
	}
	arr[y][x] = 0;
}
//void print() {
//	for (int i = 0; i < length; ++i) {
//		for (int j = 0; j < length; ++j) {
//			cout << arr[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//	cout << result << '\n';
//	cout << '\n';
//}
void solve() {
	int y = length / 2, x = length / 2, direc = -1;
	int leng = 1;
	while (true)
	{

		for (int i = 0; i < 2; ++i) {
			++direc; direc %= 4;
			for (int j = 0; j < leng; ++j) {
				y += dy[direc]; x += dx[direc];
				
				move(y, x, direc);
				if (y == 0 && x == 0) return;
				//print();
			}
		}
		leng++;
	}
}
int main() {
	cin >> length;
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			cin >> arr[i][j];
		}
	}
	//print();
	solve();
	cout << result << '\n';
	return 0;
}