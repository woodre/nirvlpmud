#define TP this_player()
#define TPN this_player()->query_name()
#include "/players/fakir/color.h"
#define TPP this_player()->query_possessive()
inherit "room/room";
int found;

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Near A Hollow Log";
long_desc =
"The trunk of an ancient tree, blown down by a harsh wind in the distant\n"+
"past, lies on the leaf-strewn ground.  Its open end, hollow and dark, is\n"+
"easily large enough to crawl into.  Small bones, broken and chewed, litter\n"+
"the ground about the log.\n";

items = ({
"trunk",   "Almost three and a half feet in diameter, this was once a very impressive\n"+
           "tree.  It is very likely a fierce animal now makes its home inside",
"ground",  "Hard to see with all the leaves lying on it",
"end",     "Rather jagged where it broke from the stump still standing behind.  It is\n"+
           "dark inside the hollow",
"bones",   "Mostly broken and splintered, they look like bones from small animals",
"log",     "Rather jagged where it broke from the stump still standing behind.  It is\n"+
           "dark inside the hollow.  You could probably 'crawl' inside",

});

dest_dir = ({
   "/players/fakir/woods/room16.c", "crawl",
   "/players/fakir/woods/room13.c", "north",

});
}


