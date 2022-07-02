function isalpha(c) {
  if (c[0] >= "a" && c[0] <= "z" && c[1] >= "a" && c[1] <= "z") {
    return true;
  }
}

function solution(str1, str2) {
  let answer = 0;
  let intersaction = 0;
  let union = 0;
  let arr1 = [];
  let arr2 = [];
  str1 = str1.toLowerCase();
  str2 = str2.toLowerCase();
  for (let i = 0; i < str1.length; i++) {
    let tmp = str1.slice(i, i + 2);
    if (tmp.length === 2 && isalpha(tmp) === true) {
      arr1.push(tmp);
    }
  }
  for (let i = 0; i < str2.length; i++) {
    let tmp = str2.slice(i, i + 2);
    if (tmp.length === 2 && isalpha(tmp) === true) {
      arr2.push(tmp);
    }
  }
  console.log(arr1);
  console.log(arr2);
  let a1l = arr1.length;
  let a2l = arr2.length;
  for (i of arr1) {
    if (arr2.includes(i)) {
      intersaction++;
      arr2.splice(arr2.indexOf(i), 1);
    }
  }
  union = a1l + a2l - intersaction;
  if (union === 0) {
    answer = 65536;
  } else if (intersaction === 0) {
    answer = 0;
  } else if (arr1.length === 0 || arr2.length === 0) {
    answer = 65536;
  } else {
    answer = Math.floor((intersaction / union) * 65536);
  }
  console.log(intersaction, union, answer);
  return answer;
}
