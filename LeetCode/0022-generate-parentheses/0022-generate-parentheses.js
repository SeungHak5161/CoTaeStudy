/**
 * @param {number} n
 * @return {string[]}
 */
const generateParenthesis = (n) => {
  const result = [];
  const dfs = (idx, payload) => {
    const left = payload.split("").filter((e) => e === "(").length;
    const right = payload.split("").filter((e) => e === ")").length;

    if (idx === n * 2) {
      if (payload.at(-1) === ")") result.push(payload);
    } else {
      ["(", ")"].forEach((p) => {
        if (left >= right && left <= n) dfs(idx + 1, payload + p);
      });
    }
  };
  dfs(1, "(");
  return result;
};