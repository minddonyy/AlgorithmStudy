using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
int ans_num, num;
vector<char> alpha;
vector<char> fin = { 'a', 'e', 'i', 'o', 'u' };
void dfs(vector<char>& arr, int cnt, int idx) {
	if (cnt == ans_num) {
		int many = 0;
		for (auto& c : arr) {
			for (auto& f : fin) {
				if (c == f) {
					many++;
					break;
				}
			}
		}
		if (many == 0 || (arr.size() - many) < 2) {
			return;
		}



		for (auto& c : arr) {
			cout << c;
		}
		cout << '\n';
		return;
	}
	if (idx == num) {
		return;
	}
	arr.push_back(alpha[idx]);
	dfs(arr, cnt + 1, idx + 1);
	arr.pop_back();
	dfs(arr, cnt, idx + 1);
}



int main() {
	cin >> ans_num >> num;
	char input;
	for (int i = 0; i < num; ++i) {
		cin >> input;
		alpha.push_back(input);
	}
	sort(alpha.begin(), alpha.end());
	vector<char> arr;
	dfs(arr, 0, 0);
	return 0;
}

