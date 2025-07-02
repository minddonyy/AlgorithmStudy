using namespace std;
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

unordered_map<string, int> dict = { {"A", 0}, {"A#", 1}, {"B", 2}, {"C", 3}, {"C#", 4}, {"D", 5}, {"D#", 6}, {"E", 7}, {"F", 8}, {"F#", 9}, {"G", 10}, {"G#", 11} };
int total_num, codes_num, result = 99999;
int total[12], codes[6];
void dfs(vector<int>& choose, vector<int>& vals, int cnt){
	if (cnt == total_num) {
		int flag = 0;
		for (int i = 0; i < codes_num; ++i) {
			if (choose[i] == 0) {
				return;
			}
		}
		int max_val = -99999, min_val = 99999;
		for (int i = 0; i < vals.size(); ++i) {
			if (vals[i] == 0) continue;
			if (vals[i] > max_val) {
				max_val = vals[i];
			}
			if (vals[i] < min_val) {
				min_val = vals[i];
			}
		}

		//cout << max_val << ' ' << min_val << endl;
		if (max_val == -99999) {
			result = 0;
			return;
		}
		
		result = min(result, max_val - min_val + 1);
		return;
	}
	bool flag = 0;
	for (int i = 0; i < codes_num; ++i) {
		flag = 1;
		if (choose[i] == 1) flag = 0;
		choose[i] = 1;
		int temp;
		if (codes[i] >= total[cnt]) {
			temp = codes[i] - total[cnt];
		}
		else
		{
			temp = codes[i] + 12 - total[cnt];
		}
		vals.push_back(temp);
		dfs(choose,vals, cnt + 1);
		vals.pop_back();
		vals.push_back(temp + 12);
		dfs(choose, vals,cnt + 1);
		vals.pop_back();
		if (flag == 1) choose[i] = 0;

	}
}
int main() {
	cin >> total_num >> codes_num;

	vector<vector<int>> diff(codes_num, vector<int>(total_num));
	string input;
	for (int i = 0; i < total_num; ++i) {
		cin >> input; total[i] = dict[input];
	}
	for (int i = 0; i < codes_num; ++i) {
		cin >> input; codes[i] = dict[input];
	}
	
	vector<int> choose(codes_num, 0);
	vector<int> vals;
	dfs(choose,vals, 0);
	cout << result << '\n';
}