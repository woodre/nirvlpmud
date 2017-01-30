#include "/sys/ansi.h"
#include "/players/mythos/closed/guild/def.h"

inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(0);
    short_desc = HIK+"Forbidden Castle"+NORM+" ["+YEL+"South Hall"+NORM+"]";
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
    "/players/mythos/closed/guild/forest/rooms/castle2.c", "north",
    "/players/mythos/closed/guild/forest/rooms/castle7.c", "east",
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
write("You find nothing.\n");
return 1;}
