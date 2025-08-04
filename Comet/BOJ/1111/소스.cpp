using namespace std;
#include <iostream>
#include <unordered_set>
const int errornum = -99999999;
int num;
int arr[50];

int solve(int a, int b) {
	for (int i = 1; i < num; ++i) {
		if (arr[i] != ((arr[i - 1] * a) + b)) {
			return errornum;
		}
	}
	return (arr[num - 1] * a) + b;
}



int main()
{	
	int result = 0;
	cin >> num;
	unordered_set<int> ans;
	for (int i = 0; i < num; ++i) {
		cin >> arr[i];
	}
	for (int a = -200; a <= 200; ++a) {
		for (int b = -20000; b <= 20000; ++b) {
			result = solve(a, b);
			if (result != errornum) {
				ans.insert(result);

			}
		}
	}
	if (ans.size() == 0) {
		cout << 'B' << '\n';
	}
	else if (ans.size() == 1) {
		for (auto& answer : ans) {
			cout << answer << '\n';
		}
		
	}
	else {
		cout << 'A' << '\n';
	}
	return 0;
}