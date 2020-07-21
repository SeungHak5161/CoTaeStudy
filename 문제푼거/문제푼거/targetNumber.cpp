#include <iostream>
#include <string>
#include <vector>

using namespace std;


int DFS(vector<int> numbers, int target, int index, int num) {
	if (numbers.size() == index) {
		if (num == target)	return 1;
		else return 0;
	}
	else {
		return DFS(numbers, target, index+1, num + numbers[index]) + DFS(numbers, target, index+1, num - numbers[index]);
	}
}

int solution(vector<int> numbers, int target) {
	int answer = 0;
	answer = DFS(numbers, target, 0, 0);
	return answer;
}

int main(void) {
	vector<int> numbers;
	int target, temp;
	for (int i = 0; i < 5; i++) {
		cout << i+1 << "번째 숫자" << endl;
		cin >> temp;
		numbers.push_back(temp);
	}
	cout << "만들 숫자" << endl;
	cin >> target;
	solution(numbers, target);
}