const a = ["bbbbbbbbbaabababbbbabbbbb"];

function solution(a) {
  let answer = [];
  a.map((e) => {
    let arr = e.split("");
    while (true) {
      console.log(arr);
      if (arr.join("") === "a") {
        answer.push(true);
        break;
        // 좌변 a제거
      } else if (arr[0] === "a") {
        arr.shift();
        // 우변 a제거
      } else if (arr[arr.length - 1] === "a") {
        arr.pop();
        // 좌우변이 모두 b이고 개수가 같을때(가운데 a가 있을 때), 가운데 a개수와 같다면 제거 / 다르면 false
      } else if (
        arr[0] === "b" &&
        arr[arr.length - 1] === "b" &&
        arr.filter((e) => e === "a").length > 0
      ) {
        let i = 0;
        while (arr[i] === "b" && arr[arr.length - 1 - i] === "b") {
          i += 1;
        }
        if (arr.filter((e) => e === "a").length === i) {
          arr.splice(0, i);
          arr.splice(arr.length - i, i);
        } else {
          answer.push(false);
          break;
        }
      } else {
        answer.push(false);
        console.log("------------------------");
        break;
      }
    }
  });
  return answer;
}

console.log(solution(a));
// str.split('').reverse().join('')
