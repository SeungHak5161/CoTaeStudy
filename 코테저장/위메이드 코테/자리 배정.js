function solution(n, k) {
  let answer = [];
  let board = [];
  let charge = [];
  for (let i = 0; i < n; i++) {
    let column = [];
    for (let j = 0; j < n; j++) {
      column.push(n * n);
    }
    board.push(column);
  }
  let s = 1;
  board[0][0] = 0;
  charge.push([0, 0]);

  while (s < k) {
    // 거리 계산
    for (let i = 0; i < n; i++) {
      for (let j = 0; j < n; j++) {
        board[i][j] = Math.min(
          charge.map((e) => {
            return Math.abs(e[0] - i) + Math.abs(e[1] - j);
          })
        );
      }
    }

    // 최대 거리 찾기
    let max = Math.max(...board.flat());
    // 최대 거리의 좌표 찾기
    let farIdx = board.flat().indexOf(max);
    // console.log(board.flat(), max, farIdx);
    // 최대 거리의 좌표에 배정
    if (farIdx !== -1) {
      board[parseInt(farIdx / n)][farIdx % n] = 0;
      charge.push([parseInt(farIdx / n), farIdx % n]);
    }
    s++;
  }
  console.log(board);
  return answer;
}
console.log(solution(3, 9));
