#include "/players/linus/def.h"
inherit "obj/treasure.c";
id(str){ return str=="tail" || str=="eeyore's tail"; }
reset(arg) {
if(arg) return;
 set_short("Eeyore's tail");
 set_long("This is the tail that once belonged to Eeyore.  A small tuft of\n"+
 "black hair covers one end, and a large pink bow is tied just above.\n"+
 "A small tack sticks out of the other end.\n");
set_weight(1);
set_value(200);
}
