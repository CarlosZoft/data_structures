DB = [];

var Fib1 = (seq) => {
  if(seq<2)
    return seq;
  if(DB[seq] !== undefined)
    return DB[seq];

  return DB[seq] = (Fib1(seq-1)+Fib1(seq-2));
}

module.exports = Fib1;