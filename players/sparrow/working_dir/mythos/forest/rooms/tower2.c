#include "/players/mythos/closed/guild/def.h"
object mon;
inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(-1);
    short_desc = HIK+"Forbidden Castle"+NORM+" ["+YEL+"South Tower"+NORM+"]";
    long_desc =
    YEL+"You climb on...  Darkness surrounds you and you begin\n"+
    "to feel a bit tired.  The pounding of you heart is all\n"+
    "that you hear and darkness is all you can see...\n"+NORM;
  items = ({
    "up","Above is Darkness....",
    "down","Below you barely see anything....",
  });

  dest_dir = ({
    "/players/mythos/closed/guild/forest/rooms/tower5.c", "up",
    "/players/mythos/closed/guild/forest/rooms/tower.c", "down",
  });
} }
realm() { return "NT";}

init() {
  ::init();
    this_player()->set_fight_area();
if(!pp && tp->is_player()) { 
          tell_object(tp,BOLD+"Do NOT venture further!\n"+
                                  "Your life is in danger!\n"+NORM);
          tell_room(this_object(),"A wind blasts out of nowhere!\n");
          mon = clone_object("/players/mythos/closed/guild/forest/mon/nightmare.c");
          move_object(mon,this_object());
          mon->attack_object(tp);
          mon = clone_object("/players/mythos/closed/guild/forest/mon/nightmare.c");
          move_object(mon,this_object());
          mon->attack_object(tp);
          }}
