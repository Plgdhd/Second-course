function cubesOfN(n){
    let sum = 0;
    for(let i = 0; i < n; ++i){
        sum += i**3;
    }
    return sum;
}

console.log("cubes of N: " + cubesOfN(7));