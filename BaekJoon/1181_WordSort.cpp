//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int compare(int a, int b) {
//	if (strlen(a) < strlen(b))
//		return a;
//	else if (strlen(a) == strlen(b)) {
//		int ret = strcmp(a, b);
//		if (ret > 0)
//			return b;
//		else
//			return a;
//	}
//}
//
//void main() {
//	int num;
//	scanf("%d", &num);
//	char word[num][50];
//
//	for (int i = 0; i < num; i++) {
//		scanf("%s", word[i]);
//	}
//
//	qsort(word, num, sizeof(int), compare);
//
//
//	for (int i = 0; i < num; i++) {
//		if (!strcmp(word[i], word[i + 1])) { //strcmp는 두 문자열이 같을때 0을 반환함 -> !로 부정함으로써 if(true)로 만듦
//			continue;
//		}
//		else {
//			printf("%s\n", word[i]);
//		}
//	}
//}

//현성ver.
 
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool compare(string a, string b) {
   if (a.length() < b.length()) { return true; }
   else if (a.length() > b.length()) { return false; }
   else { return a < b; }
}
int main(void) {
   string array[20000];
   int length;
   cin >> length;
   for (int i = 0; i < length; i++) { cin >> array[i]; }
   sort(array, array + length, compare);
   for (int i = 0; i < length; i++) {
	  if (i > 0 && array[i] == array[i - 1]) { continue; }
	  cout << array[i] << endl;
   }
}