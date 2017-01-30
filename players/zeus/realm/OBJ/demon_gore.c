inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"  /* value 500+random(2000) */

reset(arg){

  string x;
  int y;
  y = random(6);
  if(0 == y) x = RED+"A pile of gore"+NORM;
  else if(1 == y) x = RED+"Some demonic gore"+NORM;
  else if(2 == y) x = "A pile of gore";
  else if(3 == y) x = "Steamy demon gore";
  else if(4 == y) x = HIR+"A pile of bloody gore"+NORM;
  else if(5 == y) x = HIR+"A pile of steamy demon gore"+NORM;

  set_id("pile of gore");
  set_short(x);
  set_long(
"This is a very disgusting pile of gore that came from inside a demon.\n"+
"It is very runny, warm, and hard to keep a hold of.  It makes you\n"+
"feel a little queasy just having it near you.\n");
  set_weight(1);
  set_value(1);
}

id(str){ return str == "gore" || str == "pile of gore" ||
   str == "bloody gore" || str == "demon gore" || str == "pile" ||
   str == "hot and yummy gore"; }

query_real_mccoy() { return 1; }
