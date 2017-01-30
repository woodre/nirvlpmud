#define TP this_player()
#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc =("Durkor Caverns");
long_desc =(
"  The passageway forks off to the north to the east and west.  Gutteral\n"+
"moaning can be heard off to the northeast.  The passage to the northwest\n"+
"leads off into darkness and grows smaller.  A path leads off to the\n"+
"southeast growing larger.\n");

if(!present("jumak"))
	  move_object(clone_object("/players/catacomb/Cavern/mobs/Jumak1.c"),
	    this_object());

items = ({
  "passageway",
  "The passage leads off to the northwest and to the northeast",
  "passage",
  "The passage leads off to the northwest and to the northeast",
  "path",
  "A path leads off to the southeast"
  });

dest_dir = ({
  "/players/catacomb/Cavern/rooms/lvl4_4.c","northeast",
  "/players/catacomb/Cavern/rooms/lvl4_6.c","northwest",
  "/players/catacomb/Cavern/rooms/lvl4_2.c","southeast"
 
});
}


