// 시간초과 4개 core dumped 3개나와서 78.1
let N = 5;
let road = [
  [1, 2, 3],
  [1, 3, 1],
  [1, 5, 8],
  [2, 4, 5],
  [2, 3, 2],
  [3, 5, 2],
  [5, 4, 1],
];
let K = 7;
solution(N, road, K);

function makeTree(Head, road, N, K, numList) {
  let i = 0;
  road.forEach((e) => {
    // console.log(e, Head.num);
    if (e[0] === Head.num && Head.distance + e[2] <= K) {
      Head.insertChild({ num: e[1], distance: e[2] });
      if (numList.indexOf(e[1]) !== -1) {
        numList.splice(numList.indexOf(e[1]), 1);
      }
      makeTree(Head.children[i], road, N, K, numList);
      i++;
    }
  });
  i = 0;
}

function solution(N, road, K) {
  class makeNode {
    constructor({ num, distance }) {
      this.num = num;
      this.distance = distance;
      this.children = [];
    }
    insertChild({ num, distance }) {
      const childNode = new makeNode(num);
      childNode.num = num;
      childNode.distance = this.distance + distance;
      this.children.push(childNode);
    }
  }
  const Head = new makeNode({ num: 1, distance: 0 });

  let numList = [];
  let roadRev = [];
  for (let i = 1; i <= N; i++) {
    numList.push(i);
  }
  numList.shift();

  // 순차적으로 트리에 삽입하기 위해 정렬
  road.forEach((e) => {
    if (e[0] > e[1]) {
      let temp = e[0];
      e[0] = e[1];
      e[1] = temp;
    }
  });
  for (let i = 0; i < road.length; i++) {
    let temp = [];
    temp[0] = road[i][1];
    temp[1] = road[i][0];
    temp[2] = road[i][2];
    roadRev.push(temp);
  }
  let roads = [...road, ...roadRev];
  makeTree(Head, roads, N, K, numList);
  console.log(roads);
  console.log(Head);
  console.log(numList);
  console.log(N - numList.length);

  return N - numList.length;
}
