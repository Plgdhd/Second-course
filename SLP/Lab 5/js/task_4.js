var first = 1;
let second = 2;
const third = 3;

function beloded(){
    return "Комиссия со Смеловым";
}

console.log(window.first);
console.log(window.second);
console.log(window.third);
console.log(window.beloded());

window.first = 1489;
window.beloded = function() {
  return "Вы отчислены дааааааааааааааааааа";
};

console.log(first);
console.log(beloded());

window.second = 777;
console.log(second);
console.log(window.second);