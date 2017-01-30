#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(YEL+"Ruins of Khazad Naggrund"+NORM);
   set_long("\
 The walls of this passage are well crafted.  It is plain and lacks\n\
any decoration.  To the north is a large pile of rubble preventing \n\
anyone from heading in that direction.\n");
   set_light(1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "walls", "They are well crafted but hold nothing special",
         "wall", "It is well crafted but holds nothing special",
         "passage", "Time and elements have collasped this place, leaving a small area to move in",
         "pile", "A mass of stone heaped together",
         "rubble", "A large pile of collapsed stone"});
   dest_dir = ({
         "players/khrell/area/underways/undermdh1.c", "south"});
   return 1; }
