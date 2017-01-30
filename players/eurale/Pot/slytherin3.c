#include "DEF.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIG+"Slytherin Dormitory"+NORM;
long_desc =
  "  Rickety beds sit in disarray around this room.  Green quilts cover each of\n"+
  "the beds and large trunks sit at the foot or each bed.  A large window fills\n"+
  "most of the western wall and an ornate fireplace is built into the southern\n"+
  "wall.  Small candles in ornate candle holders are attached to the walls over\n"+
  "each bed to provide light.\n";

items = ({
  "beds","Well used and worn wooden bed frames with soft, comfortable down-filled\n"+
         "mattresses and large pillows",
  "quilts","Green quilts all bearing he Slytherine Crest in the middle",
  "window","A large, four-pane window with bright green curtains on each side",
  "fireplace","A small but well built fireplace with the Slytherin insignia\n"+
              "chiseled into the headstone",
  "candles","Ever burning candles that provide light to the room",
  "holders","Twisted metal holders with the head of a snake at the top",
});

dest_dir = ({
  "players/eurale/Pot/slytherin2.c","north",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("Search","search");
}

Search(str) {
if(!str) { write("You search aimlessly but to no avail.\n"); return 1; }
write("You search the "+str+" but find nothing special.\n");
say(capitalize(TPRN)+" searches the "+str+" but finds nothing.\n");
return 1;
}
