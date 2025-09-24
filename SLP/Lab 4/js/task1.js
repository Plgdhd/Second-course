let set = new Set();

for(let i = 0; i < 5; ++i){
    set.add(prompt("Введите товар "));
}

let choose = prompt("Выберите одну из операций:" +
        "\n1 -- добавить товар" + 
        "\n2 -- проверить наличие товара" + 
        "\n3 -- количество имеющегося товара");

switch(+choose){
    case 1: 
        alert(set.add(prompt("Введите товар")));
        break; 
    case 2:
        alert(set.has(prompt("Введите название товара")));
        break; 
    case 3: 
        set.forEach(e => console.log(e));
        break;
    default:
        alert("Неверный выбор")
}
