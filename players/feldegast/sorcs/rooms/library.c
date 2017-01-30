#include "defs.h"

inherit ROOM;

void reset(int arg)
{
  if(arg) return;
  set_light(1);
  short_desc=BLU+"A Sorcerous Library"+NORM;
  long_desc=
"  Assembled here in this room is what is rumored to be the single\n\
largest collection of spellbooks, grimoires, codexes, magical\n\
treatises, and erotic fiction in the triplanar area.  The room is at\n\
least thirty meters long, and its mahogany bookshelves ascend three\n\
stories tall.  On the floor, students sit at fine antique tables while\n\
they study and gossip quietly.\n";
  dest_dir=({
    ROOMPATH+"tower4.c","west",
  });
  items=({
    "bookshelves","SPECIAL",
    "tables","Antique mahogany tables, expertly fluted and stained a\n"+
             "marvelous golden brown", /* Sounds better than it is */
  });
}

  
