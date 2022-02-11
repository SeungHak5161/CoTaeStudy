#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
// key값에 해당하는 value가 없을 시 iterator의 end()값을 리턴

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	unordered_map<string, int> hash;
	for (string name : participant) {
		hash[name]++;
	}

	for (string name : completion) {
		hash[name]--;
	}
	for (auto pair : hash) {
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