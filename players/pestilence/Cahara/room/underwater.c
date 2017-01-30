#include "/players/pestilence/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;

long_desc =
  "  Water is all around.  The current is very strong preventing someone\n"+
  "from returning up the falls.  The bottom of what appears to be a large\n"+
  "lake can be seen.  Sand covers the ground, with sporatic aquatic plants\n"+
  "sprouting out from the ground.  The water is very clear here, making\n"+
  "visibility great.  The lake appears to only extend to the west direction.\n";
set_light(1);

items = ({

});

dest_dir = ({
});

}

short() {
    return ""+CYN+"Underwater"+NORM+"";
}
