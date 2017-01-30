inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
reset(arg){

  set_id("fur");
  set_alias("tuft");
  set_short("A tuft of brown bear fur");
  set_long(
"This small tuft of brown fur has come from the mighty Brown Bear\n"+
"known to reside in The Fallen Lands.  It has a pungent odor, and is\n"+
"rather dirty.  Fortunatly it is known to be very valuble, all one needs\n"+
"to do is find someone willing to 'barter' for it.\n");
  set_weight(1);
  set_value(100+random(3000));
}
