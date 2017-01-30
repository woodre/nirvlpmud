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
  "fish",
  "Tiny fish swimming against the current, you almost want to try to catch them.",
    });

dest_dir = ({
  "/players/jamila/ocean/oc16.c","north",
  "/players/jamila/ocean/oc20.c","west",
  });
{

	
}

}

