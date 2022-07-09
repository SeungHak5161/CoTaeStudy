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

// 2진수  배열 10진수 정수로 변환
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

function isalpha(c) {
  return (c >= "a" && c <= "z") || (c >= "A" && c <= "Z");
}

function isdigit(c) {
  return c >= "0" && c <= "9";
}

function isalnum(c) {
  return isalpha(c) || isdigit(c);
}

/* [특수 문자 제거 이벤트 수행 부분] */
function removeSpecialData(originalData) {
  console.log(originalData);

  // [1] 정규식 형태 선언 (특수문자, 괄호, 점, 공백 모두 제거 실시)
  var reg = /[`~!@#$%^&*()_|+\-=?;:'",.<>\{\}\[\]\\\/ ]/gim;

  // [2] 정규식 형태 선언 (특수문자, 괄호, 점 모두 제거 실시 - 공백은 제거 안함)
  //var reg = /[`~!@#$%^&*()_|+\-=?;:'",.<>\{\}\[\]\\\/]/gim;

  // [3] 정규식 형태 선언 (특수문자, 괄호, 공백 모두 제거 실시 - 점은 제거 안함)
  //var reg = /[`~!@#$%^&*()_|+\-=?;:'"<>\{\}\[\]\\\/ ]/gim;
  var resultData = originalData.replace(reg, "");
  console.log(resultData);
}

/* [숫자 제거 이벤트 수행 부분] */
function removeNumberData(originalData) {
  console.log(originalData);
  var reg = /[0-9 ]/gim;
  var resultData = originalData.replace(reg, "");
  console.log(resultData);
}

/* [영어 제거 이벤트 수행 부분] */
function removeEngData(originalData) {
  var reg = /[a-zA-Z ]/gim;
  var resultData = originalData.replace(reg, "");
  console.log(resultData);
