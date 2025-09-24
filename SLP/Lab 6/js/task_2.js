let user = {
    name: "Monkey D Luffy",
    age: 19
};

let admin = {
    root: "Admin",
    nickname: ["Joy Boy", "King of the pirates"],
    ...user
};

console.log(admin);
