const numbers=[4,1,2,1];
let answer = 0;

function DFS(numbers, target, level, sum){
    if(level===numbers.length){
        if(sum+numbers[numbers.length-1]===target){
            answer++
            console.log(sum+'+'+numbers[numbers.length-1])
        }
        if(sum-numbers[numbers.length-1]===target){
            answer++
            console.log(sum+'-'+numbers[numbers.length-1])
        }
        return 0
    }
    else{
    DFS(numbers, target, level+1, sum+numbers[level-1])
    DFS(numbers, target, level+1, sum-numbers[level-1])
    }
}

function solution(numbers, target) {
    DFS(numbers, target, 1, 0)
    console.log(answer)
}

solution(numbers,4)