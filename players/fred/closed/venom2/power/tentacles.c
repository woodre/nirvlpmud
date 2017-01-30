#include "../defs.h"

status main(string str, object PO, object User)
{
  int w,x,y,z,h,i;
  w = (int)PO->query_t_burn();
  x = (int)PO->query_t_regen();
  y = (int)PO->query_t_attack();
  z = (int)PO->query_t_defend();
  
  for(i = 0; i < 10; i++)
  {
    if(w)
    {
      TOU PO->query_color()+(i+1)+NORM+"] "+BOLD+"Assigned to: Burnoff..."+NORM+"\n");
      w--;
    }
    if(x)
    {
      TOU PO->query_color()+(i+1)+NORM+"] "+BOLD+"Assigned to: Regenration..."+NORM+"\n");  
      x--;
    }
    if(y)
    {
      TOU PO->query_color()+(i+1)+NORM+"] "+BOLD+"Assigned to: Attack..."+NORM+"\n");
      y--;
    }
    if(z)
    {
      TOU PO->query_color()+(i+1)+NORM+"] "+BOLD+"Assigned to: Defend..."+NORM+"\n");
      z--;
    }
  }
  if((w+x+y+z) < 10)
  {
    for(i = 0; i < (10 - (w+x+y+z)); i++)
    {
      TOU PO->query_color()+(i+1)+NORM+"] "+BOLD+"Assigned to: Nothing..."+NORM+"\n");   
    }
  }
  return 1;
}
