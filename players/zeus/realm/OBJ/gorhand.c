inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
reset(arg){

  set_id("gorilla hand");
  set_alias("hand");
  set_short("A black gorilla hand");
  set_long(
"A gorilla hand covered in coarse black fur and tough skin.  It is a\n"+
"very rare thing, and believed by many to have magical properties.\n"+
"At the point where it was severed, carnage and bone are visible.\n"+
"This is a valuble item that can be 'barter'ed.\n");

  set_weight(1);
  set_value(100+random(3000));
}

