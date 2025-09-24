function compare(arr1, arr2){
    const arr3 = arr1.filter(n => !arr2.includes(n));
    return arr3;
}

let myArr1 = ["beloded", "123", "jopa", "---"];
let myArr2 = ["lll", "beloded", "123", "const", "7776"];

console.log(compare(myArr1, myArr2));