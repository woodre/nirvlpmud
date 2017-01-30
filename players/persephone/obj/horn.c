inherit "obj/weapon";
#include "/players/persephone/rooms.h"
reset(arg){
  if(arg) return;
  ::reset();
  set_type("spear");
  set_name("horn");
  set_alias("spear");
  set_short("Goat Horn");
  set_long("The horn of a great sea goat it looks like it would make \n" +
           "an adequate weapon as it looks like it would pierce well\n");
  set_class(14);
  set_weight(3);
  set_value(400);
/* commented out.  why's this here ;)   Vertebraker [5.31.01]

  set_hit_func(TOB);
*/
}

