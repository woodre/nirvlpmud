#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+HIK+" - Eshin"+NORM);
   set_long(
"   This is the area where all the initates and adepts of clan\n"+
"Eshin practice and perfect their stealthy arts.  A simple yet\n"+
"effective stone pit rests in the center.  Though not deep it\n"+
"still serves as a border for combatants.  Far off is a doorway\n"+
"leading to the headmasters chambers.\n");    
   set_light(0);
   add_listen("main", "You hear nothing.\n");
   add_smell("main", "You smell nothing special.\n");
   add_property("fight_area");
   items = ({
         "stone", "Chiseled and shaped stone that forms a complete circle that fills the room",
         "pit", "Created from carefully cut stone slabs",
         "doorway", "Its veiled in shadows with a dark cloth covering"});
   dest_dir = ({
         "players/khrell/area/skaven/skaveneshindojo.c", "southwest",
         "players/khrell/area/skaven/skaveneshinmasterrm.c", "enter"});
   move_object(clone_object("/players/khrell/monster/skaven/nightrun1.c"), this_object());
   return 1; }
