using namespace std;
#include <iostream>
#include <vector>
#include <string>


void solve() {
	string time; cin >> time;
	int cost = 0, len; cin >> len;
	int hour, min;
	hour = (time[0] - '0') * 10 + (time[1] - '0');
	min = (time[3] - '0') * 10 + (time[4] - '0');
	int cur = hour * 60 + min + 120;
	while (len > 0)
	{
		int spend;
		cur = cur % 1440;
		if (cur >= 600 && cur <= 1439) {	// 8시에서 22시 사이면.
			spend = (len < (1440 - cur)) ? len : (1440 - cur);

			cost += spend / 60 + (spend % 60 == 0 ? 0 : 1);
			len -= spend + (spend % 60 == 0 ? 0 : 60 - spend % 60);
			cur += spend + (spend % 60 == 0 ? 0 : 60 - spend % 60);
		}
		else {
			if (len / 60 >= 5 && cur <= 300) {	// 정액권을 쓰는게 이득이면.
				cost += 5;
				spend = 600 - cur;
				len -= spend;
				cur = 600;
			}
			else {
				spend = len < 600 - cur ? len : 600 - cur;
				cost += spend / 60 + (spend % 60 == 0 ? 0 : 1);
				len -= spend + (spend % 60 == 0 ? 0 : 60 - spend % 60);
				cur += spend + (spend % 60 == 0 ? 0 : 60 - spend % 60);
			}
		}
	}
	cout << cost * 1000 << '\n';
}





int main() {
	int T; cin >> T;
	for (int tc = 0; tc < T; tc++) {
		solve();
	}

	return 0;
}