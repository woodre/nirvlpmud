#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(HIG+"Goblin Caves"+NORM+" (Warped Passage)");
   set_long(
"   The tunnel continues, the normal solid feel of the stone now gives\n"+
"way to a soggy thick mud like sensation, Making each step difficult.\n"+
"Off to the east appears to have once been a side tunnel, but the\n"+
"stone seems to have flowed over the opening, leaving only a small\n"+
"gap where muffled gibbering can almost be heard from within.\n");
   set_light(1);
   add_listen("main", "You hear insane gibbering\n");
   add_listen("gibbering", "You hear insane gibbering sounds\n");
   add_smell("main", "You smell foul odors yet cannot identify their source.\n");
   items = ({
	         "tunnel", "It seems to be half covered by once dripping stone.",
	         "opening", "It seems to be half covered by melted stone.",
	         "stone", "It looks solid and stable but it also ripples like water.",
	         "gap", "A small opening just large enough to fit through",
	         "mud", "Semi liquid and yet solid substance",
             });
   dest_dir = ({
         "players/khrell/area/goblins/gobrm7.c", "south",
         "players/khrell/area/goblins/gobrm9.c", "north",
         "players/khrell/area/goblins/gobrm13.c", "opening"
         });
}
