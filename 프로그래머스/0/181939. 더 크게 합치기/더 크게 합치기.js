const solution = (a,b) => {
    const fir = ~~(a.toString()+b.toString());
    const sec = ~~(b.toString()+a.toString());
    return fir>sec?fir:sec;
};