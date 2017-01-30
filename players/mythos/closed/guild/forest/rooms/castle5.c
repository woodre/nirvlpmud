#include "/sys/ansi.h"
#include "/players/mythos/closed/guild/def.h"
object mon;
inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(0);
    short_desc = HIK+"Forbidden Castle"+NORM+" ["+YEL+"Stairs"+NORM+"]";
    long_desc =
    YEL+"Before you is a twisting staircase leading up and down.\n"+
    "Up leads to the Forbidden Towers, down to the dungeons.\n"+
    "You sense a great danger from below......\n"+NORM;
  items = ({
    "west","You can see the main hall....",
    "up","The castle towers...",
    "down",HIK+"Darkness"+NORM+".....",
  });

  dest_dir = ({
    "/players/mythos/closed/guild/forest/rooms/castle2.c", "west",
    "/players/mythos/closed/guild/forest/rooms/dungeon.c", "down",
    "/players/mythos/closed/guild/forest/rooms/tower.c", "up",
  });
} }
realm() { return "NT";}

init() {
  ::init();
    this_player()->set_fight_area();
    if(!pp && tp->is_player()) { 
          tell_object(tp,HIR+"Do NOT venture further!\n"+
                                  "Your life is in danger!\n"+NORM);
          tell_room(this_object(),HIC+"A wind blasts out of nowhere!\n"+NORM);
          mon = clone_object("/players/mythos/closed/guild/forest/mon/nightmare.c");
          move_object(mon,this_object());
          mon->attack_object(tp);
          }
}
