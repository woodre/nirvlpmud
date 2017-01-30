/* DO NOT REMOVE - The cyber arena sends messages to this room still. Pup */
/* Based on Feld's arena */
inherit "/players/dune/closed/guild/rooms/room";
#include "../DEFS.h"

reset(arg) {
   if (arg) return;
   set_light(1);
   short_desc="Balcony";
   long_desc=
   "A long section of bleachers stretch from one end to the other end.\n"+
   "From this location, there is an incredible view of the CyberNetic\n"+
   "arena, below.\n";
   
   dest_dir=({
         "/players/dune/closed/guild/rooms/hallway3.c","surface"
});
}
query_no_fight() {
   return 1;
}
