#define TP this_player()
#define TPN this_player()->query_name()
#include "/players/fakir/color.h"
#define TPP this_player()->query_possessive()
inherit "room/room";
int found;

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Whispering Woods";
long_desc =
"Scattered groups of maple, alder and ash trees grow all about you,\n"+
"divided by a dirt path that leads east where the trees thin into a\n"+
"clearing.   A large log has fallen over a narrow but deep chasm. If\n"+
"you can keep your balance, you could traverse the log and explore the\n"+
"far side of the chasm.  Black lace ferns and flowers grow next to the\n"+
"log.\n";

items = ({
"flowers", "Blue iris mixed with gold, pink delphinium, and some flowering kale",
"maple",   "The maple trees are rather pear shaped and symetrical three fingered leaves",
"alder",   "The alder trees look very much like the maple, but not as broad at the top",
"ash",     "The ash trees are oval in shape, and have small delicate leaves of silver and green",
"trees",   "Mostly maple, alder, and ash trees with a few vine maple",
"path",    "I winds east into the clearing",
"clearing","An open area of the woods, covered mostly in course grass and a few small bushes",
"log",     "The trunk of an old alder tree, worn and weathered.  The bark has\n"+
           "been worn away on the top",
"chasm",   "It is too deep and its sides are too steep to climb.  The log is the only\n"+
           "means by which to cross it",
"ferns",   "Delicate and dainty, they get their name from the black stems which\n"+
           "support the green sword shaped leaves",

});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc2.c"),this_object());

dest_dir = ({
   "/players/fakir/woods/room14.c", "traverse",
   "/players/fakir/woods/room28.c", "east",
   "/players/fakir/woods/room19.c", "southwest",
   "/players/fakir/woods/room27.c", "north",
   "/players/fakir/woods/room15.c", "south",
});
}


