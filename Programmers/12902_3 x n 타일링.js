solution(6);
function solution(n) {
  let arr = [];
  arr[0] = 1;
  arr[2] = 3;
  if (n % 2 === 1) {
    return 0;
  }
  for (i = 4; i <= n; i += 2) {
    arr[i] = 3 * arr[i - 2];
    for (j = i - 4; j >= 0; j -= 2) {
      arr[i] += arr[j] * 2;
    }
    arr[i] %= 1000000007;
  }
  console.log(arr[n]);
  return arr[n];
}
