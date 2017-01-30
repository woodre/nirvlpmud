okay_follow() { return 1; }

#include "/players/vertebraker/define.h"
#include "/players/vertebraker/ed/paths.h"
inherit ROOM;
reset(arg) {
    if(arg) return;
    short_desc = "A bathroom";
    long_desc =
"     This is a small yellow-tiled bathroom.  A large bathtub is on the left\n"+
"side of the room, next to a small sink.  A medicine cabinet/mirror set is\n"+
"just above the sink.  There is a travel bag next to the sink on a small\n"+
"wooden stand, and a white curtain is wrapped around the curtain rods of\n"+
"the bathtub.  The room gives off a general feeling of cleanliness.\n";
    set_light(1);
items = ({
"bathtub","A large white bathtub is here, surrounded by a white shower curtain",
"cabinet","A small medicine cabinet is built into the backside of the mirror",
"mirror","You look into the mirror and see your reflection..",
"bag","There is a small travel bag here.  Razors and toothbrushes are inside",
"razors","There are several men's disposable razors inside the travel bag",
"toothbrushes","These clean toothbrushes are next to a roll of toothpaste",
"toothpaste","This is a roll of CREST toothpaste",
"stand","The small wooden table is balancing the travel bag",
"curtain","The white curtain provides a perfect shade for the bathtub",
"rods","There are two curtain rods with small rings holding up the curtain",
"sink","This small porcelain sink is dripping",
});

dest_dir = ({
ED1ROOM+"c6","north",
ED1ROOM+"c8","west",
});
  if(!present("shelly",TO)) MOCO(ED1MOB+"shelly"),TO);
}

init() {
    ::init();
    add_action("search","search"); }

search(arg) {
    if(!arg) { write("Your general search of the area turns up nothing.\n"); return 1; }
    if(arg) { write("You search "+arg+", but you find nothing.\n"); return 1; }
    return 1; }

realm() { return "NT"; }

set_slime() {
    int x;
    x = random(4);
    if(x == 0) long_desc = long_desc+RED+"Massive amounts of blood stains the walls and floor.\n"+NORM;
    if(x == 1) long_desc = long_desc+GRN+"Green slime and gore ooze from the remaining body parts spread here.\n"+NORM;
    if(x == 2) long_desc = long_desc+"The floor boards here have an odd tint to them.\n";
    if(x == 3) long_desc = long_desc+"A faint mist pours up from beneath the thin floorboards.\n";
    return 1; }
