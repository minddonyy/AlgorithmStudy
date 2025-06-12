#include <iostream>
using namespace std;
#include <vector>
#include <queue>
bool visited[100001] = { 0 };
int bfs() {
	int sky_1, sky_2, dong, jumi;
	cin >> sky_1 >> sky_2 >> dong >> jumi;
	queue<int> arr; arr.push(dong);
	visited[dong] = 1;
	int i, current, result = 0;
	int len;
	while (true)
	{	
		len = arr.size();
		for (i = 0; i < len; i++) {
			current = arr.front();
			arr.pop();
			if (current == jumi) return result;
			
			if (current - 1 >= 0 && !visited[current - 1]) {
				visited[current - 1] = 1;
				arr.push(current - 1);
			}
			if (current + 1 <= 100000 && !visited[current + 1]) {
				visited[current + 1] = 1;
				arr.push(current + 1);
			}
			if (current * sky_1 <= 100000 && !visited[current * sky_1]) {
				visited[current * sky_1] = 1;
				arr.push(current * sky_1);
			}
			if (current * sky_2 <= 100000 && !visited[current * sky_2]) {
				visited[current * sky_2] = 1;
				arr.push(current * sky_2);
			}
			if (current + sky_1 <= 100000 && !visited[current + sky_1]) {
				visited[current + sky_1] = 1;
				arr.push(current + sky_1);
			}
			if (current + sky_2 <= 100000 && !visited[current + sky_2]) {
				visited[current + sky_2] = 1;
				arr.push(current + sky_2);
			}
			if (current - sky_1 >= 0 && !visited[current - sky_1]) {
				visited[current - sky_1] = 1;
				arr.push(current - sky_1);
			}
			if (current - sky_2 >= 0 && !visited[current - sky_2]) {
				visited[current - sky_2] = 1;
				arr.push(current - sky_2);
			}
		}
		result++;

	}
}
int main() {
	int result;
	result = bfs();
	cout << result << '\n';
	return 0;
}