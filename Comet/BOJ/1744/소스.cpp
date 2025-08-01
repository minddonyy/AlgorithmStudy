using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>



bool compare(const int& a, const int& b) {
	return a > b;
}


int main() {
	vector<int> plus;
	vector<int> minus;
	int n, input, result = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> input;
		if (input <= 0) {
			minus.push_back(input);
		}
		else {
			plus.push_back(input);
		}
	}
	sort(plus.begin(), plus.end());
	sort(minus.begin(), minus.end(), compare);
	for (int i = plus.size() - 1; i >= 0; i -= 2) {
		if (i - 1  < 0) {
			result += plus[i];
			break;
		}
		if (plus[i] == 1 || plus[i - 1] == 1) {
			result += plus[i] + plus[i - 1];
			continue;
		}
		result += plus[i] * plus[i - 1];
	}
	for (int i = minus.size() - 1; i >= 0; i -= 2) {
		if (i - 1 < 0) {
			result += minus[i];
			break;
		}
		result += minus[i] * minus[i - 1];
	}

	cout << result << '\n';
	return 0;
}