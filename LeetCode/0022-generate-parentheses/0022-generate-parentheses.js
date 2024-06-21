/**
 * @param {number} n
 * @return {string[]}
 */
const generateParenthesis = (n) => {
  const result = [];
  const dfs = (payload) => {
    const left = payload.split("").filter((e) => e === "(").length;
    const right = payload.split("").filter((e) => e === ")").length;

    if (payload.length === n * 2) {
      if (payload.at(-1) === ")") result.push(payload);
    } else {
      ["(", ")"].forEach((p) => {
        if (left >= right && left <= n) dfs(payload + p);
      });
    }
  };
  dfs("(");
  return result;
};