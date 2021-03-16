class Graph {

    constructor(vertex) {
      this.vertex = vertex;
      this.listAdj = new Map();
    }
  
    getKeys() {
      return this.listAdj.keys();
    }
    getValues(i) {
      return this.listAdj.get(i);
    }
    addVertex(v) {
      this.listAdj.set(v, []);
    }
    addEdge(v, w) {
      this.listAdj.get(v).push(w);
    }
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
    get Keys() {
      return this.listAdj.keys();
    }
    //bfs
  
    bfs(v) {
      var fila = [];
      var visitados = []; // vetor de visitados
  
      for (var i = 0; i < this.vertex; ++i) visitados[i] = false;
  
      fila.push(v);
      visitados[v] = true; // marca como visitado
  
      while (fila.length != 0) {
        var getElement = fila.shift();
        console.log(getElement); // Vertice atual
        var get_values = this.listAdj.get(getElement); // Get adjList
        for (var i in get_values) {
          var value = get_values[i];
          if (!visitados[value]) {
            //console.log(getElement);
            visitados[value] = true;
            fila.push(value);
          }
        }
      }
    }
    //dfs
  
    dfs(v) {
      var visitados = [];
      this.path(v, visitados);
    }
    path(v, visitados) {
      visitados[v] = true;
      console.log(v); // Vertice atual
  
      var get_values = this.listAdj.get(v);
  
      for (var w in get_values) {
        var value = get_values[w];
        if (!visitados[value]) this.path(value, visitados);
      }
    }
    
    //findPath
    findPath(origem, destino) {
      if (origem == destino) {
        return [origem, origem];
      }
  
      var fila = [origem],
        visitados = {},
        ant = {},
        aux = 0,
        steps = [];
  
      while (aux < fila.length) {
        var u = fila[aux];
        aux++;
  
        if (!this.listAdj.get(u)) {
          continue;
        }
  
        var get_values = this.listAdj.get(u);
        for (var i = 0; i < get_values.length; ++i) {
          var v = get_values[i];
          if (visitados[v]) {
            continue;
          }
          visitados[v] = true;
          if (v === destino) {
            steps = [v];
            while (u !== origem) {
              steps.push(u);
              u = ant[u];
            }
            steps.push(u);
            steps.reverse();
            return steps;
          }
          ant[v] = u;
          fila.push(v);
        }
      }
      return steps;
    }
  }