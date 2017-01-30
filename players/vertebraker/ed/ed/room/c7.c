okay_follow() { return 1; }

#include "/players/vertebraker/define.h"
#include "/players/vertebraker/ed/paths.h"
inherit ROOM;
reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "A patio";
  long_desc =
"     Glancing briefly around the room, you notice that the room has been\n"+
"littered with a great deal of what appears to be sketchpad paper.\n"+
"A tall grandfather clock looms on the northwestern corner, gazing as\n"+
"you look around.  An open window blows a chilly breeze into the room,\n"+
"giving the room a tinge of ice.\n";

if(!present("cheryl",TO)) MOCO(ED1MOB+"cheryl"),TO);
items = ({
  "paper","Crumpled paper lies all around the room",
  "clock","The tall grandfather clock seems to have the time completely wrong",
  "window","The open window seems to be stuck- There is no way to close it",
  "corner","The grandfather clock stands here",
  "grandfather clock","The tall grandfather clock seems to have the time completely wrong",
  });

dest_dir = ({
ED1ROOM+"c8","east",
ED1ROOM+"c4","north",
});
  }

init() {
  ::init();
  add_action("search","search");
  }

search(arg) {
    if(!arg) { write("Your general search of the area turns up nothing.\n"); return 1; }
    if(arg) { write("You search "+arg+", but you turn up nothing.\n"); return 1; }
    return 1; }

realm() { return "NT"; }

set_slime() {
  int x;
  x = random(4);
  if(x == 0) long_desc = long_desc+RED+"Massive amounts of blood stains the walls and floor.\n"+NORM;   if(x == 1) long_desc = long_desc+GRN+"Green slime and gore ooze from the remaining body parts spread here.\n"+NORM;
  if(x == 2) long_desc = long_desc+"The floor boards have an odd tint to them.\n";
  if(x == 3) long_desc = long_desc+"A faint mist pours up from beneath the thin floorboards.\n";
  return 1; }
