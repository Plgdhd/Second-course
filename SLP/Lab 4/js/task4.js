// Создаём WeakMap для кэша
const cache = new WeakMap();

function heavyCalculation(obj) {
  if (cache.has(obj)) {
    return cache.get(obj);
  }

  let result = obj.value * obj.value; 

  cache.set(obj, result);

  return result;
}

let  first = { value: 52 };
let second = { value: 42 };

console.log(heavyCalculation(first));
console.log(heavyCalculation(second)); 

console.log(heavyCalculation({value: 23})); 
console.log(heavyCalculation(second )); 
