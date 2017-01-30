#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" ["+HIK+"Greyseer"+NORM+"]");
   set_long(
"   Although by civilized standards this room is unfit for living, to\n"+
"the skaven, it is well kept and furnished.  A crude straw mat lies\n"+
"in the corner, and a basic table sits in the middle of the room.\n"+
"From this place one can clearly see exits leading into what appears\n"+
"to be the laboratory, library, and some dark shadowed room where quiet\n"+
"chittering can be heard.\n");
   set_light(-1);
   add_listen("main", "You hear quiet chittering comming from a darkened room ahead.\n");
   add_smell("main", "You smell stagnant air.\n");
   items = ({
         "mat", "It's basically a heap of straw with a dirty soiled cloth covering",
         "corner", "It is bathed in darkness as befitting the light hating skaven",
         "table", "More of a large stump of an ancient tree then a table",
         "exits", "One leads to a library, one leads to a laboratory and one looks to lead to a altar room"});
   dest_dir = ({
         "players/khrell/area/skaven/skavenhallway1.c", "down",
         "players/khrell/area/skaven/skavengreyslibrary.c", "library",
         "players/khrell/area/skaven/skavengreysaltarrm.c", "altar",
         "players/khrell/area/skaven/skavengreyslab.c", "lab"});
   return 1; }
