#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
 if(!arg);
 set_light(0);
 set_short("In the "+HIK+"Crypt"+NORM);
 set_long("\
  The tunnel opens into a chamber, the first of several where bodies\n\
were kept until fairer weather permitted burial outside.  Wooden\n\
coffins are piled along the walls, having been ripped apart and\n\
emptied.  The odor of decaying flesh hovers like a fog here.  Tunnels\n\
allow entry to the chamber from the southeastern, eastern and \n\
northwestern directions.\n");
 add_smell("main","The stench of death and decaying flesh gives you dry heaves");
 add_item("tunnels","Openings in the walls that allow travel");
 add_item("tunnel","An opening in the wall that allows travel");
 add_item("walls","Packed dirt with coffins piled along them");
 add_item("earthen walls","Packed dirt with coffins piled along them");
 add_item("wall","Packed dirt with coffins piled along it");
 add_item("earthen wall","Packed dirt with coffins piled along it");
 add_item("coffin","The tattered remains of a coffin, the wood splintered and ripped apart");
 add_item("coffins","The tattered remains of coffins, the wood splintered and ripped apart");
 add_item("wooden coffins","The tattered remains of coffins, the wood splintered and ripped apart");
 add_item("wooden coffin","The tattered remains of a coffin, the wood splintered and ripped apart");
 add_item("pile","A pile of coffins that have been ripped apart");
 add_item("dirt","The dirt is brown in color, and moist from condensation");
 add_item("clothing","Tattered remains of clothing from corpses buried in the crypt");
 add_item("articles","Tattered remains of clothing from corpses buried in the crypt");
 add_item("floor","Hard packed dirt with a few bones and articles of clothing scattered about");
 add_exit(PLAIN+"cr4.c","southeast");
 add_exit(PLAIN+"cr7.c","east");
 add_exit(PLAIN+"cr6.c","northwest");
 add_object(PNPC+"ghoul.c",random(3));
}
graveyard() { return "YES"; }
