var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');
let result = 0, i = 0;
let valor = parseInt(lines.shift());
while(1){
  if(valor === 0)break;
  i = 0;
  while(i < 5){

      if(valor%2===0){
        result+=valor;
        valor+=2;
        i++;
      }

      else {
        valor++;
      }
     
  }
  console.log(parseInt(result));
  result = 0;
  valor = parseInt(lines.shift());
}
