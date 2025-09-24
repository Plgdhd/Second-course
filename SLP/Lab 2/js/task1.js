
let operation = prompt("Введите операцию");

function basicOperation(operation, value1, value2){
    switch(operation){
        case '+':
            return value1 + value2;
            break;
        case '-':
            return value1 - value2;
        case '*':
            return value1 * value2;
        case '/':
            return value1 / value2;
    }
}

alert(basicOperation(operation ,42, 10));


