#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);
if(!present("hickory tree")) {
  move_object(clone_object("players/eurale/Glade/NPC/tree"),TO); }

short_desc = HIG+"Enchanted Glade"+NORM;
long_desc =
  "  Before you looms a large stand of trees.  They are not like any\n"+
  "trees you've ever seen before...  In fact, they almost look as if\n"+
  "they might be moving.  The path leads eastward directly into the\n"+
  "trees and whatever might lie beyond.\n";

items = ({
  "trees","Tall, lush and green..but somehow strange",
  "path","A well-traveled dirt path leading into the trees",
});

dest_dir = ({
  "players/eurale/Glade/eg2.c","east",
  "players/eurale/RMS/warp.c","warp",
});

}

init() {
  ::init();
  add_action("east","east");
}

east() {
if(present("hickory tree")) {
  write("A gnarly tree moves to block your path...\n"); return 1; }
else {
  TP->move_player("east#players/eurale/Glade/eg2.c"); return 1; }
}
