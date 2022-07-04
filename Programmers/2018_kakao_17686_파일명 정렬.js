function matrix(m, n, initial) {
  let a,
    i,
    j,
    mat = [];
  for (i = 0; i < m; i += 1) {
    a = [];
    for (j = 0; j < n; j += 1) {
      a[j] = initial;
    }
    mat[i] = a;
  }
  return mat;
}
function findHead(spltArr) {
  let headLength = 0;
  for (let i = 0; i < spltArr.length; i++) {
    if (spltArr[i].match(/[0-9]/)) {
      headLength = i;
      break;
    }
  }
  return headLength;
}
function findNumber(spltArr) {
  let numberLength = 0;
  for (let i = 0; i < spltArr.length; i++) {
    if (spltArr[i].match(/[^0-9]/)) {
      numberLength = i;
      break;
    }
  }
  return numberLength;
}
function solution(files) {
  let arr = matrix(files.length, 0, null);
  files.map((e, idx) => {
    let spltArr = e.split("");
    let head = "";
    let number = "";
    let tail = "";

    let headLength = findHead(spltArr);
    for (let i = 0; i < headLength; i++) {
      head += spltArr[i];
    }

    spltArr.splice(0, headLength);
    let numberLength = findNumber(spltArr);
    if (numberLength === 0) {
      for (let i = 0; i < spltArr.length; i++) {
        number += spltArr[i];
      }
    } else {
      for (let i = 0; i < numberLength; i++) {
        number += spltArr[i];
      }
    }

    spltArr.splice(0, numberLength);
    if (numberLength === 0) {
      tail = "";
    } else {
      tail = spltArr.join("");
    }

    arr[idx].push(e);
    arr[idx].push(head);
    arr[idx].push(number);
    arr[idx].push(tail);
  });
  arr
    .sort((a, b) => {
      let numberA = parseInt(a[2]);
      let numberB = parseInt(b[2]);
      console.log(numberA, numberB);
      if (numberA < numberB) {
        return -1;
      }
      if (numberA > numberB) {
        return 1;
      }
      return 0;
    })
    .sort((a, b) => {
      let headA = a[1].toUpperCase();
      let headB = b[1].toUpperCase();
      if (headA < headB) {
        return -1;
      }
      if (headA > headB) {
        return 1;
      }
      return 0;
    });
  console.log(arr);
  let answer = [];
  arr.map((e) => {
    answer.push(e[0]);
  });
  console.log(answer);
  return answer;
}
