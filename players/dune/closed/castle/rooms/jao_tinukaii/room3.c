inherit "room/room";
#include "definitions.h"

reset(arg) {

if (!present("darkshadow")) {
      move_object(clone_object(CASTLEMONSTER+"/darkshadow.c"),this_object());
   }

        if(!arg) {
        set_light(1);
        short_desc="Entrance to main worship area";
        long_desc=
"     Several dozen candles surround an entrance into what looks like\n"+
"a church.  A book resting upon a pedestal lies opposite the entrance.\n"+
"It seems a little darker inside the church.\n";

   dest_dir=({
        CASTLEROOM+"/foyer.c","south"  ,
        CASTLEROOM+"/room1.c","west"  ,
        CASTLEROOM+"/pews.c","enter"  ,
        CASTLEROOM+"/sithichambers.c","east"  ,
        CASTLEROOM+"/room4.c","northeast"  ,
            });

   items=({
        "book",
"     You take a look at the book and read the following:\n"+
"\n"+
"Sysili'ta---- 'Tamana'se - ele naa ot'a?\n"+
"Unigato------ 34 ink'e dakas\n"+
"Khonori's---- 'seoas'aa!  sobsao asics faski'!!\n",
   });
   }   }
