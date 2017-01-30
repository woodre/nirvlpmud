#include "/players/fred/ansi.h"
inherit "/obj/weapon.c";

reset (arg) {
  ::reset(arg);
  if(arg) return;
  
  set_name("mallet");
  set_alias("club");
  set_short("Croquet Mallet");
  set_long(
    "    A BIG wooden croquet mallet.  There are metal \n"+
    "plates on either side of the mallet.  The handle is \n"+
    "about 4 feet in length with different colored tape\n"+
    "going around it every 6 inches.\n");
  
    set_type("club");
    set_class(16);
    set_weight(1);
    set_value(1500);
    message_hit=({
      BOLD+RED+"T E N D E R I Z E D"+NORM,"",
      BOLD+"mauled"+NORM,"",
      BOLD+"whacked"+NORM,"",
      BOLD+"hit"+NORM,"",
      BOLD+"grazed"+NORM,"",
      BOLD+"nicked"+NORM,"",
      "missed","",
      });
}
