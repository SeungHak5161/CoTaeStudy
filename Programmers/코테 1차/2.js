solution(
  ["banana", "apple", "rice", "pork", "pot"],
  [3, 2, 2, 2, 1],
  [
    "chicken",
    "apple",
    "apple",
    "banana",
    "rice",
    "apple",
    "pork",
    "banana",
    "pork",
    "rice",
    "pot",
    "banana",
    "apple",
    "banana",
  ]
);
function solution(want, number, discount) {
  let answer = 0;

  let wants = [];
  for (let j = 0; j < number.length; j++) {
    for (let i = 0; i < number[j]; i++) {
      wants.push(want[j]);
    }
  }
  wants = wants.sort().toString();
  for (let j = 0; j < discount.length - 9; j++) {
    let available = [];
    for (let i = 0; i < 10; i++) {
      available.push(discount[j + i]);
    }
    available.sort();
    console.log(available);
    if (wants === available.toString()) {
      answer++;
    }
  }
  console.log(answer);
  return answer;
}
