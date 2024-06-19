// const judgeSquareSum = (c) => {
//   const max = Math.floor(Math.sqrt(c));
//   for (let a = 0; a <= max; a++) {
//     const b = Math.sqrt(c - a * a);
//     if (b === parseInt(b)) return true;
//   }
//   return false;
// };

const judgeSquareSum = (c) => {
  const max = Math.floor(Math.sqrt(c));
  let a = 0;
  let b = max;
  while (a <= b) {
    const sum = a * a + b * b;
    if (sum === c) return true;
    if (sum < c) a++;
    else b--;
  }
  return false;
};

console.log(judgeSquareSum(2147482647));
