#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {

}

int main(void) {
	vector<int> scoville;
	int K = 7;
	scoville.push_back(9);
	scoville.push_back(2);
	scoville.push_back(10);
	scoville.push_back(1);
	scoville.push_back(3);
	scoville.push_back(12);

	cout << solution(scoville, K);
	return 0;
}

//int solution(vector<int> scoville, int K) {	
//	int size = scoville.size();
//	int *arr = new int[size];
//	//vector<int>::iterator it;
//	int i = 0, cnt = 0;
//	for (int num:scoville) {
//		arr[i] = num;
//		++i;
//	}
//	sort(arr, arr + size);
//	while (arr[0] < K) {
//		if (size == 1) return -1;
//		arr[0] = arr[0] + arr[1] * 2;
//		for (int j = 1; j < size-1; j++)
//			arr[j] = arr[j + 1];
//		--size;
//		++cnt;
//		sort(arr, arr + size);
//	}
//	return cnt;
//}