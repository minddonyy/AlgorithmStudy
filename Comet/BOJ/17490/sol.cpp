using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

int num, construct;
long long stone;
int needs[1000001] = { 0 };
struct datas
{
	int start, end;
};
vector<datas> cant;
bool compare(const datas& a, const datas& b) {
	return a.start < b.start;
}
void solve() {
	cin >> num >> construct >> stone;
	if (construct < 2) { cout << "YES" << '\n'; return; }
	cant.resize(construct);
	for (int i = 1; i <= num; ++i) {
		cin >> needs[i];
	}
	int s, n;
	for (int i = 0; i < construct; ++i) {
		cin >> s >> n;
		if (s < n) {
			if (n == num && s == 1) {
				cant[i].start = n; cant[i].end = s;
			}
			else {
				cant[i].start = s; cant[i].end = n;
			}
		}
		else {
			if (s == num && n == 1) {
				cant[i].start = s; cant[i].end = n;
			}
			else {
				cant[i].start = n; cant[i].end = s;
			}
		}
	}
	sort(cant.begin(), cant.end(), compare);
	int idx = 0;


	vector<int> min_val(construct, 999999999);

	for (int i = 1; i <= num; ++i) {
		min_val[idx] = min(needs[i], min_val[idx]);
		//cout << idx << ' ' << i << "     ";
		if (idx != construct && cant[idx].start == i) {
			idx++;
			idx %= construct;
		}
	}
	for (int i = 0; i < construct; ++i) {
		stone -= min_val[i];
	}
	/*
	for (int i = 0; i < construct; ++i) {
		cout << min_val[i] << ' ';
	}
	*/
	

	if (stone < 0) {
		cout << "NO" << '\n';
	}
	else {
		cout << "YES" << '\n';
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}