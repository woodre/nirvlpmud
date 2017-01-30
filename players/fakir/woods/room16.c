#define TP this_player()
#define TPN this_player()->query_name()
#include "/players/fakir/color.h"
#define TPP this_player()->query_possessive()
inherit "room/room";
int found;

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "Inside a Log";
long_desc =
"Even with a light it is still mostly dark inside the log.  Obviously\n"+
"this is the lair of a very nasty varmint...a bobcat.  You are very\n"+
"lucky the mother cat is not home right now.\n";

items = ({
"log",   "Inside the log it is warm and snug, and smells of rotting wood",
"lair",  "For a bobcat, this is what they call home.  It is warm, dry, and\n"+
         "a bit smelly.  It is never a good idea to get caught inside a wild\n"+
         "animals lair",

});
if(!present("bcat")) {
 move_object(clone_object("/players/fakir/woods/NPC/bcat.c"),this_object());
 move_object(clone_object("/players/fakir/woods/NPC/bcat.c"),this_object());
}
dest_dir = ({
   "/players/fakir/woods/room15.c", "crawl",
});
}
