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
"A small brook trickles down from the east and continues its journey\n"+
"west.  Maple, alder, and ash trees grow thickly here, their trunks\n"+
"so close together it is almost impossible to find a way through.  The\n"+
"air is cool and slightly damp.  Clumps of ferns and bushes grow in such\n"+
"abundance they create a barrier in almost any direction other than along\n"+
"the bank of the brook east or west.  There are small footprints in the\n"+
"wet earth next to the brook. They lead east and west for the most part,\n"+
"though some lead off into the ferns and bushes.\n";

items = ({
"brook",   "Only a three to four feet wide at this point, it meanders down from the east\n"+
           "and continues on its way to the west",
"water",   "Crystal clear and very cold",
"ferns",   "Deep green and bushy, they grow near the brook and around the base of the trees",
"trees",   "The trees all blend in together, but you can tell they are maple, alder, and ash",
"earth",   "Rich dark loam like that found in most wooded areas",
"footprints", "No bigger than your thumb, they must belong to very small fairy folk",
"maple",   "The maple trees are rather pear shaped and symetrical three fingered leaves",
"alder",   "The alder trees look very much like the maple, but not as broad at the top",
"ash",     "The ash trees are oval in shape, and have small delicate leaves of silver and green",
"trunks",  "They are so close together it is hard to tell one from another",
"bushes",  "Gooseberry, rhododendrons in full bloom, wild grape and a few vine maple",
"bank",    "Mostly damp forest earth, with a few partially exposed round, grey rocks",


});
if(!present("minion",this_object()))
 move_object(clone_object("/players/fakir/woods/NPC/minion.c"),this_object());
if(!present("calendula",this_object()))
 move_object(clone_object("/players/fakir/woods/OBJ/calendula.c"),this_object());

dest_dir = ({
   "/players/fakir/woods/room9.c", "west",
   "/players/fakir/woods/room11.c", "east",
  
});
}


