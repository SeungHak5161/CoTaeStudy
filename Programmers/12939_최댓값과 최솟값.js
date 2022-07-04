solution("1 2 3 4 5");
function solution(s) {
  let arr = s.split(" ");
  for (i in arr) {
    arr[i] = parseInt(arr[i]);
  }
  console.log(arr);
  let answer = "";
  let max = Math.max(...arr);
  let min = Math.min(...arr);
  console.log(max, min);
  answer = min + " " + max;
  console.log(answer);
  return answer;
}
