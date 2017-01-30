#include "/players/jamila/ansi.h"
#define tp this_player()
inherit "/players/vertebraker/closed/std/room.c";


reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Soft Beach";
long_desc =
"  This is the sandbar.  The water here is up to your\n"+
"knees.  The seagulls no longer swarm above your head but\n"+
"are replaced now by large pelicans.  Small fish swim here\n"+
"and the brave ones swim around your legs.\n";

add_listen("main", "You hear the beating of large wings as a Pelican glides by you.");
add_smell("main", "The smell of saltwater fills your nostrils.");


items = ({
  "water",
  "The water is a foggy blue and the small waves crest in a lighter blue green color.", 
  "sand",
  "The sand below the water ripples as the waves move over it.",
  "waves",
  "The foggy blue waves crest around you.",
  "wave",
  "A wave comes toward you and the warm water rises and then falls on your legs",
    });

dest_dir = ({
  "/players/jamila/beach/beach14.c","north",
  "/players/jamila/beach/beach16.c","south",
  "/players/jamila/beach/beach18.c","east",
  "/players/jamila/beach/beach12.c","west",
  });
              if(!present("pelican"))
{
move_object(clone_object("/players/jamila/beach/mobs/pelican.c"),this_object());
}
if(!present("fish"))
{
move_object(clone_object("/players/jamila/beach/mobs/fish.c"),this_object());
}
}
