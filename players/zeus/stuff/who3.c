inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
reset(arg){

  set_short("A who3 pill");
  set_long(
"This is a small white pill.  The shell is made of a solid white plastic.\n"+
"Written in black lettering on the pill are the letters:  ZP1\n");
  set_weight(1);
  set_value(0);
}

id(str){ return str == "pill" || str == "who3"; }

init(){  
  ::init();
  add_action("who3", "who3");
}


who3(str)
{
  int sz, x, y, swap;
  string g;
  object *a, atemp;
  a = users();
  sz = sizeof(a);
  swap = 1; /* a swap was made */

  while(swap)
  {
    swap = 0;
    for(x = 0; x < sz; x++)  /* count through a [users] */
    {
      if(a[x]->query_level() < 20)  /* if not a wizard */
      {
        if((x + 1) < sz) /* if there is one more element in a */
        {
          if(a[x]->query_exp() < a[x+1]->query_exp())  /* 2 has more xp */
          {
            atemp = a[x+1];  /* swap the two */
            a[x+1] = a[x];
            a[x] = atemp;
            swap = 1;
          }
        }
      }
      else /* if it is a wizard */ 
      {
        swap = 1;
        if((x + 1) < sz) /* if there is one more element in a */
        {
          for(y = x; y < sz; y++)
          {
            if((y + 1) < sz) /* if there is one more element in a */
              a[y] = a[y+1];
            else
              sz--;  /* make it think array is 1 less */
          }
        }
        else /* no more elements in the a array */
          sz--;  /* make it think array is 1 less */
      }
    }
    for(x = 0; x < sz; x++)
    {
      if((x + 1) < sz) /* if there is one more element in a */
      {
        if(a[x]->query_exp() < a[x+1]->query_exp())  /* 2 has more xp */
        {
          atemp = a[x+1];  /* swap the two */
          a[x+1] = a[x];
          a[x] = atemp;
        }
      }
    }
  }

  for(x = 0; x < sz; x++)
  {
    if(x < 9){
      write((x+1)+".  "+pad(a[x]->query_name(),12)+" "+
          pad(a[x]->query_exp(),10)+
          pad(((g = a[x]->query_guild_name()) ? capitalize(g) : "None"),12));
      if(environment(a[x]))
        write(file_name(environment(a[x]))+"\n");
      else
        write("\n");
    }
    else {
      write((x+1)+".  "+pad(a[x]->query_name(),11)+" "+
          pad(a[x]->query_exp(),10)+
          pad(((g = a[x]->query_guild_name()) ? capitalize(g) : "None"),12));
      if(environment(a[x]))
        write(file_name(environment(a[x]))+"\n");
      else
        write("\n");
    }
  }

  return 1;
}


