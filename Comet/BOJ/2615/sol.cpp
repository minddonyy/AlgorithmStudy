using namespace std;
#include <iostream>
#include <vector>
const int length = 18;
struct dataset {
	int y, x, color;
};
void print(dataset before) {
	cout << before.color << '\n' << before.y + 1 << ' ' << before.x + 1;
}
void solve() {
	int cnt; dataset before;
	vector<vector<int>> arr(length + 1, vector<int>(length + 1));
	for (int i = 0; i <= length; i++) {
		for (int j = 0; j <= length; j++) {
			cin >> arr[i][j];
		}
	}
	// °¡·Î Å½»ö
	for (int i = 0; i <= length; i++) {
		cnt = 0; before.color = arr[i][0]; before.y = i; before.x = length;
		for (int j = length; j >= 0; j--) {
			if (!arr[i][j]){
				if (cnt == 5) {
					print(before);
					return;
				}
				cnt = 0; before.color = arr[i][j]; before.y = i; before.x = j;
			}
			else if (arr[i][j] == before.color) {
				cnt++;
				before.y = i; before.x = j;
			}
			else {
				if (cnt == 5) {
					print(before);
					return;
				}
				cnt = 1; before.color = arr[i][j]; before.y = i; before.x = j;
			}
		}
		if (cnt == 5) {
			print(before);
			return;
		}
	}// ¼¼·Î Å½»ö
	for (int j = 0; j <= length; j++) {
		cnt = 0; before.color = arr[length][j]; before.y = length; before.x = j;
		for (int i = length; i >= 0; i--) {
			if (!arr[i][j]) {
				if (cnt == 5) {
					print(before);
					return;
				}
				cnt = 0; before.color = arr[i][j]; before.y = i; before.x = j;
			}
			else if (arr[i][j] == before.color) {
				cnt++;
				before.y = i; before.x = j;
			}
			else {
				if (cnt == 5) {
					print(before);
					return;
				}
				cnt = 1; before.color = arr[i][j]; before.y = i; before.x = j;
			}
		}
		if (cnt == 5) {
			print(before);
			return;
		}
	}
	// ¿ìÇÏÇâ Å½»ö
	for (int i = 0; i <= length - 4; i++) {
		cnt = 0; before.color = arr[length - i][length]; before.y = length - i; before.x = length;
		for (int j = length - i; j >= 0; j--) {
			if (!arr[j][j + i]) {
				if (cnt == 5) {
					print(before);
					return;
				}
				cnt = 0; before.color = arr[j][j + i]; before.y = j; before.x = j + i;
			}
			else if (arr[j][j + i] == before.color) {
				cnt++;
				before.y = j; before.x = j + i;
			}
			else {
				if (cnt == 5) {
					print(before);
					return;
				}
				cnt = 1; before.color = arr[j][j + i]; before.y = j; before.x = j + i;
			}
		}
		if (cnt == 5) {
			print(before);
			return;
		}
	}
	for (int i = 1; i <= length - 4; i++) {
		cnt = 0; before.color = arr[length][length - i]; before.y = length; before.x = length - i;
		for (int j = length; j >= i; j--) {
			
			if (!arr[j][j - i]) {
				if (cnt == 5) {

					print(before);
					return;
				}
				cnt = 0; before.color = arr[j][j - i]; before.y = j; before.x = j - i;
			}
			else if (arr[j][j - i] == before.color) {
				cnt++;
				before.y = j; before.x = j - i;
			}
			else {
				if (cnt == 5) {
					print(before);
					return;
				}
				cnt = 1; before.color = arr[j][j - i]; before.y = j; before.x = j - i;
			}
		}
		if (cnt == 5) {
			print(before);
			return;
		}
	}
	// ÁÂÇÏÇâ Å½»ö
	for (int i = 4; i <= length; i++) {
		cnt = 0; before.color = arr[i][0]; before.y = i; before.x = 0;
		for (int j = 0; j <= i; j++) {
			if (!arr[i - j][j]) {
				if (cnt == 5) {
					print(before);
					return;
				}
				cnt = 0; before.color = arr[i - j][j]; before.y = i - j; before.x = j;
			}
			else if (arr[i - j][j] == before.color) {
				cnt++;
		
			}
			else {
				if (cnt == 5) {
					print(before);
					return;
				}
				cnt = 1; before.color = arr[i - j][j]; before.y = i - j; before.x = j;
			}
		}
		if (cnt == 5) {
			print(before);
			return;
		}
	}
	for (int i = 1; i <= length - 4; i++) {
		cnt = 0; before.color = arr[length][i]; before.y = length; before.x = i;
		for (int j = length; j >= i; j--) {
			if (!arr[j][length - j + i]) {
				if (cnt == 5) {
					print(before);
					return;
				}
				cnt = 0; before.color = arr[j][length - j + i]; before.y = j; before.x = length - j + i;
			}
			else if (arr[j][length - j + i] == before.color) {
				cnt++;

			}
			else {
				if (cnt == 5) {
					print(before);
					return;
				}
				cnt = 1; before.color = arr[j][length - j + i]; before.y = j; before.x = length - j + i;
			}
		}
		if (cnt == 5) {
			print(before);
			return;
		}
	}
	cout << 0 << '\n';
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}