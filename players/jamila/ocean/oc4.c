#include "/players/jamila/ansi.h"
#define tp this_player()
inherit "/players/vertebraker/closed/std/room.c";


reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Wide Open Ocean";
long_desc =
"  Upon stepping through the sponge you find yourself in\n"+
"the middle of a giant ocean.  The water is thick and you\n"+
"wonder how it is you can breathe and move so easily here.\n"+
"Everything around you is a wonderful shade of blue and you\n"+
"notice small fish hiding around everywhere.  Far in the\n"+
"distance you can make out the shape of a large building\n"+
"but you can't tell from here what it is.  Maybe you should\n"+
"go deeper into the ocean and find out what lurks there.\n";

add_listen("main", "You are underwater! You can feel vibrations but hear nothing..");
add_smell("main", "Don't try to smell water!");

items = ({
  "bed",
  "The canopy covers most of the bed to hide the ones inside.",
  "canopy", 
  "Looking past the canopy you notice the sheets turned down.",
  "fire",
  "A couple logs with bits of orange flickering over them.",
  "carpet",
  "Warm and cozy looking, it invites you to lay down.",
  "wine",
  "A dusty bottle of red wine, someone has been saving this.",
  "glasses",
  "Two beautiful crystal glasses shimmering in the light.",
    });

dest_dir = ({
  "/players/jamila/ocean/oc2.c","north",
  "/players/jamila/ocean/oc5.c","east",
  }); 
  }
  
  init()
{
	::init();
	add_action("cmd_west","hole");
}

cmd_west(str)
{
	write("You swim into the hole!\n");
	this_player()->move_player("west#/players/jamila/ocean/oc6.c");
	return 1;


}

