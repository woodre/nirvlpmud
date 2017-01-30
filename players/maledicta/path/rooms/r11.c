#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
object guard1;

reset(arg) {
	if(!present("cont_lizardguard")){
	guard1 = clone_object("/players/maledicta/cont/ltown/mobs/lguard.c");
	move_object(guard1, this_object());
	}
  if(arg) return;
set_light(1);

short_desc = "a swampy area";
long_desc =
"  The land gives way to ankle deep water as you\n"+
"trudge along through the swamp.  The trees begin\n"+
"to thin out, and something large can be seen to\n"+
"the north.\n";  

items = ({
  "land",
  "It is covered in ankle deep water",
  "water",
  "The water here is dark and swirls about your ankles lazily",
  "trees",
  "Sagging trees that almost looked depressed",
  "something",
  "Your not sure what it is",
  });

dest_dir = ({
  "/players/maledicta/path/rooms/r12.c","north",
  "/players/maledicta/path/rooms/r10.c","west",
});

}


