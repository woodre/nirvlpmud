#include "/players/jamila/ansi.h"
#define tp this_player()
inherit "/players/vertebraker/closed/std/room.c";


reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Soft Beach";
long_desc =
"  The beach stretches out before you in all its glory.\n"+
"A seagull screams above your head and below your feet are\n"+
"many small shelled creatures.  The waves are closer now\n"+
"and every few minutes they lap up at your feet.\n";

add_listen("main", "You hear seagulls calling out and waves crashing close by.");
add_smell("main", "The smell of saltwater fills your nostrils.");

items = ({
  "sand",
  "The soft white sand glitters in the sun with small fragments of seashells", 
  "waves",
  "The waves barely lap at your feet, just enough to get them wet on the bottom",
  "wave",
  "A wave comes up and covers the sand barely touching your feet",
  "creatures",
  "Small shelled creatures burry themselves back into the sand as the waves pass over them",
    });

dest_dir = ({
  "/players/jamila/beach/beach4.c","south",
  "/players/jamila/beach/beach13.c","east",
  "/players/jamila/beach/beach6.c","west",
  });
if(!present("crab"))
{
move_object(clone_object("/players/jamila/beach/mobs/crab.c"),this_object());
move_object(clone_object("/players/jamila/beach/mobs/crab.c"),this_object());
}
}
