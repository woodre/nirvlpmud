#include "/players/jamila/ansi.h"
#define tp this_player()
inherit "/players/vertebraker/closed/std/room.c";


reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Soft Beach";
long_desc =
"  This is the beginning of a small beach. The sand squishes\n"+
"softly under your feet.  Seagulls fly all over the beach\n"+
"and over your head.  Nearby the waves crash hard up\n"+
"against the sand and you can see the nearby sparkle of the\n"+
"shells on the beach.\n";

add_listen("main", "You hear seagulls calling out and waves crashing close by.");
add_smell("main", "The smell of saltwater fills your nostrils.");

items = ({
  "sand",
  "The soft white sand glitters in the sun with small fragments of seashells",
  "seashells", 
  "Small seashells glittering where the sunlight hits them",
  "shells",
  "Small seashells glittering where the sunlight hits them",
    });

dest_dir = ({
  "/players/jamila/sponge.c","sponge",
  "/players/jamila/beach/beach2.c","north",
  });
  if(!present("seagull"))
{
move_object(clone_object("/players/jamila/beach/mobs/seagull.c"),this_object());
move_object(clone_object("/players/jamila/beach/mobs/seagull.c"),this_object());
}

}

