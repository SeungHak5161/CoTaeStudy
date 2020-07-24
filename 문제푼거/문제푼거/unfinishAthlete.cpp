#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
// key���� �ش��ϴ� value�� ���� �� iterator�� end()���� ����

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	unordered_map<string,int> hashSwan;
	for (string name : participant) {
		hashSwan[name]++;
	}

	for (string name:completion) {
		hashSwan[name]--;
	}
	for (auto pair : hashSwan) {
		if (pair.second > 0) {
			return pair.first;
		}
	}
}

int main(void) {
	vector<string> participant;
	vector<string> completion;
	participant.push_back("mislav");
	participant.push_back("stanko");
	participant.push_back("mislav");
	participant.push_back("ana");
	completion.push_back("stanko");
	completion.push_back("ana");
	completion.push_back("mislav");
	cout<<solution(participant, completion);
}