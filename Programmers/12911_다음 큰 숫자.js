solution(4);
function check(arr, i) {
  if (arr.length - 1 - i < 0) {
    arr.unshift(0);
  }
  if (arr[arr.length - 1 - i] + 1 === 2) {
    arr[arr.length - 1 - i] = 0;
    check(arr, i + 1);
  } else {
    arr[arr.length - 1 - i] = 1;
  }
  return arr;
}
function decimal(arr) {
  let ret = 0;
  for (i = 0; i < arr.length; i++) {
    ret += arr[arr.length - 1 - i] * Math.pow(2, i);
  }
  return ret;
}
function binary(n) {
  let arr = [];
  while (n >= 1) {
    arr.unshift(n % 2);
    n = Math.floor(n / 2);
  }
  return arr;
}
function solution(n) {
  let arr = binary(n);
  // console.log(arr);
  let count = arr.filter((e) => e === 1).length;

  while (true) {
    arr = check(arr, 0);
    // console.log(arr);
    if (count === arr.filter((e) => e === 1).length) {
      // console.log(decimal(arr));
      return decimal(arr);
    }
  }
}
