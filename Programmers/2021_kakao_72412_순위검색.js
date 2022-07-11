const info = [
  "java backend junior pizza 150",
  "python frontend senior chicken 210",
  "python frontend senior chicken 150",
  "cpp backend senior pizza 260",
  "java backend junior chicken 80",
  "python backend senior chicken 50",
];
const query = [
  // "java and backend and junior and pizza 100",
  "python and frontend and senior and chicken 200",
  // "cpp and - and senior and pizza 250",
  // "- and backend and senior and - 150",
  "- and - and - and chicken 100",
  // "- and - and - and - 150",
];
solution(info, query);

// // 효율성에서 떨어짐, 이진탐색 사용하는 알고리즘 짜보기
// function solution(info, query) {
//   let answer = [];
//   let info_arr = [];
//   // info 데이터 배열로 정리
//   for (i = 0; i < info.length; i++) {
//     info_arr[i] = info[i].split(" ");
//   }
//   console.log(info_arr);
//   for (i = 0; i < query.length; i++) {
//     answer[i] = 0;
//     // query 데이터 배열로 정리
//     let line = query[i].split(" ").filter((x) => x !== "and");
//     // query의 기준 점수보다 높은 점수를 가진 info의 사람을 temp에 저장
//     let temp = [];
//     for (j = 0; j < info_arr.length; j++) {
//       if (parseInt(line[4]) <= parseInt(info_arr[j][4])) {
//         temp.push(info_arr[j].slice(0, 4));
//       }
//     }
//     // query에서 점수 부분 삭제
//     line.pop();
//     console.log(temp);
//     console.log("line : " + line);
//     // 각 temp 배열이 line(query)의 요소들을 포함하고 있는지 확인
//     for (j = 0; j < temp.length; j++) {
//       let count = 0;
//       for (p = 0; p < line.length; p++) {
//         if (line[p] === "-") {
//           count++;
//           continue;
//         }
//         if (temp[j].includes(line[p]) === true) {
//           count++;
//           continue;
//         } else {
//           break;
//         }
//       }
//       if (count === line.length) {
//         answer[i]++;
//       }
//     }
//   }
//   console.log(answer);
//   return answer;
// }

// // 조금 다르긴 한데 시간 복잡도는 같은듯
// function solution(info, query) {
//   let answer = [];
//   let info_arr = [];
//   // info 데이터 map으로 파싱
//   for (i = 0; i < info.length; i++) {
//     info_arr.push([]);
//     let temp = info[i].split(" ");
//     for (a of [temp[0], "-"]) {
//       for (b of [temp[1], "-"]) {
//         for (c of [temp[2], "-"]) {
//           for (d of [temp[3], "-"]) {
//             info_arr[i].push(a + b + c + d);
//           }
//         }
//       }
//     }
//     info_arr[i].unshift(parseInt(temp[4]));
//   }
//   info_arr.sort((a, b) => {
//     return b[16] - a[16];
//   });
//   console.log(info_arr);

//   for (i = 0; i < query.length; i++) {
//     answer[i] = 0;
//     let temp = [];
//     // query 데이터 배열로 파싱
//     let line = query[i].split(" ").filter((x) => x !== "and");
//     for (j = 0; j < info_arr.length; j++) {
//       if (info_arr[j][0] >= line[4]) {
//         temp.push(info_arr[j]);
//       }
//     }
//     console.log(temp);
//     line = line.slice(0, 4).join("");
//     console.log(line);
//     for (j = 0; j < temp.length; j++) {
//       if (temp[j].includes(line)) {
//         answer[i]++;
//       }
//     }
//   }
//   console.log(answer);
//   return answer;
// }

// 찾아보니 includes 먼저 한 방식이 있어서 따라해봤는데 이후에 탐색문제인지 통과는 못함 + 오류 있는지 정확도도 틀림
// function solution(info, query) {
//   let answer = [];
//   let info_arr = [];
//   // info 데이터 map으로 파싱
//   for (i = 0; i < info.length; i++) {
//     info_arr.push([]);
//     let temp = info[i].split(" ");
//     for (a of [temp[0], "-"]) {
//       for (b of [temp[1], "-"]) {
//         for (c of [temp[2], "-"]) {
//           for (d of [temp[3], "-"]) {
//             info_arr[i].push(a + b + c + d);
//           }
//         }
//       }
//     }
//     info_arr[i].unshift(parseInt(temp[4]));
//   }
//   info_arr.sort((a, b) => {
//     return b[16] - a[16];
//   });
//   console.log(info_arr);

//   for (i = 0; i < query.length; i++) {
//     answer[i] = 0;
//     let temp = [];
//     // query 데이터 배열로 파싱
//     let line = query[i].split(" ").filter((x) => x !== "and");
//     // // query의 기준 점수보다 높은 점수를 가진 info의 사람을 temp에 저장 -> 이 부분 생략하고 마지막에 이진탐색하는게 효율성이 더 좋나?
//     // for (j = 0; j < info_arr.length; j++) {
//     //   if (info_arr[j][0] >= line[4]) {
//     //     temp.push(info_arr[j]);
//     //   }
//     // }
//     let score = line[4];
//     line = line.slice(0, 4).join("");
//     for (j = 0; j < info_arr.length; j++) {
//       if (info_arr[j].includes(line)) {
//         temp.push(info_arr[j][0]);
//       }
//     }
//     console.log("line : " + line);
//     console.log("temp : " + temp);
//     console.log("score : " + score);
//     for (j = 0; j < temp.length; j++) {
//       if (temp[j] >= score) {
//         answer[i]++;
//       } else {
//         break;
//       }
//     }
//   }
//   console.log(answer);
//   return answer;
// }
