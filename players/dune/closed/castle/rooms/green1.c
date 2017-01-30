inherit "room/room";
#include "definitions.h"

reset(arg) {

   if (!present("seal"))
     move_object(clone_object(CASTLEOBJECT+"/seal.c"),this_object());

   if (!present("hawk")) 
     move_object(clone_object(CASTLEMONSTER+"/hawk.c"),this_object());

   if(!arg) {
   set_light(1);
   short_desc=("Northeastern Green Plains");
   long_desc=
"     Broad green grass plains stretch across the\n"+
"greater expanse of your view.  The land slopes\n"+
"gently, making for easy travel.  A few pine trees\n"+
"grow in isolated patches, but the land is mainly wide\n"+ 
"open.  Very far off in the southwest, you can see tall\n"+
"mountains.  Farmland lies to the north.\n"+
"The World of Nirvana\n";

   dest_dir=({
   CASTLEROOM+"/green6.c","west"  ,
   CASTLEROOM+"/green2.c","south"  ,
   "/room/plane8.c","nirvana"  ,
        });

   items=({
   "plains","     The plains stretch for miles",
   "land","     The land is smooth and green",
   "trees","     The trees are short and few in numbers",
   "mountains","     The mountains are too far to clearly see",
   "farmland","     The farmland continues for miles northward",
   "nirvana","     This is the way back to Nirvana",
   "world","     This is the way back to Nirvana",
        });
   }   }
