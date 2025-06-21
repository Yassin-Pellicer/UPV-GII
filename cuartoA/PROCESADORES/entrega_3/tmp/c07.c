// Criba de Eratostenes: calcula los numeros primos menores 
// que un cierto numero  1 < n < 150.
//---------------------------------------------------------
bool a[150];

int main()
{ int max;     // Numero maximo para buscar
  int n=2;     // Siguiente numero primo
  int i;
  bool OK;

  // Comprobacion de que es un numero admisible
  for (OK = false; ! OK ;) {
    read(max);
    if ((max > 1) && (max < 150)) OK = true; else {}
  }
  
  // Inicializacion del vector de posible primos
  for (i=2; i <= max; i=i+1) a[i] = true;

  // Criba de Earatostenes
  for (OK = false; ! OK ;) {
    // Eliminacion de los multiplos de "n"
    for (i = 2; (i * n) <= max; i=i+1) a[i * n] = false; 
    // Busqueda del siguiente primo
    for (i = n + 1;  (! a[i] && (i <= max)); i=i+1) {}
    // Control del fin (n * n > max)
    if ((i * i) <= max) n = i;
    else OK = true;
  }

  // visualizacion de los primos menores que "max"
  for (i=2; i <= max; i=i+1)
    if (a[i]) print(i); else {}
  
  return 0;
}
