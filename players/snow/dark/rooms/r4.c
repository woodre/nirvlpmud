/* DarK ArenA southern-middle */

inherit "/players/snow/dark/rooms/arch.c";
#include "/players/snow/dark/defs.h"
#include "/players/snow/closed/cyber/color.h"
 
reset(arg){
 if(!arg){

 short_desc=BOLD+"DarK ArenA"+OFF;
 long_desc=
 "This is the southern-middle of the "+BOLD+"DarK ArenA"+END+
 ".\n Dark, shadowy spaces stretch in every direction except\n\
  southerly.\n";
 
items=({
 "shadows", "There are shadows all around you...",
});
 
set_light(-1);

  dest_dir=({
  C1, "north",
  C8, "east",
  C9, "west",
  C5, "northwest",
  C3, "northeast",
  });
  }   }
