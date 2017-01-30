#include "/players/khrell/define.h"
#include "/players/khrell/ansi.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(HIG+"Goblin Caves"+NORM);
   set_long(
"   This wide opening has been crudely chiseled and worked in a\n"+
"rough manner.  Poorly made support beams frame the tunnel and\n"+
"appear to be an attempt to keep any cave-ins from crushing any\n"+
"who dare to walk though this area. The stink of urine and fecal\n"+
"matter assails your senses and threatens to make you sick. Above\n"+
"your head hangs a sturdy rope you can probably climb.\n");
   set_light(1);
   add_listen("main", "You hear nothing except your own heartbeat\n");
   add_smell("main", "You smell urine and fecal matter\n");
   add_smell("urine", "You smell the lovely stench of urine\n");
   add_smell("fecal", "You smell the stench of fresh droppings\n");
   items = ({
         "beams", "Many crude and poorly cut and shaped beams of poor design",
         "rope", "A sturdy rope you can climb",
         "opening", "A widened entrance to this tunnel",
         "tunnel", "A rough hewn and dug passage"
         });
   dest_dir = ({
         "players/khrell/area/goblins/gobrm2", "north",
         });
   
   return 1; }

init()
{
   ::init(); 
   add_action("exit_function", "climb");
   add_action("go_north","north");
   add_action("go_north","n");
}

go_north()
{
   if(!this_player()) return;
   if(this_player() && this_player()->is_player())
      return 0;
   else
      return 1;
}
exit_function(string str)
{
    if (!str || str != "rope")
    {
        notify_fail("What are you thinking?\n");
        return 0;
    }
    this_player()->move_player("up the rope#/players/khrell/shaft.c");
    return 1;
}
