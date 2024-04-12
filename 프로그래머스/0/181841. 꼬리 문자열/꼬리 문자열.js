const solution = (str_list, ex) => {
    return str_list.map((item) => {
        if(!item.includes(ex)) return item;
    }).join("");
}