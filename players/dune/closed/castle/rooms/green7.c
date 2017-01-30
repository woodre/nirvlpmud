inherit "room/room";
#include "definitions.h"

reset(arg) {
   if(!arg) {
   set_light(1);
   short_desc=("Middle Green Plains");
   long_desc=
"     Broad green grass plains stretch across the\n"+
"greater expanse of your view.  The land slopes\n"+
"gently, making for easy travel.  A few pine trees\n"+
"grow in isolated patches, but the land is mainly wide\n"+ 
"open.  Very far off in the southwest, you can see tall\n"+
"mountains.  Farmland lies to the north.\n";

   dest_dir=({
   CASTLEROOM+"/green10.c","west"  ,
   CASTLEROOM+"/green8.c","south"  ,
   CASTLEROOM+"/green2.c","east"  ,
   CASTLEROOM+"/green6.c","north"  ,
            });

   items=({
   "plains","     The plains stretch for miles",
   "land","     The land is smooth and green",
   "trees","     The trees are short and few in numbers",
   "mountains","     The mountains are too far to clearly see",
   "farmland","     The farmland continues for miles northward",
        });
   }   }
