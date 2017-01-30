#include "/players/pestilence/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+YEL+"Daleka's Hut"+NORM+"";
long_desc =
  "    This is the hut of the fierce warrior named Daleka.  This hut is small\n"+
  "compared to most.  Daleka spends the majority of his time fighting rather\n"+
  "than in the hut.  The walls are solidly made of mud, same as the floor.  The\n"+
  "hut consists of only one room.  A bedroll lays on the floor.  The fireplace\n"+
  "is on the northern wall.\n";
set_light(1);

items = ({

});

dest_dir = ({
  "/players/pestilence/Cahara/room/cvillage.c","east",
});

}
