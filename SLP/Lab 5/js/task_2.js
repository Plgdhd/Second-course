function volume(a){
    return function(b){
        return function(c){
            return a * b * c;
        };
    };
}

alert(volume(2)(3)(4));