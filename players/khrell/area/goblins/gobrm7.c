#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(HIG+"Goblin Caves"+NORM);
   set_long(
"   The tunnel opens slightly creating room to stand almost straight\n"+
"up.  Again the crude mine workings of the goblins is readily apparent\n"+
"but then something seems really odd.  The wood is appears to be fused\n"+
"to the stone and it looks as if the wood and stone were like liquid \n"+
"and running together before returning to a solid state.\n");
              
   set_light(0);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell something foul but cannot identify it.\n");
   items = ({
	         "wood", "It appears to have been twisted and warped by soem unknown means",
	         "stone", "Apparently this had the solidity of water before suddently hardening.",
	         "workings", "Shoddy timbers and support beams lashed together with half rotten rope.",
	         "tunnel", "A widened rock passage that stretches before you",
	         "mine", "A worked rock passage that widens before you",
	         "ropes", "Well worn and half decayed ropes",
	         "timbers", "Poorly cut to be supports now apparently turned liquid then solid",
	         "supports", "Poorly cut supports now apparently semi liquid yet also solid"
           });
   dest_dir = ({
         "players/khrell/area/goblins/gobrm6.c", "south",
         "players/khrell/area/goblins/gobrm8.c", "north"
         });
}
