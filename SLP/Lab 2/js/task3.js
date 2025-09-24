function sumOfArray(array){

    let sum = 0;
    array.forEach(el => sum += el);
    let arithm = sum / array.length;
    return arithm;
}


let numbers = [1, 2, 3, 4, 5, 6, 7];
console.log("arithmArr([1, 2, 3, 4, 5, 6, 7]) = " + sumOfArray(numbers));
