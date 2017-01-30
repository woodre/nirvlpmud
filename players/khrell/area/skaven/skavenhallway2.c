#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+"["+RED+"Warlord"+NORM+"]");
   set_long(
"   The holdings of the Warlord are oppulent, as only skaven can make\n"+
"it.  Torn banners, paintings and tapestries decorate the walls here\n"+
"and soiled rugs cover the floor.\n");
   set_light(1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell the foul smells of skaven living.\n");
   items = ({
         "banners", "Captured or stolen, they have all but been torn to shreds",
         "paintings", "Whatever they depicted they are now just a stained canvas",
         "rugs", "At one time they may have been valueable, now just a trampled and torn mess",
         "tapestries", "They have been shredded leaving only fragments"});
   dest_dir = ({
         "players/khrell/area/skaven/ss19.c", "west",
         "players/khrell/area/skaven/skavenlordchamber.c", "enter"});
   move_object(clone_object("/players/khrell/monster/skaven/stormvermin.c"), this_object());
   move_object(clone_object("/players/khrell/monster/skaven/stormvermin.c"), this_object());
   return 1; }
