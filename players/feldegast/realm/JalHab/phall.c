#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(!present("elder"))
    move_object(clone_object(MON_PATH+"pkolitor.c"),this_object());
  if(arg) return;
  set_light(1);
  short_desc="Hall of P'kal";
  long_desc=
"  This is the village meeting hall of the P'kalians.  It is here\n"+
"that they meet to recount the history of their people.  The walls\n"+
"of the meeting hall are painted with murals of important moments\n"+
"in their history.  A raised dais with a stone podium is at the far\n"+
"end of the hall, opposite the entrance.\n";
  items=({
    "murals",
"  The murals depict the creation and enslavement of the p'kalians by\n"+
"the Majiri, a majestic empire spanning the continent, ruled by\n"+
"magicians and sorcerers of unsurpassed power and intellect.  The\n"+
"Majiri used the p'kalians to work the fields, dig their mines, and\n"+
"build their cities.\n"+
"  A pestilence fell upon the land in the form of a demon lord,\n"+
"summoned by a foolish Majiri lord who mistakenly believed that it\n"+
"could bring him power.\n"+
"  In the chaos following the downfall of the Majiri empire, many\n"+
"p'kalians escaped into the wilderness, killing many of their masters\n"+
"on the way.\n"+
"  Slowly, the landscape began to change from valleys and hills covered\n"+
"in trees to an arid and rocky desert.  Hard times befell the p'kalians\n"+
"as they learned to adapt to their new environment, where to dig for\n"+
"wells and which of the now poisonous plants were edible.  In time,\n"+
"they learned to thrive in the desert and built villages upon the\n"+
"Majiri ruins",
  "dais","A raised platform at the end of the hall",
  "podium","A sandstone block atop the dais",
  });
  dest_dir=({
    PATH+"pwell.c","east",
  });
}
