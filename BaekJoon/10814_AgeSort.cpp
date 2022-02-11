#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool compare(pair<int, string>a, pair<int, string>b) {
	if (a.first == b.first)
		return a < b;
	else
		return a.first < b.first;
}

void main() {
	vector<pair<int, string>>v;

	int num,age;
	string name;

	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> age >> name;
		v.push_back(pair<int, string>(age,name));
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << ' ' << v[i].second << endl;
}

/*
void main() {
	int num, *age, temp;
	char *Ntemp, **name;

	scanf("%d", &num);

	age = (int*)malloc(sizeof(num) / sizeof(int));
	name = (char*)malloc(sizeof(num) / sizeof(int));

	for (int i = 0; i < num; i++) {
		scanf("%d %s", &age, &name);
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (age[i] > age[j]) {
				temp = age[j];
				age[j] = age[i];
				age[i] = temp;
				*Ntemp = name[j];
				name[j] = name[i];
				name[i] = *Ntemp;
			}
		}
	}
	for(int i = 0; i < num; i++)
		printf("%d %s", age[i], *name[i]);
}*/