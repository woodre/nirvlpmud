#include "/players/jamila/ansi.h"
#define tp this_player()
inherit "/players/vertebraker/closed/std/room.c";


reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Soft Beach";
long_desc =
"  Here is where the shore meets the water.  The waves lap\n"+
"up over your feet and go back out leaving small creatures\n"+
"flapping in their wake.  Here the seagulls are very happy\n"+
"with a large buffet of beached crustaceans.  There is a\n"+
"large trench to the east at the edge of the sandbar.\n";

add_listen("main", "The seagulls can be heard above you and the waves are louder.");
add_smell("main", "The smell of saltwater fills your nostrils.");


items = ({
  "sand",
  "The sand is a darker color here and it shifts shapes as the water rushes over it",
  "water",
  "The water is a foggy blue and the small waves crest in a lighter blue green color.",
  "creatures",
  "These small crustaceans are fighting for life until the waves come back in.", 
  "wave",
  "A wave comes up and covers the sand and creatures before going back out",
  "waves",
  "Waves rushing in and out playing with the small creatures that live here",
    });

dest_dir = ({
  "/players/jamila/beach/beach12.c","north",
  "/players/jamila/beach/beach10.c","south",
  "/players/jamila/beach/beach16.c","east",
  "/players/jamila/beach/beach3.c","west",
  });

}
