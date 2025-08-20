using namespace std;
#include <iostream>
#include <vector>
#include <set>
#include <string>
struct dataset
{
	int num, difficulty;
	bool operator < (const dataset& other) const {
		if (difficulty == other.difficulty) {
			return num < other.num;
		}
		return difficulty < other.difficulty;
	}
};

int problems[100001] = { 0 };
set<dataset> list;


int main()
{
	int num, a, b;
	cin >> num;
	for (int i = 0; i < num; ++i) {
		cin >> a >> b;
		list.insert({ a, b });
		problems[a] = b;
	}
	cin >> num;
	string q;

	for (int i = 0; i < num; ++i) {
		cin >> q;
		if (q == "add") {
			cin >> a >> b;
			list.insert({ a, b });
			problems[a] = b;
		}
		else if (q == "solved") {
			cin >> a;
			list.erase({ a, problems[a] });
			problems[a] = 0;
		}
		else {
			cin >> a;
			if (a == 1) {
				auto result = list.end();
				--result;
				cout << (*result).num << '\n';
			}
			else {
				auto result = list.begin();
				cout << (*result).num << '\n';
			}
			
		}
	}
	return 0;
}