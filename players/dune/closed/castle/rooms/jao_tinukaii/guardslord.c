inherit "room/room";
#include "definitions.h"

int l;

reset(arg) {

    if (!present("knight")) {
      for(l=1;l<=2;l++)
      move_object(clone_object(CASTLEMONSTER+"/sithi_knight.c"),this_object());
      }
    if (!present("sithi"))
    move_object(clone_object(CASTLEMONSTER+"/sithi_knight.c"),this_object());

        if(!arg) {
        set_light(1);
        short_desc="King's Guard";
        long_desc=
"     A long thin hallway stretches before you.  At the southern end,\n"+
"a large set of fancy doors blocks off further view.  Along the walls,\n"+
"pictures and vases are neatly ordered.  Withered plants decorate\n"+
"the hall as well.\n";

   dest_dir=({
        CASTLEROOM+"/lordchambers.c","south"  ,
        CASTLEROOM+"/room1.c","east"  ,
        CASTLEROOM+"/dining.c","north"  ,
            });

   items=({
        "pictures",
"     The pictures seem to tell a story.  You follow the pictures as\n"+
"they seem to be ordered:\n"+
"\n"+
"A sithi is seen leading smaller sithis into this very temple.\n"+
"The sithi summons a devil thing from a septagram.\n"+
"The sithi faces a diabolic figure in contemplation.\n"+
"The sithis wage war against men, elves, and other races, led by\n"+
"devils and the head sithi",
        "vases","     The vases are solid black in color",
   });
   }   }
