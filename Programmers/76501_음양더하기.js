function solution(absolutes, signs) {
  let answer = 0;
  for (i = 0; i < signs.length; i++) {
    answer += absolutes[i] * (signs[i] === true ? 1 : -1);
    console.log(answer);
  }
  return answer;
}
