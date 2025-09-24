let a = parseFloat(prompt("Введите длину: "));
let b = parseFloat(prompt("Введите ширину: "));

function params(a, b){
    if(a == b){
        return (a * 2) + (b * 2);
    }
    else{
        return a * b;
    }
}

// const params = function(a, b){
//     if(a == b){
//         return (a * 2) + (b * 2);
//     }
//     else{
//         return a * b;
//     }
// }

// const params = (a, b) => (a === b ? 4 * a : a * b);

alert(params(a,b));