#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(YEL+"Khazad Naggrund"+NORM+"("+HIK+"Main Hold"+NORM+")");
   set_long("\
  A well manned guard post exists here.  Though a casual observer\n\
might take this as a unwelcome way of greeting visitors, it does\n\
serve a purpose to keep out the denizens of the Underways that may\n\
attempt to gain entry.  A large sign sits above a doorway leading\n\
into some sort of merchant's shop.  To the west extends more of\n\
what can only be called a merchants quarter.\n");  
   set_light(1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "guard post", "A small stone wall ment as a first defence aginst intruders",
         "sign", "A sign that reads 'The Hungry Furnace'",
         "doorway", "It is dark and doesn't look to hav ebeen used in quite awhile"});
   dest_dir = ({
         "players/khrell/area/dwarf/rm1.c", "south",
         "players/khrell/area/dwarf/rm6.c", "north",
         "players/khrell/area/dwarf/rm3.c", "west"});
   return 1; }      
