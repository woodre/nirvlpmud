#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
 if(!arg);
 set_light(0);
 set_short("In the "+HIK+"Crypt"+NORM);
 set_long("\
  The odor of decaying flesh fills the air, hovering like a thick fog.\n\
A few splintered boards lay along the tunnel wall, where logs stand as\n\
pillars for support.  The tunnel allows travel to the west, and opens\n\
into a chamber to the southeast.\n");
 add_smell("main","The odor of decaying flesh gives you dry heaves");
 add_item("boards","Some wooden boards, splintered and rotting");
 add_item("board","A wooden board, splintered and rotting");
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
 add_item("skull","The crushed remains of a skull.  It looks to be of human origin");
 add_item("remains","The crushed remains of a skull.  It looks to be of human origin");
 add_item("dirt","The dirt is brown in color, and moist from condensation");
 add_item("clothing","Tattered remains of clothing from corpses buried in the crypt");
 add_item("articles","Tattered remains of clothing from corpses buried in the crypt");
 add_item("floor","Hard packed dirt with a few bones and articles of clothing scattered about");
 add_exit(PLAIN+"cr5.c","southeast");
 add_exit(PLAIN+"cr7.c","west");
}
graveyard() { return "YES"; }





