#include "DEF.h"
inherit "room/room";
int W;

reset(arg) {
  if(arg) return;
set_light(1);
W = 0;  /*  Window starts closed  */

short_desc = HIY+"Ravenclaw Commons"+NORM;
long_desc =
  "  Two long tables aligned end to end divide this room.  Around the tables sit\n"+
  "stuffed wooden chairs.  Dozens of lighted candles sit atop the tables and\n"+
  "provide light.  An ornate oval fireplace sits against the outside wall and\n"+
  "a large window sits off to the side.\n";

items = ({
  "tables","Long wooden tables on large pedestal legs",
  "chairs","Dark wood with stuffed seats and backs",
  "candles","Various sized candles burning with eternal wicks",
  "fireplace","Lined with gold-colored brick, this fireplace appears to be the\n"+
              "source of warmth on chilly days and night.  It burns with a bright \n"+
              HIY+"yellow flame"+NORM,
  "window","A beautiful stained-glass window with the Hufflepuff crest on it.\n"+
           "A gold handle allows for it to be opened to let owls in and out",
});

dest_dir = ({
  "players/eurale/Pot/ravenclaw.c","out",
  "players/eurale/Pot/ravenclaw3.c","west",
  "players/eurale/Pot/ravenclaw4.c","east",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("Search","search");
  add_action("Open","open");
  add_action("Close","close");
}

Close(str) {
if(!str || str != "window") { write("Close what?\n"); return 1; }
if(W == 1) {
  write("You close the drafty window and lock it.\n");
  W = 0;
  return 1; }
write("The window is already shut.\n");
return 1;
}

Open(str) {
if(!str || str != "window") { write("What?\n"); return 1; }
if(str == "window" && W == 0) {
  write("You open the window and feel a cool breeze flutter in.\n");
  W = 1;
  return 1; }
write("The window is already open.\n");
return 1;
}
Search(str) {
if(!str) { write("You search aimlessly but to no avail.\n"); return 1; }
write("You search the "+str+" but find nothing special.\n");
say(capitalize(TPRN)+" searches the "+str+" but finds nothing.\n");
return 1;
}
