// Calcula el maximo comun divisor de dos numeros > 0.
// Por ejemplo, la salida esperada para 42 y 56 es 14.
// 450,360->90; 150,180->30; 
//----------------------------------------------------
int max(int x, int y)
{ int z;
  if (x < y) z = y;
  else       z = x;
  return z;
}

int min(int x, int y)
{ int z;
  if (x < y) z = x;
  else       z = y;
  return z;
}

int mcd(int x, int y)
{ int z;
  if (x == y) z = x;
  else        z = mcd(min(x,y-x),max(x,y-x));
  return z;
}

int main()
{ int x; int y; bool z=true;

  for (; z ;) {
    read(x);  read(y);
    if ((x>0)&&(y>0)) {
      if (x < y) print(mcd(x, y));
      else       print(mcd(y, x));
      z=false;
    }
    else {}
  }
  
  return 0;
}
