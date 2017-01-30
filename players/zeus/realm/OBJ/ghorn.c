inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
reset(arg){
	  if(arg) return;

  set_id("horn");
  set_alias("horn");
  set_short("A gurther horn");
  set_long(
"This horn has come from the head of a gurther.  At the base it is\n"+
"deeply cracked, and there are small cracks running all along it.\n"+
"It is very rare and valuable despite the bad condition that it's in.\n"+
"If only you could find someone willing to buy it off you.\n");
  set_weight(1);
  set_value(1200);
}
