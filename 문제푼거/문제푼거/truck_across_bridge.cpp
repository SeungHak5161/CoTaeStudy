#include<iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct truck {
	int weight;
	int left_time;
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0, index = 0, queue_size = 0, num;
	num = truck_weights.size();
	truck bridge_queue[10000];
	int sum = 0;
	do {
		for (int i = 0; i < num; i++) {
			if (bridge_queue[i].left_time > 0) {
				if (bridge_queue[i].left_time - 1 == 0) {
					queue_size--;
					sum -= bridge_queue[i].weight;
					bridge_queue[i].left_time -= 1;
				}
				else bridge_queue[i].left_time -= 1;
			}
		}
		if (index < num) {
			if (sum + truck_weights.at(index) <= weight) {
				bridge_queue[index].weight = truck_weights.at(index);
				bridge_queue[index].left_time = bridge_length;
				sum += truck_weights.at(index);
				index++;
				queue_size++;
			}
		}
		answer++;
	} while (queue_size != 0);

	return answer;
}

int main(void) {
	int bridge_length, weight, num, temp;
	vector<int> truck_weights;
	cout << "num, bridge_length, weight 순으로 입력"<<endl;
	cin >> num >> bridge_length >> weight;
	cout << "truck_weights 입력"<<endl;
	for (int i = 0; i < num; i++) {
		cin >> temp;
		truck_weights.push_back(temp);
	}
	cout<< solution(bridge_length, weight, truck_weights);
}