/* DarK ArenA CentraL */

inherit "/players/snow/dark/rooms/arch.c";
#include "/players/snow/dark/defs.h"
#include "/players/snow/closed/cyber/color.h"
 
reset(arg){
 if(!arg){

 short_desc=BOLD+"DarK ArenA CentraL"+OFF;
 long_desc=
 "This is the center of the "+BOLD+"DarK ArenA"+END+".\n\
  Dark, shadowy spaces stretch in every direction.\n";
 
items=({
 "shadows", "There are shadows all around you...",
});
 
set_light(-1);

  dest_dir=({
  C2, "north",
  C3, "east",
  C4, "south",
  C5, "west",
  C6, "northwest",
  C7, "northeast",
  C8, "southeast",
  C9, "southwest",
  "/players/snow/gate.c","vortex"});
  }   }
