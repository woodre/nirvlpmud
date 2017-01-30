okay_follow() { return 1; }

#include "/players/vertebraker/define.h"
#include "/players/vertebraker/ed/paths.h"
inherit ROOM;
reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "The cabin's kitchen";
  long_desc =
"     You stand in the kitchen of the cabin- There are several wall cupboards\n"+
"and a small, old refrigerator in the southwestern corner of the room.\n"+
"A small dinner table is in the middle of the room.  Several bags of unopened\n"+
"food have been left on the counter near the sink.  A wastebasket is in the\n"+
"opposite corner of the room.\n";
if(!present("scotty",TO)) MOCO(ED1MOB+"scotty"),TO);
  dest_dir = ({
ED1ROOM+"c2","north",
ED1ROOM+"c4","west",
ED1ROOM+"c8","south",
ED1ROOM+"c6","east",
});
  items = ({
"cupboards","Cupboards placed upon the wall bear miscellaneous amounts of food",

"food","Boxes of Rice Krispies and cartons of Cup-o-Soup are within the cupboards",
"refrigerator","The bare 'fridge gives off a small chill when it is opened",
"table","A table which seats approximately six stands in the middle of the room",
"bags","Frozen meats and waffles are inside these grocery bags",
"meats","Steaks and pork chops are some of the meats within the bags",
"steaks","Nice, juicy USDA approved beef cuts",
"pork chops","Small but tender slabs of pig",
"waffles","A few boxes of waffles lie here",
"wastebasket","A small wastebasket sits in the corner",
"sink","The sink is covered with some kind of brownish-red liquid that looks like...\ndried blood...",
});
  }
init() {
  ::init();
  add_action("search","search"); }
search(arg) {
    if(!arg) { write("Your general search of the area turns up nothing.\n"); return 1; }
    if(arg) { write("You search "+arg+", but you turn up nothing.\n"); return 1; }
    return 1; }

realm() { return "NT"; }

set_slime() {
    int x;
    x = random(4);
    if(x == 0) long_desc = long_desc+RED+"Massive amounts of blood stains the walls and floor.\n"+NORM;
    if(x == 1) long_desc = long_desc+GRN+"Green slime and gore ooze from the remaining body parts spread here.\n"+NORM;
    if(x == 2) long_desc = long_desc+"The floor boards here have an odd tint to them.\n";
    if(x == 3) long_desc = long_desc+"A faint mist pours from up beneath the thin floorboards.\n";
    return 1; }
