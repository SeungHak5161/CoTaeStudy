solution(1, 30);
function solution(begin, end) {
  let arr = [];
  for (i = begin; i <= end; i++) {
    let pushed = false;
    console.log(i - 1, arr);
    if (i === 1) {
      arr.push(0);
      continue;
    }
    for (j = 2; j <= Math.sqrt(i); j++) {
      if (i % j === 0 && i / j <= 10000000) {
        arr.push(i / j);
        pushed = true;
        break;
      }
    }
    if (pushed === false) {
      arr.push(1);
    }
  }
  console.log(arr);
  return arr;
}
