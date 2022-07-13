let N = 5;
let road = [
  [1, 2, 1],
  [2, 3, 3],
  [5, 2, 2],
  [1, 4, 2],
  [5, 3, 1],
  [5, 4, 2],
];
let K = 3;
solution(N, road, K);

function check(Head, road) {
  road.forEach((e) => {
    console.log(Head.num);
    if (e[0] === Head.num) {
      Head.insertChild({ num: e[1], distance: e[2] });
      check(Head.children[0], road);
    }
  });
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

  let roadRev = [];
  // 순차적으로 트리에 삽입하기 위해 정렬
  road.forEach((e) => {
    if (e[0] > e[1]) {
      let temp = e[0];
      e[0] = e[1];
      e[1] = temp;
    }
  });
  console.log(road);
  check(Head, road);
  console.log(Head);

  // return answer;
}
