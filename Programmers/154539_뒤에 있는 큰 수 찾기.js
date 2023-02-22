function solution (numbers) {
  // debugger
  // console.log(numbers)
  const answer = []
  numbers.forEach((e) => {
    let found;
    let i = 0;
    while (i <= numbers.length - 1) {
      if (e < numbers[i]) {
        found = numbers[i]
        break;
      }
      i++
    }
    // console.log(found)
    found ? answer.push(found) : answer.push(-1)
  })
  return answer
}

const numbers = [2, 3, 3, 5]
// const numbers = [9, 1, 5, 3, 6, 2]
console.log(solution(numbers))