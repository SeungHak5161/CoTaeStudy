const reqs = [
  "DEPOSIT 3a 10000",
  "CREATE 3a 300000",
  "WITHDRAW 3a 150000",
  "WITHDRAW 3a 150001",
];

function solution(reqs) {
  let answer = [];
  let spltArr = [];
  let account = [];

  reqs.map((e) => {
    spltArr.push(e.split(" "));
  });
  console.log(spltArr);
  spltArr.map((e) => {
    switch (e[0]) {
      case "CREATE":
        if (account.find((el) => el.id === e[1])) {
          answer.push(403);
        } else {
          account.push({ id: e[1], balance: e[2] });
          answer.push(200);
        }
        break;
      case "DEPOSIT":
        let found1 = account.find((el) => el.id === e[1]);
        if (found1) {
          found1.balance += e[2];
          answer.push(200);
        } else {
          answer.push(404);
        }
        break;
      case "WITHDRAW":
        let found2 = account.find((el) => el.id === e[1]);
        if (found2) {
          if (found2.balance < e[2]) {
            answer.push(403);
          } else {
            found2.balance -= e[2];
            answer.push(200);
          }
        } else {
          answer.push(404);
        }
        break;
    }
  });
  console.log(account);
  return answer;
}

console.log(solution(reqs));
