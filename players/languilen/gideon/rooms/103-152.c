#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define TPN this_player()->query_name()
#define TP this_player()
inherit "room/room";


reset(arg) {
     if(arg) return;
     set_light(1);

     short_desc = "The Bazaar";
     long_desc =
"    Variously colored tents selling a wide variaty of items lie open\n\
in all directions.  Weapons to the north, armors to the south, someone\n\
selling refreshments to the west and a magic shop to the east.  One\n\
large tent stands out from among the rest to the northwest.  Unlike\n\
the others it is closed and made of entierly black matireal.  It has\n\
a sign above the door.\n";

     items = ({
  "tents","Colorfull, bright pastells and richly garnished fabrics attempt\n\
to attract the attention and raise the spirits of those passing by",
});

     dest_dir = ({
        AREA+"104-153.c","northeast",
        AREA+"102-151.c","southwest",

});

}
