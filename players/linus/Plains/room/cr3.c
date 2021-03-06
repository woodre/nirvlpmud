#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
 if(!arg);
 set_light(0);
 set_short("In the "+HIK+"Crypt"+NORM); 
 set_long("\
  The stench of death and decay permeates the narrow confines of the\n\
crypt.  Logs stand against the earthen walls, being used as pillars\n\
for support.  The tunnel allows travel to the north and southwest.\n");
 add_item("crypt","Tunnels and chambers dug into a hill");
 add_item("tunnel","\Tunnels carved into the hill.  Log pillars stand along the\n\
earthen walls for support");
 add_item("walls","Packed dirt with logs standing as pillars for support");
 add_item("earthen walls","Packed dirt with logs standing as pillars for support");
 add_item("wall","Packed dirt with logs standing as pillars for support");
 add_item("earthen wall","Packed dirt with logs standing as pillars for support");
 add_item("logs","Wooden logs that stand along earthen walls for support");
 add_item("log","A wooden log that stands along earthen walls for support");
 add_item("pillars","Wooden logs that stand along earthen walls for support");
 add_item("pillar","A wooden log that stands along earthen walls for support");
 add_item("bones","The bones are old and covered in dirt");
 add_item("dirt","The dirt is brown in color, and moist from condensation");
 add_item("clothing","Tattered remains of clothing from corpses buried in the crypt");
 add_item("articles","Tattered remains of clothing from corpses buried in the crypt");
 add_item("floor","Hard packed dirt with a few bones and articles of clothing scattered about");
 add_object(PNPC+"ghoul.c");
 add_exit(PLAIN+"cr2.c","southwest");
 add_exit(PLAIN+"cr4.c","north");
 }
