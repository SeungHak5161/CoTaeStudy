solution(6, 6, ["AABBEE", "AAAEEE", "VAAEEV", "AABBEE", "AACCEE", "VVCCEE"]);
function matrix(m, n, initial) {
  let a,
    i,
    j,
    mat = [];
  for (i = 0; i < m; i += 1) {
    a = [];
    for (j = 0; j < n; j += 1) {
      a[j] = initial;
    }
    mat[i] = a;
  }
  return mat;
}
function check(arr, i, j, num, retVal) {
  if (j < arr[i].length) {
    if (arr[i][j] === arr[i + 1][j] && arr[i][j] === num) {
      retVal = check(arr, i, j + 1, arr[i][j], retVal + 1);
    }
  }
  return retVal;
}
function solution(m, n, board) {
  let answer = 0;
  let arr = matrix(m, n, 0);
  let delQ = [];
  let flag = true;
  for (let j = 0; j < n; j++) {
    for (let i = 0; i < m; i++) {
      arr[i][j] = board[i][j];
    }
  }
  while (flag) {
    // 행, 마지막 행은 탐색하지 않음(전 행 탐색에서 확인됨)
    for (let i = 0; i < m - 1; i++) {
      // 열
      for (let j = 0; j < n; j++) {
        let retVal = 0;
        // 행과 행+1의 값이 같으면서 X가 아니면
        if (arr[i][j] === arr[i + 1][j] && arr[i][j] !== "X") {
          // 다음 열도 같은지 확인하고 1*2가 몇 개 반복되는지 리턴
          retVal = check(arr, i, j + 1, arr[i][j], 1);
          // 2*2 이상이 존재할때
          if (retVal > 1) {
            // 삭제할 영역의 시작 x,y좌표와 길이 저장
            delQ.push([i, j, retVal]);
          }
        }
      }
    }
    console.log(delQ);
    // 삭제할 영역이 없으면 종료플래그 값 변경
    if (delQ.length === 0) {
      flag = false;
    }
    // 삭제할 영역의 개수
    for (let i = 0; i < delQ.length; i++) {
      // 해당 삭제 영역의 길이
      for (let j = 0; j < delQ[i][2]; j++) {
        arr[delQ[i][0]][delQ[i][1] + j] = "X";
        arr[delQ[i][0] + 1][delQ[i][1] + j] = "X";
      }
    }
    // 삭제할 영역 초기화
    delQ = [];
    // 행 수 만큼 반복(효율적인 방법이 안떠올라서 안전하게 해둠)
    for (let p = 0; p < m; p++) {
      for (let i = 1; i < m; i++) {
        for (let j = 0; j < n; j++) {
          // 해당 좌표값이 X이면
          if (arr[i][j] === "X") {
            // 해당 좌표를 행-1의 값으로 바꾸고
            arr[i][j] = arr[i - 1][j];
            // 해당좌표 행-1의 값을 X로 바꿈(삭제 개념)
            arr[i - 1][j] = "X";
          }
        }
      }
    }
    // 같은 방식인데 밑에서부터
    //   for (let p = 0; p < m; p++) {
    //     for (let i = m - 1; i > 0; i--) {
    //       for (let j = 0; j < n; j++) {
    //         if (arr[i][j] === "X") {
    //           console.log(i, j);
    //           arr[i][j] = arr[i - 1][j];
    //           arr[i - 1][j] = "X";
    //         }
    //       }
    //     }
    //   }
  }
  console.log(arr);
  // 전체 탐색하며 X 개수(삭제영역) 개수 세기
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      if (arr[i][j] === "X") {
        answer++;
      }
    }
  }
  console.log(answer);
  return answer;
}
