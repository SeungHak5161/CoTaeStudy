solution([3, 0, 6, 1, 5]);
function solution(arr) {
  let result = 0;
  arr.sort((a, b) => {
    return b - a;
  });
  console.log(arr);
  for (i in arr) {
    console.log(parseInt(i) + 1, arr[i]);
    if (arr[i] >= parseInt(i) + 1) {
      result = parseInt(i) + 1;
    }
  }
  console.log(result);
  return result;
}
