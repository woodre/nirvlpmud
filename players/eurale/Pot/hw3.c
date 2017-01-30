#include "DEF.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Hogwarts";
long_desc =
  "  Surrounding this small foyer is an immense building with curving stairs that\n"+
  "lead to upper levels.  To the north is a large curved archway that appears to\n"+
  "lead into a giant hall of some kind.  Ghostly apparitions float overhead and\n"+
  "flickering candles in large metal wall holders light the darkness.  A narrow\n"+
  "curved staircase leads down from this room.\n";

items = ({
  "staircase","Narrow stone steps curving down out of this room to some of the\n"+
              "classrooms here at Hogwarts",
  "stairs","Wide, stone steps that curve upward from both sides of the foyer.\n"+
           "They seem to swing about ending at different locations at the top",
  "archway","Cut through thick, stone walls, this high, arched opening is edged\n"+
            "with shiney black stones",
  "stones","Dark, stained stones having seen years and years of abuse at the hands\n"+
           "of Hogwart's students",
  "hall","A giant room of some kind but it's barely visible from this location",
  "apparitions","Smiling ghosts that float up and through the stone walls",
  "candles","Large, melted wax candles with big wicks giving off lots of light",
  "holders","Metal holders attached to the wall upon which sit candles",
});

dest_dir = ({
  "players/eurale/Pot/hall.c","north",
  "players/eurale/Pot/hw2.c","out",
  "players/eurale/Pot/hw4.c","up",
  "players/eurale/Pot/hw5","down",
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
