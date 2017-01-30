#include "/players/pestilence/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;

long_desc =
  "  This is directly inside the "+CYN+"waterfall"+NORM+".  Water flows down \n"+
  "all around.  The water is a sparkling crystal blue.  It appears the only\n"+
  "way to exit from here, is to either jump, or attempt to swim back up the\n"+
  "falls into the cave.\n";
set_light(1);

items = ({

});

dest_dir = ({
});

}

short() {
    return ""+CYN+"Waterfall"+NORM+"";
}
