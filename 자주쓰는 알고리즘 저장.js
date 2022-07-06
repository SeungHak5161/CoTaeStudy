// 소인수 분해한 배열 return(오름차순)
function primeFactors(n) {
  const answer = [];
  for (let i = 2; i * i <= n; i++) {
    while (n % i === 0) {
      answer.push(i);
      n /= i;
    }
  }
  if (n > 2) answer.push(n);
  return answer;
}

// 2진수 배열 10진수 정수로 변환
function decimal(arr) {
  let ret = 0;
  for (i = 0; i < arr.length; i++) {
    ret += arr[arr.length - 1 - i] * Math.pow(2, i);
  }
  return ret;
}

// 10진수 정수 2진수 배열로 변환
function binary(n) {
  let arr = [];
  while (n >= 1) {
    arr.unshift(n % 2);
    n = Math.floor(n / 2);
  }
  return arr;
}
