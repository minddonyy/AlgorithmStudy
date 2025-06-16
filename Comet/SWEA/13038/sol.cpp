using namespace std;
#include <iostream>
#include <vector>
#include <numeric>
void solve() {
	int day, result = 0; cin >> day;
	int week[7]; int temp;
	for (int i = 0; i < 7; i++) cin >> week[i];
	int study_week = accumulate(week, week + 7, 0);
	int answer = 9999999;
	for (int change = 0; change < 7; change++)
	{

		if (week[0] == 1) {
			if (day % study_week == 0) {
				result = (day / study_week) * 7;
				for (int i = 0; i < 7; i++) {
					if (week[6 - i]) {
						result -= i;
						break;
					}
				}
			}
			else {
				result = (day / study_week) * 7;
				int remain = day % study_week, cnt = 0;
				for (int i = 0; i < 7; i++) {
					if (week[i]) {
						cnt++;
						if (cnt == remain) {
							result += i + 1;
							break;
						}
					}
				}
			}
			for (int i = 0; i < 7; i++) {
				if (week[i]) {
					result -= i;
					break;
				}
			}

			answer = min(answer, result);
		}
		temp = week[6];
		for (int i = 6; i >= 1; i--) {
			week[i] = week[i - 1];
		}
		week[0] = temp;

	}
	
	cout << answer;
}

int main() {
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cout << '#' << tc << ' ';
		solve();
		cout << '\n';
	}
	return 0;
}