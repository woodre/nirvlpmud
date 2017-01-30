#include "DEFS.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "Labyrinth";
long_desc =
  "  Jagged rock surrounds you.  Moss grows between the small shelves\n"+
  "that have been chipped away in the forming of this underground cave.\n"+
  "The darkness above seems open as the echoes of your footsteps fade\n"+
  "away in that direction.\n";

items = ({
  "rock","Dull grey with streaks of brown running through it",
  "moss","A soft, lime green growth, almost like carpet",
  "darkness","Nothing but blackness",
  "shelves","Pieces of rock sticking out that could provide footing for\n"+
            "those who wished to climb up into the darkness",
});

dest_dir = ({
  "players/eurale/Lab/l7.c","up",
  "players/eurale/Lab/l5.c","southeast",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("up","up");
}

up() {
int num;
num = random(25);
if(TP->query_attrib("luc") < num) {
  write("As you try to climb up you lose your grip and fall..\n");
  TP->add_hit_point(-random(40));
  return 1; }
TP->move_player("up#players/eurale/Lab/l7.c");
return 1;
}
