inherit "room/room";
#include "definitions.h"

reset(arg) {

if (!present("sithi"))
  move_object(clone_object(CASTLEMONSTER+"/sithi_man.c"),
  this_object());
if (!present("lord"))
  move_object(clone_object(CASTLEMONSTER+"/dais_lord.c"),
  this_object());

   if(!arg) {
   set_light(0);
   short_desc=("The Ruins of Hikehikayo");
   long_desc=
"     The cave abruptly stops in what looks to be\n"+
"a large pavilion.  Sparkling pinpoints of\n"+
"light beautify the area.  Huge cracks in the earth\n"+
"have torn apart this once beautiful town center.\n";

   dest_dir=({
   CASTLEROOM+"/hikehikayo3.c","north"  ,
            });

   items=({
   "pinpoints","     The sparkles seem to come from gems",
   "pavilion","     It is torn to pieces by past earthquakes",
   "cracks","     The cracks are everywhere.  This is a disaster area",
   });
   }   }
