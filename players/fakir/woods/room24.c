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

"Maple and alder trees grow tall and their leaves block some of the light\n"+
"from the sun, making the air cool and slightly damp.  Clumps of ferns and\n"+
"bushes grow here and there, and a thick layer of ivy covers the ground and\n"+
"climbs the trunks of some of the trees.\n";

items = ({
"trunks",  "Maple and alder for the most part, and some are covered in Ivy",
"leaves",  "They rustle slightly in the cool breeze",
"ivy",     "Growing thickly in some places, it has covered most of the ground\n"+
           "and climbs the trunks of the trees nearby to a height of about six\n"+
           "feet.  It is a deep green in color and its vines grab at your feet",
"ferns",   "Deep green and bushy, they grow near the trunks of the trees",
"trees",   "Mostly maple and alder",
"ground",   "Rich dark loam like that found in most wooded areas",
"maple",   "The maple trees are rather pear shaped and have symmetrical three fingered leaves",
"alder",   "The alder trees look very much like the maple, but not as broad at the top",
"bushes",  "Gooseberry, rhododendrons in full bloom, wild grape and a few vine maple",
"bank",    "Mostly damp forest earth, with a few partially exposed round, grey rocks",
"footprints", "No bigger than your thumb, they must belong to very small fairy folk",

});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc3.c"),this_object());

dest_dir = ({
   "/players/fakir/woods/room9.c", "northeast",
   "/players/fakir/woods/room23.c", "south",
});
}
