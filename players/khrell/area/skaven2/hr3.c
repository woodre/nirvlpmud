#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" ["+CYN+"Temple of the Horned Rat"+NORM+"]");
   set_long("This is the description.\n");
   set_light(-1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "item", "NO/N"});
   dest_dir = ({
         "players/khrell/area/skaven2/hr2.c", "down"});
   move_object(clone_object("/players/khrell/EX/mob.c"), this_object());
   return 1; }

init()
{
   ::init(); 
   add_action("exit_function", "climb");
}

exit_function(string str)
{
    if (!str || str != "rope")
    {
        notify_fail("What are you thinking?\n");
        return 0;
    }
    this_player()->move_player("climbs up the rope#/players/khrell/area/skaven2/hr4.c");
    return 1;
}