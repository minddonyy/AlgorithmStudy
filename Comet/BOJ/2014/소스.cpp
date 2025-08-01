using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_set>
#include <algorithm>
long long num_prime, tar;


struct compare
{
	bool operator ()(const long long& a, const long long& b) {
		return a > b;
	}
};
vector<long long> primes;
priority_queue<long long, vector<long long>, compare> que;
unordered_set<long long> sett;
int main() {
	int input;
	cin >> num_prime >> tar;
	for (int i = 0; i < num_prime; ++i) {
		cin >> input;
		primes.push_back(input);
		que.push(input);
		sett.insert(input);
	}
	long long cnt = 0;
	long long cur;
	long long max_val = primes[num_prime - 1];
	while (cnt < tar)
	{	
		
		cur = que.top(); que.pop();
		//cout << cur << '\n';
		++cnt;
		for (long long& num : primes) {
			long long new_val = num * cur;
			if (new_val >= INT_MAX) continue;
			if (que.size() >= tar && new_val >= max_val) continue;
			if (sett.find(new_val) != sett.end()) continue;
			sett.insert(new_val);
			que.push(new_val);
			max_val = max(max_val, new_val);
		}
	}
	cout << cur << '\n';

	return 0;
}