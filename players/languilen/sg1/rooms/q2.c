/*
 *
 */
#include "../paths.h"
#include "/players/languilen/langdefs.h"
#include "/players/languilen/closed/ansi.h"
inherit "room/room";

reset(arg) {
     if(arg) return;
     set_light(1);

     short_desc = "Personel Quarters";
     long_desc =
"    For living quarters this place is poorly decorated, it's fasion keeping\n\
in step with all the other rooms in the complex.  One notable niceity being\n\
a small bed.  Beside the bed a chest of drawers and\n";

     items = ({
     "bed","bed description",
     });

     dest_dir = ({
     ROOM + "ehall.c","west",
});

}
