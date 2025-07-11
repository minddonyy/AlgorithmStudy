using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
struct dataset
{
	long long loc, degree;
};
bool compare(const dataset& a, const dataset& b) {
	return a.loc < b.loc;
}
int main() {
	long long num, loc, degree;
	long long Ltotal = 0, Rtotal = 0;
	cin >> num;
	vector<dataset> arr(num);

	for (int i = 0; i < num; ++i) {
		cin >> loc >> degree;
		arr[i] = { loc, degree };
	}
	sort(arr.begin(), arr.end(), compare);

	for (int i = 1; i < num; ++i) {
		Ltotal += (arr[i].loc - arr[i - 1].loc) * i;
		Rtotal += (arr[i].loc - arr[i - 1].loc) * (num - i);
	}

	for (int i = 0; i < num; ++i) {
		Ltotal += arr[i].degree;
		Rtotal += arr[i].degree;
	}
	long long result = LLONG_MAX;
	long long val;
	val = Ltotal - arr[0].degree - (arr[num - 1].loc - arr[0].loc);
	result = min(result, val);
	val = Ltotal - arr[num - 1].degree - (arr[num - 1].loc - arr[num - 2].loc) * (num - 1);
	result = min(result, val);

	val = Rtotal - arr[num - 1].degree - (arr[num - 1].loc - arr[0].loc);
	result = min(result, val);
	val = Rtotal - arr[0].degree - (arr[1].loc - arr[0].loc) * (num - 1);
	result = min(result, val);


	for (int i = 1; i < num - 1; ++i) {
		// аб -> ©Л
		val = Ltotal;
		val -= arr[num - 1].loc - arr[i].loc;
		val -= arr[i].degree;
		result = min(result, val);
		// аб <- ©Л
		val = Rtotal;
		val -= arr[i].loc - arr[0].loc;
		val -= arr[i].degree;
		result = min(result, val);
	}
	cout << result << '\n';
	return 0;
}
