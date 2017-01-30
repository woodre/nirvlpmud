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
"A small brook trickles down from the east and continues its journey west.\n"+
"Maple and alder trees grow tall and their leaves block some of the light\n"+
"from the sun, making it cool and slightly damp here next to the slow moving\n"+
"water of the brook.  Clumps of ferns and bushes mix together making it hard\n"+
"to see very far in any direction.  There are small footprints in the wet\n"+           
"earth along the bank of the brook. They lead east and west for the most part,\n"+
"though some seem to wander off into the ferns and bushes.\n";

items = ({
"brook",   "Only three to four feet wide at this point, it meanders down from the east\n"+
           "and continues on its way to the west",
"water",   "Crystal clear and very cold",
"ferns",   "Deep green and bushy, they grow near the brook and around the base of the trees",
"trees",   "The trees all blend in together, but you can tell they are maple and alder",
"earth",   "Rich dark loam like that found in most wooded areas",
"maple",   "The maple trees are rather pear shaped and have symmetrical three fingered leaves",
"alder",   "The alder trees look very much like the maple, but not as broad at the top",
"bushes",  "Gooseberry, rhododendrons in full bloom, wild grape and a few vine maple",
"bank",    "Mostly damp forest earth, with a few partially exposed round, grey rocks",
"footprints", "No bigger than your thumb, they must belong to very small fairy folk",

});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc4.c"),this_object());

dest_dir = ({
   "/players/fakir/woods/room8.c", "west",
   "/players/fakir/woods/room10.c", "east",
   "/players/fakir/woods/room24.c", "southwest",
});
}


