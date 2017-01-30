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
"    Here in the bazaar all manner of things can be found for those\n\
with expensive tastes and those a little light of pocket.  Many tents\n\
and light wooden structures have been erected here by the purveyors of\n\
goods to facilitate sales.  An exit to the southwest leads out into an\n\
intersection.  To the northeast the tents continue.\n";

     items = ({
  "tents","Colorfull, bright pastells and richly garnished fabrics attempt\n\
to attract the attention and raise the spirits of those passing by",
});

     dest_dir = ({
        AREA+"103-152.c","northeast",
        AREA+"101-150.c","southwest",

});

}
