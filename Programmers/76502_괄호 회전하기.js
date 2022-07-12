let str = "()[{}]";
solution(str);

function check(s, all, open, close) {
  let arr = [];
  let count = 0;
  for (let j = 0; j < s.length; j++) {
    if (open.includes(s[j])) {
      arr.push(s[j]);
      count++;
    } else if (all.includes(s[j]) === false) {
      count++;
    } else if (open.indexOf(arr.pop()) === close.indexOf(s[j])) {
      count++;
    } else {
      break;
    }
    console.log(s, arr, count);
  }
  if (s.length === count && arr.length === 0) {
    return 1;
  } else {
    return 0;
  }
}
function solution(str) {
  let answer = 0;
  let all = ["[", "{", "(", "]", "}", ")"];
  let open = ["[", "{", "("];
  let close = ["]", "}", ")"];
  const arr = str.split("");
  for (let i = 0; i < str.length; i++) {
    console.log(arr);
    answer += check(arr, all, open, close);
    arr.push(arr.shift());
    console.log(answer);
  }
  return answer;
}
