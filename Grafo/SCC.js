class Graph {

    constructor(vertex) {
      this.vertex = vertex;
      this.listAdj = new Map(); // Grafo Original
      this.listAdjInverse = new Map(); // Grafo inverso
      this.time = 0; 
      this.prev = [];
      this.post = [];
      this.groups = new Map(); // SCC;
    }
    // Get 
    getKeys() {
      return this.lis1tAdj.keys();
    }
    getValues(i) {
      return this.listAdj.get(i);
    }
    getGroups() {
      return this.groups;
    }
    // Adicionando Vertice;
    addVertex(v) {
      this.listAdj.set(v, []);
      this.listAdjInverse.set(v, []);
    }
    // Adicionando Arestas;
    addEdge(v, w) {
      this.listAdjInverse.get(w).push(v);
      this.listAdj.get(v).push(w);
    }
    // Auxiliar 
    print() {
      var vertex = this.listAdj.keys();
      console.log('VERTEX -> LIST\n');
      for (var i of vertex) {
        var listAdj = this.listAdj.get(i);
        var sum = '';
        for (var j = 0; j < listAdj.length; ++j) {
          sum += listAdj[j];
          if (j != listAdj.length - 1) sum += ' && ';
        }
        console.log(i + ' -> ' + sum);
      }
    }
    printInverse() {
      var vertex = this.listAdjInverse.keys();
      console.log('VERTEX -> LIST\n');
      for (var i of vertex) {
          var listAdj = this.listAdjInverse.get(i);
          var sum = '';
          for (var j = 0; j < listAdj.length; ++j) {
            sum += listAdj[j];
            if (j != listAdj.length - 1) sum += ' && ';
          }
        console.log(i + ' -> ' + sum);
      }
    }
  
    //DFS -> Para setar pre e post 
    dfs() {
        this.time = 1;
        let visitados = [];
        var vertex = this.listAdj.keys();  
        for (var i of vertex) {
            if(!visitados[i])this.path(i, visitados)
        }
    }
    path(v, visitados) {
        visitados[v] = true;
        this.prev[v] = this.time;
        this.time++;
        var get_values = this.listAdj.get(v);
      
        for (var w in get_values) {
            var value = get_values[w];
            if (!visitados[value]) this.path(value, visitados);
        }
        this.post[v] = {time : this.time, node : v};
        this.time++;
    }
  
    // Ordenando Post obtidos DFS 
    timeSorted(){
  
      var sortable = [];
      for (var i in this.post) {
          sortable.push(this.post[i]);
      }
      sortable.sort(function(a, b) {
          return a.time - b.time;
      });
      for (var j=0; j<sortable.length ; ++j){
          sortable[j] = sortable[j].node;
      }
      return sortable;
      
    }
    
    // DFS no grafo inverso;
    dfsInverseGraph() {
        var i = 0;
        var aux = this.timeSorted();
        let visitadosInverse = [];
        while (aux[0] != undefined){ 
          var v = aux.pop();
          
          if (!visitadosInverse[v]) 
          {   
              this.groups.set(i, []);
              this.pathInverse(v, visitadosInverse, i);
              i++;
          }
        } 
    }
    pathInverse(v, visitados, i) {
        visitados[v] = true; 
        this.groups.get(i).push(v);
        
        var get_values = this.listAdjInverse.get(v);
        for (var w in get_values) {
            var value = get_values[w];
            if (!visitados[value]) this.pathInverse(value, visitados, i);
        }
    }
  }
  
  module.exports = Graph;