solution("000000201", "12310000");
function solution(X, Y) {
  let answer = "";
  let x = X.split("");
  let y = Y.split("");
  let union = [];
  x.map((e) => {
    if (y.includes(e)) {
      union.push(e);
      y.splice(y.indexOf(e), 1);
    }
  });
  union.sort((a, b) => {
    return b - a;
  });
  if (union.length === 0) {
    return "-1";
  }
  console.log(union);
  answer = String(Number(union.join("")));
  console.log(answer);
  return answer;
}
