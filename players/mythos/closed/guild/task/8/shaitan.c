#include "/players/mythos/closed/guild/def.h"
int n;
inherit "room/room";
reset(arg) {
  if(!present("tarrant")) {
    move_object(clone_object("/players/mythos/closed/guild/task/8/hunter.c"),this_object());
  }
  if(!arg) {
  n = 1;
  set_light(0);
    short_desc = HIR+"Blood Room"+NORM;
    long_desc =
    "You enter a rather small room.  A blue fire blazes in the fireplace,\n"+
    "books line the bookshelves, and the ceiling sparkles- crystal.  The \n"+
    "wall facing you has a large tapestry- of an odd design.\n"+
    "In the center of room stands a man.....\n";
  dest_dir = ({
    "/players/mythos/closed/guild/forest/rooms/castle6.c", "back",
  });
} }
realm() { return "NT";}

init() {
  ::init();
    this_player()->set_fight_area();
    add_action("bback","back");
    add_action("llook","look");
}

bback() {
  if(n == 1) { write("You can not leave.\n"); return 1;}
  if(pp) { pp->set_switch(1); }
}

llook(str) {
  if(!str) { tp->look(); return 1;}
  if(str == "at tapestry") {
    write("It is a maze of amazing complexity....\n");
  return 1;}
}
