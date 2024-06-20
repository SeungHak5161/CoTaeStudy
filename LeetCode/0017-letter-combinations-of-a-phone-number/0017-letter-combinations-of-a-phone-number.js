const letterCombinations = (digits) => {
  const map = {
    2: ["a", "b", "c"],
    3: ["d", "e", "f"],
    4: ["g", "h", "i"],
    5: ["j", "k", "l"],
    6: ["m", "n", "o"],
    7: ["p", "q", "r", "s"],
    8: ["t", "u", "v"],
    9: ["w", "x", "y", "z"],
  };
  const result = [];
  const dfs = (idx, payload) => {
    if (idx === digits.length) {
      if (payload !== "") result.push(payload);
    } else {
      map[digits[idx]].forEach((char) => {
        dfs(idx + 1, payload + char);
      });
    }
  };
  dfs(0, "");
  return result;
};