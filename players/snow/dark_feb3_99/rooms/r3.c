/* DarK ArenA eastern-middle */

inherit "/players/snow/dark/rooms/arch.c";
#include "/players/snow/dark/defs.h"
#include "/players/snow/closed/cyber/color.h"
 
reset(arg){
 if(!arg){

 short_desc=BOLD+"DarK ArenA"+OFF;
 long_desc=
 "This is the eastern-middle of the "+BOLD+"DarK ArenA"+END+
 ".\n Dark, shadowy spaces stretch in every direction except\n\
  easterly.\n";
 
items=({
 "shadows", "There are shadows all around you...",
});
 
set_light(-1);

  dest_dir=({
  C7, "north",
  C8, "south",
  C1, "west",
  C2, "northwest",
  C4, "southwest",
  });
  }   }
