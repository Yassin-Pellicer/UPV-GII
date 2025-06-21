// Ejemplo de funciones y variables globales y locales
// Lee dos numeros (0 <= (x, y) < 10) y obtiene (x+y/2)
//-----------------------------------------------------
int a[10];

bool inicializa (int x)
{ int i;
  for (i=0; i < x; i=i+1)  a[i] = i;

  return true;
}

int suma(int x, int y)
{ int a;
  a = x+y;
  
  return a;
}

int division(int x, int y)
{
  return x/y;
}

int x; int y;

int main()
{ bool ok; 
  
  ok = ! inicializa(10);

  for (ok = !inicializa(10); ! ok ; ) {
    read(x); read(y);
    if (((x>=0) && (x<10)) && ((y>=0) && (y<10))) ok = true;
    else {}
  }
  
  print(division(suma(a[x], y), 2));
  
  return 0;
}
