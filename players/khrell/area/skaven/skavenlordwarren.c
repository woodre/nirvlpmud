#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+"["+RED+"Warlord"+NORM+"]");
   set_long(
"   This is the main lair for the warlord.  He spends most of his\n"+
"off hours here.  A crude table sits directly in the center of the\n"+
"room, and a large bed sits off to the side.  On the far side of the\n"+
"room sits a small opening, partially hidden in deep shadows.\n");
   set_light(1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "table", "The Warlord does most of his feeding here apparently",
         "bed", "Like all other skaven beds, a straw filled mattress",
         "opening", "It looks like you can 'enter' it easily enough",
         "shadows", "They are deeper then normal, perhaps magical in nature"});
   dest_dir = ({
         "players/khrell/area/skaven/skavenlordchamber.c", "out",
         "players/khrell/area/skaven/skavenlordharem.c", "enter"});
   move_object(clone_object("/players/khrell/monster/skaven/stormvermin.c"), this_object());
   move_object(clone_object("/players/khrell/monster/skaven/stormvermin.c"), this_object());
   return 1; }
