#include "../define.h"
inherit SWAMP

reset(arg) {
if(arg) return;
::reset();
set_long(
"     A strange, twisted pathway in the back end of the swamp, this\n"+
"leads both north to a small brook and east, where you can see a dark,\n"+
"black cavern.  Animals still wander around here, but they are much\n"+
"less plentiful for some reason.\n");
add_item("brook",
"The small, babbling brook runs through the swamplands\n"+
" to the north");
add_item("cavern",
"The dark, menacing cavern lies to the east");
add_item("animals",
"You spy an otter, but it quickly paddles out\n"+
" of the immediate area");
add_exit(ROOMS+"s34","north");
add_exit(ROOMS+"s37","east"); }

