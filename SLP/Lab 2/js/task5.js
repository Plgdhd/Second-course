let n = prompt("Введите n");
let s = prompt("Введите строку");

function repeatString(n, s){
    let res = "";
    for(let i = 0; i < n; ++i){
        res+= s;
    }
    return res;
}

console.log("copyStr(3, 'Beloded') = " + copyStr(3, "Beloded"));