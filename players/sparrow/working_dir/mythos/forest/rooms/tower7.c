#include "/players/mythos/closed/guild/def.h"

inherit "room/room";
reset(arg) {
  if(!present("guard")) {
    move_object(clone_object("/players/mythos/closed/guild/forest/mon/silent_guard.c"),
      this_object());
  }
  if(!arg) {
  set_light(-3);
    short_desc = "Forbidden Castle Main Tower Top";
    long_desc =
    "You are in the Main Tower.  Things are very quiet here.\n"+
    "Beware, for something seems to be watching you.\n";
  items = ({
    "leave","You may leave the room down the stairs",
    "open","You may open the hatch to the observatory",
  });

  dest_dir = ({
    "/players/mythos/closed/guild/forest/rooms/tower8.c", "open",
    "/players/mythos/closed/guild/forest/rooms/tower4.c", "leave",
  });
} }
realm() { return "NT";}

init() {
  ::init();
    this_player()->set_fight_area();
    add_action("oopen","open");
}

oopen() {
  if(present("guard",this_object())){
  write("Somthing attacks before you can open the hatch!\n");
    present("guard",this_object())->attack_object(tp);
  return 1;}
}
