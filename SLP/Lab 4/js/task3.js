class Product{
    constructor(name, amount, price){
        this.name = name;
        this.amount = amount;
        this.price = price;
    }
}

function addProduct(cart, id, name, amount, price){
    cart.products.set(id, {name, amount, price});    
}

function removeProductById(cart, id){
    cart.products.delete(id);
}

function removeProductByName(cart, name){
    for(let [id, product] of cart.products.entries()){
        if(product.name.toLowerCase() === name.toLowerCase()){
            cart.products.delete(id);
        }
    }
}

function updateAmount(cart, id, amount) {
  let product = cart.products.get(id);
  if (product) {
    product.amount = amount;
  }
}

function updatePrice(cart, id, newPrice) {
  let product = cart.products.get(id);
  if (product) {
    product.price = newPrice;
  }
}

function getProductCount(cart) {
  return cart.products.size;
}

function getTotalCost(cart) {
  let sum = 0;
  for (let product of cart.products.values()) {
    sum += product.price * product.amount;
  }
  return sum;
}

function printCart(cart) {
  for (let [id, product] of cart.products.entries()) {
    console.log(` ${id}. ${product.name} (количество: ${product.amount}, цена: ${product.price})`);
  }
  console.log(`Всего позиций: ${getProductCount(cart)}`);
  console.log(`Общая сумма: ${getTotalCost(cart)}`);
}

let cart = { products: new Map() };

addProduct(cart, 1, "beloded", 1, 232);
addProduct(cart, 1, "me", 5, 10);
addProduct(cart, 2, "Jopa", 3, 15.5);
addProduct(cart, 3, "Kakashki", 2, 11);

console.log("Дикая корзина:");
printCart(cart);

updateAmount(cart, 1, 10);
updatePrice(cart, 2, 20);

console.log("\nКорзина сейчас:");
printCart(cart);

removeProductByName(cart, "beloded");
console.log("\nУдалили белодеда, просрочен:");
printCart(cart);

