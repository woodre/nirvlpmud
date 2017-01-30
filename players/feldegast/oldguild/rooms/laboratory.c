#include "defs.h"

inherit ROOM;

void reset(int arg)
{
  if(arg) return;
  set_light(1);
  short_desc=MAG+"The Laboratory"+NORM;
  long_desc=
"  This is a large semicircular room about twenty meters long and\n\
half that many wide.  Two long workbenches, covered with assorted\n\
alchemical apparatii, spell ingredients, a troll skeleton, and other\n\
tools of the trade run the length of the room.  Along the far wall\n\
is a tall shelf stacked with spell scrolls and other texts.  You get\n\
the feeling that this room has been blown up on several occassions\n\
and then pieced back together.\n";
  items=({
    "workbenches","The two workbenches are scarred by all manner of claws, weapons,\n"+
                  "acids, and explosions.  They rather remind you of a high school\n"+
                  "shop class",
    "apparatii","It appears to consist of several apparatuses",
    "apparatuses","Together they form an apparatii",
    "ingredients","The usual spidersilk, mandrake, eye of newt, etcetera",
    "shelf","The shelf is made out of cedar and runs the length of the room",
    "scrolls","Upon closer inspection, you realize that these scrolls are mostly\n"+
              "either failed attempts or the work of amateurs",
    "texts","Even the titles of these texts are boring:\n"+
            "  Lifecycle of the Paramecium\n"+
            "  Mating Rituals of Trolls\n"+
            "  Chicken Soup for the Sorcerer's Soul",
  });
  dest_dir=({
    ROOMPATH+"tower4.c","east",
  });
  if(!present("aubec"))
    move_object(clone_object(NPCDIR+"aubec.c"),this_object());  
}
