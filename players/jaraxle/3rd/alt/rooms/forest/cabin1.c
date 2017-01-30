#include <ansi.h>
#include "defs.h"
inherit "/players/wocket/std/tvroom.c";

reset(arg){
  if(arg) return;
  short_desc = "A log cabin";
  long_desc = "   "+
     YEL+"A large log cabin.  The walls and ceiling seem to be made from\n"+
         "the same trees which haunt the wood outside.  The ground is\n"+
         "composed of packed dirt.  In the corner a small kitchen resides.\n"+
         "To the east a door hides another room.\n"+OFF;
  dest_dir = ({
    DIR+"cabinent.c","north",
    DIR+"cabin2.c","east",
  });
  items = ({
    "walls","They are old and grey logs from the forest",
    "celing","They are old and grey logs from the forest",
    "floor","It is very smooth soft packed dirt",
    "kitchen","A small kitchen in the corner.\nIt comprises of many pots and pans",
    "door","A large wood door",
  });
  smells = ({ "default","You smell pine of the logs", });
  listens = ({ "default","You hear the living forest outside",});
  set_light(1);
}

