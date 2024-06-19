const maxArea = (height) => {
  let left = 0;
  let right = height.length - 1;
  let max = 0;

  while (left < right) {
    max = Math.max(max, Math.min(height[left], height[right]) * (right - left));
    if (height[left] < height[right]) left++;
    else right--;
  }
  return max;
};

console.log(maxArea([1, 4, 6, 8, 2, 5, 4, 5, 3, 7]));
