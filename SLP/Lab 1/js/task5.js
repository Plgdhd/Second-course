const teacher = "Белодед Николай Иванович";
const partsOfName = teacher.toLowerCase().split(" ");

let input = prompt("Введите имя или ФИО преподавателя:");

if (!input) {
    alert("Поле ввода пустое");
} else {
    input = input.trim().toLowerCase();
    const inputParts = input.split(" ");
    let isMatch = true;

    for (let i = 0; i < inputParts.length; ++i) {
        if (partsOfName.indexOf(inputParts[i]) === -1) {
            isMatch = false;
            break;
        }
    }
    
    if (isMatch) {
        alert("Введенные данные верные");
    } else {
        alert("Данные не верны");
    }
}
