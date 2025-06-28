
using namespace std;
#include <iostream>
#include <vector>
#include <string>

int main() {
	int length;
	string str, result;
	cin >> length;
	cin >> str;
	vector<char> stack;

	for (int i = length - 1; i >= 0; i--) {
		if (!stack.empty() && str[i] == stack.back()) {
			stack.pop_back();
			result.push_back('N');
			continue;
		}
		if (str[i] == 'S')
		{
			stack.push_back('U');
			result.push_back('U');
			result.push_back('N');
		}
		else
		{
			stack.push_back('S');
			result.push_back('S');
			result.push_back('N');
		}
	}
	cout << result.size() << '\n';
	cout << result << '\n';
	return 0;
}


