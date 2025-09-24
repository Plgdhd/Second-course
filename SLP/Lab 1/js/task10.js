function makeSomeString(param1 = "def", param2, param3) {
    return param1 + " " + param2 + " " + param3;
}

let input = prompt("Введите третий параметр:");

let result = makeSomeString(undefined, "Второй", input);
alert("Результат: " + result);
