#include "/players/jamila/ansi.h"
#define tp this_player()
inherit "/players/vertebraker/closed/std/room.c";


reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Boardwalk";
long_desc =
"  At this spot in the boardwalk there is a small shop\n"+
"farther to the east and more boardwalk to the south,\n"+
"this seems to be the beginning of the tourists interest\n"+
"in the boardwalk and so there are more benches around\n"+
"for them to rest on.\n";

add_listen("main", "You hear the bustling of tourists and the sound of the water rushing beneath.");
add_smell("main", "The smells of food mixed with the smells of the beach fill your nostrils.");

items = ({
  "boards",
  "The boards are a dark brown with stains from the salty water on them.", 
  "waves",
  "You look over the side and see the frothy waves rolling under the boardwalk.",
  "shop",
  "A shop to the east that has stained glass windows and a small sign hanging above the door.",
  "benches",
  "There are benches placed every ten feet or so along both sides of the board walk.",
    });

dest_dir = ({
  "/players/jamila/boardwalk/bw1.c","north",
  "/players/jamila/boardwalk/bw4.c","east",
  "/players/jamila/boardwalk/bw3.c","south",
  });
  
  init()
{
	::init();
	add_action("cmd_brave","west");
}

cmd_west(str)
{
	write("You brave the darkness and enter the cave!\n");
	this_player()->move_player("/players/jamila/boardwalk/cave/c1.c");
	return 1;
}
      if(!present("seagull"))
{
move_object(clone_object("/players/jamila/beach/mobs/seagull.c"),this_object());

}
if(!present("crab"))
{
move_object(clone_object("/players/jamila/beach/mobs/crab.c"),this_object());
move_object(clone_object("/players/jamila/beach/mobs/crab.c"),this_object());
}
}
