#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	unordered_map<long long, long long> room;
	int size = room_number.size();
	for (int i = 0; i < size; ++i) {
		long long idx = room_number[i];
		vector<long long> memo;
		memo.push_back(room_number[i]);
		while (room[idx] != 0)
		{
			idx = room[idx];
			memo.push_back(idx);
		}
		for (auto& n : memo) {
			room[n] = idx + 1;
		}
		
		answer.push_back(idx);
	}
	return answer;
}