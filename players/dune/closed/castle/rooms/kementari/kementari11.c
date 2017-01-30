inherit "room/room";
#include "definitions.h"

reset(arg) {

if (!present("knight"))
  move_object(clone_object(CASTLEMONSTER+"/sithi_knight.c"),
  this_object());

   if(!arg) {
   set_light(1);
   short_desc=("The Ruins of Kementari");
   long_desc=
"     Before you sits a huge pile of boulders.\n"+
"It seems as if it were artificially formed.\n"+
"The heavy stones must have been lifted by a\n"+
"strong arm to be stacked as high as they are.\n";

   dest_dir=({
   CASTLEROOM+"/kementari10.c","north"  ,
            });

   items=({
   "pile","     The pile is square-like in shape",
   "boulders","     The boulders are huge and heavy",
   "stones","     The stones are packed like bricks",
   });
   }   }
