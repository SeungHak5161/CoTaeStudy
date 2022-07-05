// solution([
//   [1, 0, 1, 1, 1],
//   [1, 0, 1, 0, 1],
//   [1, 0, 1, 1, 1],
//   [1, 1, 1, 0, 1],
//   [0, 0, 0, 0, 1],
// ]);
// function find(arr, x, y) {
//   let retVal = [];
//   if (arr[x + 1][y] === 1) {
//     retVal.push([x + 1, y]);
//   }
//   if (arr[x][y + 1] === 1) {
//     retVal.push([x, y + 1]);
//   }
//   if (x - 1 > 0 && arr[x - 1][y] === 1) {
//     retVal.push([x - 1, y]);
//   }
//   if (y - 1 > 0 && arr[x][y - 1] === 1) {
//     retVal.push([x, y - 1]);
//   }
//   return retVal;
// }
// function check(arr, x, y, count) {
//   let cases = [];
//   if (x === arr.length - 1 && y === arr[0].length - 1) {
//     return count;
//   }
//   let route = find(arr, x, y);
//   if (route.length === 0) {
//     return count + 10000;
//   }
//   for (i = 0; route.length > i; i++) {
//     cases.push(check(arr, route[i][0], route[i][1], count + 1));
//   }
//   return (cases = Math.min(...cases));
// }
// function solution(arr) {
//   let count = check(arr, 0, 0, 1);
// }

solution([
  [1, 0, 1, 1, 1],
  [1, 0, 1, 0, 1],
  [1, 0, 1, 1, 1],
  [1, 1, 1, 0, 1],
  [0, 0, 0, 0, 1],
]);
// solution([
//   [1, 0, 1, 1, 1, 1, 1],
//   [1, 0, 1, 0, 1, 0, 1],
//   [1, 0, 1, 1, 1, 0, 1],
//   [1, 1, 1, 0, 1, 0, 1],
//   [0, 0, 1, 0, 0, 0, 1],
//   [0, 0, 1, 0, 1, 0, 1],
//   [0, 0, 1, 1, 1, 0, 1],
// ]);
// solution([
//   [1, 1, 1, 1, 1, 0, 0],
//   [1, 0, 1, 0, 1, 1, 1],
//   [1, 1, 1, 1, 1, 0, 1],
// ]);
function check(matrix) {
  let newX, newY;
  let xys = [[0, 0, 1]];
  matrix[0][0] = 0;
  rowD = [0, 0, 1, -1];
  colD = [1, -1, 0, 0];
  while (xys.length) {
    let [y, x, count] = xys.shift();
    for (i = 0; i < 4; i++) {
      newY = y + colD[i];
      newX = x + rowD[i];
      if (
        newX >= 0 &&
        newY >= 0 &&
        newY <= matrix.length - 1 &&
        newX <= matrix[0].length - 1 &&
        matrix[newY][newX] === 1
      ) {
        if (newY === matrix.length - 1 && newX === matrix[0].length - 1) {
          return count + 1;
        }
        matrix[newY][newX] = 0;
        xys.push([newY, newX, count + 1]);
      }
    }
  }
  return -1;
}
function solution(arr) {
  let matrix = [];
  let a;
  for (i = 0; i < arr.length; i++) {
    a = [];
    for (j = 0; j < arr[0].length; j++) {
      a.push(arr[i][j]);
    }
    matrix.push(a);
  }
  return check(matrix);
}
