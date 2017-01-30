#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(-1);

long_desc =
    ""+BLK+BOLD+"  A short, stone archway reaching deeper into the\n"+
    "pyramid.  The walls are a shade of green and covered\n"+
    "with slabs of mud and dirt.  Old, thin roots grow from\n"+
    "the cracks in the walls."+NORM+"\n";
items = ({
  "pyramid","A large structure made from clay stone",
  "archway","A curved overhang making a short walkway",
  "walls","Walls made of stone and clay.\nDead roots grow untamed throughout the walls",
  "mud","Dust, which is stuck to the walls",
  "roots","Thin, browned roots pushing their way through cracks in the walls",
  "cracks","Splits in the walls of various lengths",
});

dest_dir = ({
  "/players/jaraxle/3rd/pyramid/rooms/room3.c","out",
  "/players/jaraxle/3rd/pyramid/rooms/archway2.c","north",
});

MOCO("/players/jaraxle/3rd/pyramid/mon/revenant.c"),TO);
MOCO("/players/jaraxle/3rd/pyramid/mon/revenant.c"),TO);
}
short(){ return ""+BOLD+""+BLK+"Dark Pyramid"+NORM+""; }
realm() { return "NT"; }

