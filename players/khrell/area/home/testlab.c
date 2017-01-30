#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(BLINK+"Testing Labratory"+NORM);
   set_long("\
   A menagre of endless testing equipment fills this room from floor to \n\
ceiling.  Many unidentified stains lay splattered all over the place. A \n\
constant mechanical hum echos through the chamber and a metalic tang is \n\
in the air.\n");   
   set_light(1);
   add_listen("main", "You hear mechanical hum.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "item", "NO/N"});
   dest_dir = ({
         "players/khrell/area/home/entrance.c", "west",
         "players/khrell/area/home/arena.c", "in"});
   return 1; }
