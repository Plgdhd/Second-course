let x = 0, y = 0;

for(let i = 0; i<10; ++i){

    let answer = 0; 

    answer = Number(prompt("Выберите направление: 1 -- left, 2 - right, 3 - up, 4 - down"));
    switch(answer){
        case 1: 
            x++;
            break;
        case 2:
            x--;
            break;
        case 3:
            y++;
            break;
        case 4:
            y--; 
            break;
        default:
            break;
    }
}

alert(`Координаты после 10 шагов: (${x}, ${y})`);
