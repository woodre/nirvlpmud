string color_string(string str) 
{
  string msg;
  switch(random(7)) 
  {
    case 0: msg = NORM+RED+str+NORM; break; 
    case 1: msg = NORM+BLU+str+NORM; break;
    case 2: msg = NORM+CYN+str+NORM; break;
    case 3: msg = NORM+MAG+str+NORM; break;
    case 4: msg = NORM+HIR+str+NORM; break;
    case 5: msg = NORM+HIB+str+NORM; break;
    case 6: msg = NORM+HIK+str+NORM; break;
  }
  return msg;
}