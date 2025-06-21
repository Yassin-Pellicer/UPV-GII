
//---------------------------------------------------------
int main ( )
{
  int b;
  int c;

  c = -1;
  b = 2;

  switch c { less 
		{ switch b { less { print(11); } equal {print(12);} greater {print(13);  }  } }
	     equal {print(2);} 
	     greater {print(3);  }   
 	   }
 // imprime  13  
  return 0;
}
