#include "/sys/ansi.h"
#include "/players/mythos/closed/guild/def.h"
int n;
inherit "room/room";
reset(arg) {
n = 1;
  if(!arg) {
  set_light(0);
    short_desc = HIK+"Forbidden Castle"+NORM+" ["+YEL+"North Hall"+NORM+"]";
    long_desc =
    YEL+"You enter a large hall.  Dark crystal walls, black\n"+
    "marble flooring, and a high domed ceiling.  Every step\n"+
    "you take- the sound is muffled as if the darkness\n"+
    "swallowed up the vibrations.  Your heart pounds and\n"+
    "dread slowly creeps up on you.\n"+NORM;
  items = ({
    "north",HIK+"Darkness"+NORM+"....",
    "east",HIK+"Darkness"+NORM+"....",
    "south",HIK+"Darkness"+NORM+"....",
    "west",HIK+"Darkness"+NORM+"....",
  });

  dest_dir = ({
    "/players/mythos/closed/guild/forest/rooms/castle6.c", "east",
    "/players/mythos/closed/guild/forest/rooms/castle2.c", "south",
  });
} }
realm() { return "NT";}

init() {
  ::init();
    this_player()->set_fight_area();
    if(!pp) { tell_object(tp,HIR+"Do NOT venture further!\n"+
                                  "Your life is in danger!\n"+NORM);}
    add_action("search","search");
}

search() {
if(n) {
  if(pp) { write("Power floods you as you pull a tiara from the shadows!\n");
  }
  else { write("You are filled with dread as you pull a tiara from the shadows!\n");
  }
  n = 0;
  move_object(clone_object("/players/mythos/closed/guild/task/4/jewel.c"),tp);
  } else { write("You find nothing.\n"); }
return 1; }
