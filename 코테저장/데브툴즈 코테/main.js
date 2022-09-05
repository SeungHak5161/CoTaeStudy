const $target = document.querySelector(".calc-main");
$target.addEventListener("click", (e) => {
  const classType = e.target.className.split(" ").at(-1);
  if (classType === "btn-num") {
    const $btnNum = e.target.closest("div");
    const num = $btnNum.dataset.idx;
    console.log(num);
  } else if (classType === "btn-calc") {
  }
});
