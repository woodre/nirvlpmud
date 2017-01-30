#include "../x.h"

int cmd_scamper()
{
 string *x, *y, huh;
 int    a, b;
 object z;
 write("You scamper around wildly!\n");
 say("Frothing at the mouth, "+(string)TP->QN+
  " scampers about wildly!\n", TP);

 x = (string*)ENVTP->query_dest_dir();
 if(!x) x = ({ });
 b = sizeof(x);
 y = ({ });
 for(a=1;a<b;a+=2)
  y += ({x[a]});
 
 if(sizeof(y))
 huh = y[random(sizeof(y))];

 z = ENVTP;
 if(stringp(huh))
 command(huh, TP);

 if(z != ENVTP)
  write(HIK+"\n\tYou run "+huh+"!\n\n"+NORM);

 return 1;
}
