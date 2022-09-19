// setTimeout을 Promise처럼 사용하는 법에 대한 질문을 받았었음.
// 아래 방식처럼 Promise 안에 setTimeout을 넣고 resolve를 호출하는 방식이 맞는지 가능하면 물어보기

function func(n) {
  console.log("start");
  new Promise((resolve) => {
    setTimeout(() => {
      console.log("timeout");
      resolve(n);
    }, 1000);
  }).then((res) => {
    console.log(res);
    func(res + 1);
  });
}

func(0);
