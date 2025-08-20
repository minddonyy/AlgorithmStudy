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
struct memo
{
	int difficulty = 0, algo = 0;
};
memo problems[100001];
set<dataset> list;
vector<set<dataset>> algo(101);

int main()
{	
	int num, a, b, c;
	cin >> num;
	for (int i = 0; i < num; ++i) {
		cin >> a >> b >> c;
		list.insert({ a, b });
		algo[c].insert({ a, b });
		problems[a].difficulty = b;
		problems[a].algo = c;
	}
	cin >> num;
	string q;

	for (int i = 0; i < num; ++i) {
		cin >> q;
		//cout << q << endl;
		if (q == "add") {
			cin >> a >> b >> c;
			list.insert({ a, b });
			algo[c].insert({ a, b });
			problems[a].difficulty = b;
			problems[a].algo = c;
		}
		else if (q == "solved") {
			cin >> a;
			list.erase({ a, problems[a].difficulty });
			algo[problems[a].algo].erase({ a, problems[a].difficulty });
			problems[a].difficulty = 0;
			problems[a].algo = 0;
		}
		else if (q == "recommend2") {
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
		else if (q == "recommend") {
			cin >> a >> b;
			if (b == 1) {
				auto result = algo[a].end();
				--result;
				cout << (*result).num << '\n';
			}
			else {
				auto result = algo[a].begin();
				cout << (*result).num << '\n';
			}
		}
		else if (q == "recommend3") {
			cin >> a >> b;
			if (a == 1) {
				auto result = list.lower_bound({ 0, b });
				if (result == list.end()) {
					cout << -1 << '\n';
				}
				else {
					cout << (*result).num << '\n';
				}
			}
			else {
				auto result = list.lower_bound({ 0, b });
				if (result == list.end() || result == list.begin()) {
					cout << -1 << '\n';
				}
				else {
					--result;
					cout << (*result).num  << '\n';
				}
			}
		}
	}
	return 0;
}