#include "/players/jamila/ansi.h"
#define tp this_player()
inherit "/players/vertebraker/closed/std/room.c";


reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Soft Beach";
long_desc =
"  This is a small trench at the end of the sandbar.\n"+ 
"Here there are a few traps set by local fisherman for the\n"+
"lobster.  Unfortunately the lobster seem to be smarter\n"+
"than that since they are crawling across the bottom\n"+
"next to the large traps.\n";

add_listen("main", "You hear the birds hunting in the distance and the roar of the waves.");
add_smell("main", "The smell of saltwater fills your nostrils.");


items = ({
  "water",
  "The water is a foggy blue and the small waves crest in a lighter blue green color.",
   "seaweed",
  "The seaweed waves with the movement of the water and seems to grab at your body as you swim through the water.",
  "cage",
  "The large lobster cage is empty except for some bait that a large lobster seems to be grabbing at through the bars.",
  "trench",
  "A large trench that drops down fifty feet or so into darkness", 
  });

dest_dir = ({
  "/players/jamila/beach/beach19.c","south",
  "/players/jamila/beach/beach15.c","west",
  });
                if(!present("lobster"))
{
move_object(clone_object("/players/jamila/beach/mobs/lobster.c"),this_object());
}
}
