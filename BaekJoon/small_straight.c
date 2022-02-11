//#include <Stdio.h>
//
//int main() {
//	int input;
//	int arr[5];
//	int count = 0;
//	int tmp;
//
//	/*scanf("%d", &input);*/
//	for (int i = 0; i < 5; i++)
//		scanf("%d", &arr[i]);
//
//	if (arr[0] > arr[4]) {
//		tmp = arr[4]; arr[4] = arr[0]; arr[0] = tmp; tmp = arr[3]; arr[3] = arr[1]; arr[1] = tmp;
//	}
//
//	for (int i = 0; i < 4; i++) {
//		if (arr[i] == arr[i + 1]) {
//			for (int j = i; j < 5 - i; j++)
//				arr[j] = arr[j + 1];
//			arr[4] = 0;
//		}
//		else if (arr[i + 1] - arr[i] != 1) {
//			printf("NO");
//		}
//	}
//	//12234
//
//	for (int i = 0; i < 4; i++) {
//		if (arr[i + 1] - arr[i] == 1)
//			if (arr[i+1] == 0)
//				count += 0;
//			else
//			count += arr[i + 1] - arr[i];
//	}
//
//
//	if (count == 3 || count == 4)
//		printf("YES");
//
//	return 0;
//}
