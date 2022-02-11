#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
	//���� ����(string Ÿ���̱� ������ ���� ũ�Ⱑ �ƴ� ���� ������������ ���ĵ�)
	//���� ���� ���� �� "1234","12"���� ��� true�� ����
	sort(phone_book.begin(), phone_book.end());
	unordered_map<string, int> book;
	//hash�� ù��° ��ȭ��ȣ ����
	book.insert(make_pair(phone_book[0], 0));
	for (int i = 1; i < phone_book.size(); i++) {
		string number = "";
		//�� ���ھ� ������ �ٸ� ��ȣ�� ���λ簡 �Ǵ��� ��
		for (int j = 0; j < phone_book[i].length(); j++) {
			number += phone_book[i][j];
			if (book.find(number) != book.end())
				return false;
		}
		//���� ��� ���� ���λ簡 �� �� ������ hash�� ����
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