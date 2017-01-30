inherit "room/room";
#include "definitions.h"

int i;

reset(arg) {

if (!present("sithi"))
  for(i = 1; i<= 7; i++)
  move_object(clone_object(CASTLEMONSTER+"/sithi_man.c"),
  this_object());
if (!present("lord"))
  move_object(clone_object(CASTLEMONSTER+"/evacuu_lord.c"),
  this_object());

   if(!arg) {
   set_light(0);
   short_desc=("The Caverns of Tumetai");
   long_desc=
"     The cave tunnel ends in a huge cavern.\n"+
"Stalagtites rim the ceiling.  Strangely, there\n"+
"are no accompanying stalagmites.  It looks as\n"+
"if some resident took them out.\n";

   dest_dir=({
   CASTLEROOM+"/tumetai15.c","south"  ,
            });

   items=({
   "stalagtites","     The stalagtites hang high above you",
   "cavern","     The cavern is very large and roomy",
   "tunnel","     The tunnel heads back into the windy cave",
   });
   }   }
