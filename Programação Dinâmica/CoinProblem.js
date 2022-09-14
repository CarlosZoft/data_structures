var coin = (opc , size , value) => {
  var table = new Array(value+1).fill(0);
  table[0] = 1;
  for (var i = 0; i < size; ++i){
      for (var j = opc[i]; j <= value; ++j)
          table[j] += table[j-opc[i]];
  }
  return table[value];
}

module.exports = coin;