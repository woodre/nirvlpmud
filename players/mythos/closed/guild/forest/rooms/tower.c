#include "/sys/ansi.h"
#include "/players/mythos/closed/guild/def.h"

inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(0);
    short_desc = HIK+"Forbidden Castle"+NORM+" ["+YEL+"Tower"+NORM+"]";
    long_desc =
    YEL+"You climb up a set of twisting stairs and reach the upper\n"+
    "level.  You have a very bad feeling about this place.\n"+
    "BEWARE!\n"+NORM;
  items = ({
    "down","Leads down to the main castle area...",
    "right",HIK+"Darkness"+NORM+".....",
    "left",HIK+"Darkness"+NORM+".....",
    "forward",HIK+"Darkness"+NORM+".....",
  });

  dest_dir = ({
    "/players/mythos/closed/guild/forest/rooms/castle5.c", "down",
    "/players/mythos/closed/guild/forest/rooms/tower2.c", "right",
    "/players/mythos/closed/guild/forest/rooms/tower3.c", "left",
    "/players/mythos/closed/guild/forest/rooms/tower4.c", "forward",
  });
} }
realm() { return "NT";}

init() {
  ::init();
    this_player()->set_fight_area();
    if(!pp) { tell_object(tp,HIR+"Do NOT venture further!\n"+
                                  "Your life is in danger!\n"+NORM);}
}
