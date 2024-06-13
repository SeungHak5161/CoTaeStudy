const solution = (s) => {
  const arr = s.split(" ");
  return arr.reduce((acc, cur, idx) => {
    if (cur === "Z" || arr[idx + 1] === "Z") return acc;
    return acc + Number(cur);
  }, 0);
};

solution("10 Z 20 Z 1");
