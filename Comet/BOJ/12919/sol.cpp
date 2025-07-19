using namespace std;
#include <iostream>
#include <string>
#include <algorithm>


string arr;
string tar;
bool result = 0;


void dfs(string st) {

	if (arr.size() == st.size()) {
		int size = st.size();
		for (int i = 0; i < size; ++i) {
			if (st[i] != arr[i]) {
				return;
			}
		}
		result = 1;
		return;
	}
	string temp = st;
	if (temp.back() == 'A') {
		temp.pop_back();
		dfs(temp);

	}
	temp = st;
	if (temp.front() == 'B') {
		reverse(temp.begin(), temp.end());
		temp.pop_back();
		dfs(temp);

	}
}
int main() {
	cin >> arr >> tar;
	dfs(tar);
	cout << result << '\n';
	return 0;
}