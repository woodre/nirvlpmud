#include "/players/mythos/closed/guild/def.h"
inherit "room/room";
reset(arg) {
if(!present("it")) {
  move_object(clone_object("/players/mythos/closed/guild/task/7/it.c"),
     this_object()); }
  if(!arg) {
  set_light(-2);
    short_desc = HIK+"Forbidden Castle"+NORM+" ["+HIK+"Dungeon"+NORM+"]";
    long_desc = HIK+
    "\n\n\n\t\t\tD  A  R  K  N  E  S  S\n\n\n\n"+NORM;
  items = ({
    "open","The way out...",
  });

  dest_dir = ({
    "/players/mythos/closed/guild/forest/rooms/dungeon.c", "open",
  });
} }
realm() { return "NT";}

init() {
  ::init();
    this_player()->set_fight_area();
    add_action("open","open");
}

open() {
  if(present("it")) {
   write(present("it")->short()+" blocks you way.\n"); return 1;}
}
