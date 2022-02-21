function solution(k, m, names, amounts) {
  let answer=0
  let state=0
  for(let i=0;i<names.length;i++){
    names[i]=names[i].toUpperCase()
  }
  
  let prev=names[0]
  let count=0
  for(let j=1;j<names.length;j++){
    if(amounts[j]>=m){
      answer++
      state=1
    }
    if(names[j]===prev){
      count++
      if(count>=k-1&&state===0){
        answer++
      }
    }
    else{
      count=0
    }
    state=0
    prev=names[j]
  }
  return answer;
}