#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
#include "/players/maledicta/ansi.h"
object naga;
reset(arg) {

  if(arg) return;
set_light(1);

short_desc = ""+BOLD+"The "+HIB+"Dragons"+NORM+BOLD+" Cave"+NORM+"";
long_desc =
"   You are at the entrance of a very large cave. The rock\n"+
"walls seem to have been torn and dug out to make the entrance\n"+
"wider. A path of bones litter the area and mark a gruesome\n"+
"trail further into the cave. You see an exit to the north\n"+
"leading into the cave, and to the south is a path leading\n"+
"out of this area.\n";

items = ({
  "bones",
  "The bones of many creatures and men. They are piled at least 3 feet deep",
  "walls",
  "The walls here look to have been dug out by powerful claws",
});

dest_dir = ({
  "/players/maledicta/cont/dragon/rooms/cave2.c","north",
  "/players/maledicta/cont/rooms/", "south",
});

}
