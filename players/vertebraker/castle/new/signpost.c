#include "../../define.h"
inherit ITEM;

void reset(int x) {
   if(x) return;
   set_id("post");
   set_alias("signpost");
   set_short("A tall signpost");
   set_long(
      "This is a tall piece of thick silverbark shooting straight up in the air\n"
      +"from the ground.  Several dark placards with carvings notched into them\n"
      +"hang from the sides.\n\n"
      +BOLD+BLK+"The Dark Forest - -"+NORM+" - - - - North\n\n"
      +BOLD+BLK+"Village of Pratho -"+NORM+" - - - - West\n\n"
      +BOLD+BLK+"Nirvana - - - - - -"+NORM+" - - - - East\n\n"
      +BOLD+BLK+"Sin'tara - - - - - "+NORM+"- - - - South\n\n"
      +BOLD+BLK+"The Dwarven Tunnels"+NORM+" - - - - Southwest\n\n"); }

get() { return 0; }
