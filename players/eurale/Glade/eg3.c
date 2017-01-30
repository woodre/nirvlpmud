#include "/players/eurale/defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);
if(!present("wood troll")) {
  move_object(clone_object("players/eurale/Glade/NPC/troll"),TO); }

short_desc = HIG+"Enchanted Glade"+NORM;
long_desc =
  "  The path wanders through the tall trees.  The groundcover is lush\n"+
  "and thick.  There are a few large rocks scattered among the ferns\n"+
  "and flowers.  Such a peaceful place but something tells you there's\n"+
  "trouble close by.\n";

items = ({
  "path","A dirt trail, seldom used",
  "groundcover","Ferns, flowers and wild grasses",
  "ferns","Large, leafy plants",
  "flowers","Wildflowers, especially Trilliam",
  "rocks","White, crystalline rocks with wild moss covering them",
});

dest_dir = ({
  "players/eurale/Glade/eg2.c","north",
  "players/eurale/Glade/eg4.c","south",
});

}

init() {
  ::init();
  add_action("search","search");
  add_action("south","south");
}

search() {
  write("You search the area and find nothing special.\n");
  return 1; }

south() {
if(present("wood troll")) {
  write("Hawthorn laughs heartily and shoves you back the way you came.\n");
  return 1; }
else {
  TP->move_player("south#players/eurale/Glade/eg4.c");
  return 1; }
}
