#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
 if(!arg);
 set_light(0);
 set_short("In the "+HIK+"Crypt"+NORM);
 set_long("\
A few splintered boards lay along the tunnel wall, where logs stand as\n\
pillars for support.  Piles of rock and debris give the impression of\n\
a cave-in here, blocking any passage to the west.\n");
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
 add_item("dirt","The dirt is brown in color, and moist from condensation");
 add_item("floor","Hard packed dirt");
 add_item("rock","Large and small rocks that appear to have caved in");
 add_item("rock","A large rock that lies in a pile of debris");
 add_item("debris","Wooden logs, rocks, and boards that have caved in here");
 add_item("pile","Wooden logs, rocks, and boards that have caved in here");
 add_exit(PLAIN+"cr7.c","east");
 add_object(PNPC+"ghoul.c");
}
graveyard() { return "YES"; }





