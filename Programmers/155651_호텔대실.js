const roomList = []
for (let i = 0; i <= 23 * 60 + 59; i++) {
  roomList.push(0)
}

function unableTime (enter, leave) {
  return (leave[0] - enter[0]) * 60 + (leave[1] - enter[1]) + 10
}

function book (e) {
  const enter = e[0].split(':')
  const leave = e[1].split(':')
  const length = unableTime(enter, leave)
  const enterTime = Number(enter[0] * 60) + Number(enter[1])
  let preparedTime = enterTime + length
  console.log(e)
  console.log(length)
  console.log(enterTime, preparedTime)

  if (preparedTime > 1440) { preparedTime = 1440 } // 완료 시간이 00시가 넘는 경우 에러 예외처리
  for (let i = enterTime; i < preparedTime; i++) {
    roomList[i]++
  }
}

function solution (bookTime) {
  while (bookTime.length !== 0) {
    book(bookTime.shift())
  }

  console.log(roomList)
  console.log(Math.max(...roomList))
  return Math.max(roomList)
}

const bookList = [["15:00", "17:00"], ["16:40", "18:20"], ["14:20", "15:20"], ["14:10", "19:20"], ["23:50", "23:55"]]
solution(bookList)