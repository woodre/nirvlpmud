#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+"["+HIW+"Skryre"+NORM+"]");
   set_long(
"   This is the second floor of the spiraling labratory tower of\n"+
"Clan Skryre's holdings.  Here is where alot of their machinery \n"+
"is built and tested.  Various blackened burns and chunks of many\n"+
"different targets litter the floor here.\n");
   set_light(-1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "burns", "It looks as if some flame type weapon was tested here",
         "burn", "It looks as if some flame type of weapon was used here",
         "chunks", "Various debris of some sort of targets",
         "targets", "Some of them were mockup dummies and some were probally alive",
         "target", "This might have been a dummoy or some poor slave, it's impossible to tell now",
         "floor", "It's littered with the remains of different targets"});
   dest_dir = ({
         "players/khrell/area/skaven/skavenskyrelab1.c", "down",
         "players/khrell/area/skaven/skavenskyrelab3.c", "up"});
   move_object(clone_object("/players/khrell/monster/skaven/warleng2.c"), this_object());
   return 1; }
