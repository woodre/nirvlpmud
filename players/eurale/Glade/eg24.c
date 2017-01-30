#include "defs.h"
inherit "room/room";
object player;

reset(arg) {
  if(arg) return;
if(!present("asytrasil")) {
  move_object(clone_object("players/eurale/Glade/NPC/Fhooker"),TO); }
set_light(0);

short_desc = HIG+"Enchanted Glade Cave"+NORM;
long_desc =
  "  This is a small cave, large enough to stand in.  On the floor\n"+
  "is a thick layer of fragrant pine needles covered with a large\n"+
  "animal skin.  The cave entrance is out of sight and the area is\n"+
  "dark and private.\n";

items = ({
  "needles","Fresh, soft pine needles",
  "skin","A soft, furry black bear hide",
});

dest_dir = ({
  "players/eurale/Glade/eg23.c","west",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("search","search");
  add_action("west","west");
}

search() {
  write("You search the area and find nothing special.\n");
  return 1; }

west() {
  TP->move_player("west#players/eurale/Glade/eg23.c");
  ("/players/eurale/Glade/eg23.c")->set_PATRONE(0);
return 1; }
