#include <iostream>
using namespace std;
#include <vector>
#include <queue>


int main() {
	int result = 0;
	int truck_num, length, max_weight;
	cin >> truck_num >> length >> max_weight;
	queue<int> trucks, road;
	int truck, sum_weight = 0;
	for (int i = 0; i < length; i++) {
		road.push(0);
	}
	for (int i = 0; i < truck_num; i++) {
		cin >> truck;
		trucks.push(truck);
	}
	while (trucks.size() != 0 || sum_weight != 0)
	{
		result++;
		sum_weight -= road.front(); road.pop();
		if (trucks.size() == 0) {
			continue;
		}
		truck = trucks.front();
		if (truck + sum_weight <= max_weight) {
			trucks.pop();
			road.push(truck);
			sum_weight += truck;
		}
		else {
			road.push(0);
		}
	}

	

	cout << result << '\n';
	return 0;
}