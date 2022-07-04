solution([
  [1, 2, 3, 5],
  [5, 6, 7, 8],
  [4, 3, 2, 1],
  [4, 4, 4, 50],
]);

function solution(land) {
  let max = 0;
  for (i = 1; i < land.length; i++) {
    land[i][0] += algo(land[i - 1][1], land[i - 1][2], land[i - 1][3]);
    land[i][1] += algo(land[i - 1][0], land[i - 1][2], land[i - 1][3]);
    land[i][2] += algo(land[i - 1][0], land[i - 1][1], land[i - 1][3]);
    land[i][3] += algo(land[i - 1][0], land[i - 1][1], land[i - 1][2]);
  }
  console.log(land);
  for (j = 0; j < land[0].length; j++) {
    if (land[land.length - 1][j] > max) {
      max = land[land.length - 1][j];
    }
  }
  console.log(max);
  return max;
}

function algo(a, b, c) {
  return Math.max(a, b, c);
}
