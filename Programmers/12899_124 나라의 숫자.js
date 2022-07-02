solution(24);
function solution(n) {
  let arr = [];
  while (n >= 3) {
    let mod = (n - 1) % 3;
    if (mod === 0) {
      arr.unshift(1);
    } else if (mod === 1) {
      arr.unshift(2);
    } else if (mod === 2) {
      arr.unshift(4);
    }
    console.log(arr, n);
    n = Math.floor((n - 1) / 3);
  }
  if (n !== 0) {
    arr.unshift(n);
    console.log(arr);
  }
  console.log(arr.join(""));
}

// 입력값 3으로 나누고 나머지를 배열에 추가하면서, 10,20,30은 각각 03,13,23으로 바꿔줌
// 첫째자리가 0으로 시작할 경우 삭제하고, 모든 3을 4로 바꿔줌
// => 몇 개 틀리고, 효율성 테스트 전체 탈락
// => 30 넣었을때 다르게 나옴, 고칠 수 있을 것 같은데 귀찮아서 패스, 효율성 테스트는 console.log()만 떼도 됨
// function solution(n) {
//   let arr = [];
//   while (n >= 3) {
//     arr.unshift(n % 3);
//     n = Math.floor(n / 3);
//   }
//   arr.unshift(n);
//   console.log(arr);
//   for (let i = 0; i < arr.length; i++) {
//     if (i + 1 !== arr.length) {
//       let str = `${arr[i]}${arr[i + 1]}`;
//       switch (str) {
//         case "10":
//           arr[i] = 0;
//           arr[i + 1] = 3;
//           break;
//         case "20":
//           arr[i] = 1;
//           arr[i + 1] = 3;
//           break;
//         case "30":
//           arr[i] = 2;
//           arr[i + 1] = 3;
//           break;
//       }
//     }
//   }
//   if (arr[0] === 0) {
//     arr.shift();
//   }
//   for (i in arr) {
//     if (arr[i] === 3) {
//       arr[i] = 4;
//     }
//   }
//   let answer = arr.join("");
//   console.log(answer);
//   return answer;
// }
