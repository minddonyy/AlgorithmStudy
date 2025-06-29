#include <iostream>
#include <string>
#include <map>
using namespace std;
/*
알파벳 소문자로 구성된 문자열 X, Y, Z가 주어진다
각 문자열에는 중복된 문자가 존재하지 않는다
문자열 S에 있는 문자 중 임의로 k개를 선택하여 문자열 S에서의 순서를 유지하여 만든 모든 부분 문자열을 모아놓은 집합을
문자열 S에 대한 조합 C(S, k)라고 하자
C(X, k), C(Y, k), C(Z, k)에 두번 이상 나타나는 부분 문자열을 오름차순으로 출력하자
*/
int k;
map<string, int> um;

void dfs(int idx, const string& s, string res, int n) {
	if (res.length() == k) {
		if (um.find(res) == um.end()) {
			um.insert({ res, 1 });
		}
		else {
			um[res]++;
		}
		return;
	}
	for (int i = idx; i < n; i++) {
		dfs(i + 1, s, res + s[i], n);
	}
	return;
}

void solve() {
	string X, Y, Z;
	getline(cin, X);
	getline(cin, Y);
	getline(cin, Z);
	cin >> k;
	dfs(0, X, "", X.size());
	dfs(0, Y, "", Y.size());
	dfs(0, Z, "", Z.size());
	int cnt = 0;
	for (const auto& elem : um) {
		if (um[elem.first] > 1) {
			cout << elem.first << "\n";
			cnt++;
		}
		//cout << elem.first << ": " << elem.second << "\n";
	}
	if (cnt == 0) cout << -1 << '\n';
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);

	solve();
	return 0;
}