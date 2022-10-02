#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
	//정렬 실행(string 타입이기 때문에 숫자 크기가 아닌 문자 오름차순으로 정렬됨)
	//정렬 하지 않을 시 "1234","12"같은 경우 true로 나옴
	sort(phone_book.begin(), phone_book.end());
	unordered_map<string, int> book;
	//hash에 첫번째 전화번호 저장
	book.insert(make_pair(phone_book[0], 0));
	for (int i = 1; i < phone_book.size(); i++) {
		string number = "";
		//한 글자씩 저장해 다른 번호가 접두사가 되는지 비교
		for (int j = 0; j < phone_book[i].length(); j++) {
			number += phone_book[i][j];
			if (book.find(number) != book.end())
				return false;
		}
		//없을 경우 내가 접두사가 될 수 있으니 hash에 저장
		book.insert(make_pair(phone_book[i], i));
	}
	return true;
}

int main(void) {
	vector<string> phone_book;
	phone_book.push_back("123");
	phone_book.push_back("456");
	phone_book.push_back("789");
	cout << solution(phone_book);
}