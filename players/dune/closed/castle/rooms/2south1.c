inherit "room/room";
#include "definitions.h"

reset(arg) {

        if(!present("catoblepas"))
        move_object(clone_object(CASTLEMONSTER+"/catoblepas.c"),this_object());

        if(!arg) {
        set_light(1);
        short_desc="Marshes";
        long_desc=
"     You smell a slight stench here as you push your way through the\n"+
"many cattails and marshweed.  There is no dry land here, only a very\n"+
"depressing layer of slime and mud.  Here and there, you see the shore of\n"+
"what must be another large water patch.  Mist tends to clump in certain\n"+
"areas, sometimes rising above your very head.\n";

   dest_dir=({
        CASTLEROOM+"/2se1.c","north"  ,
        CASTLEROOM+"/sroad2.c","west"  ,
            });

   items=({
        "marshweed","     The marshweed grows up to your waist",
        "slime","     The slime is green and yellow in color",
        "mist","     The mist looks like fog, it is so thick",
        "cattails","They grow abundantly here",
   });
   }   }
