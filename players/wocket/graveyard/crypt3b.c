#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/graveyard/"
inherit "/players/wocket/graveyard/crypt1.c";

reset(arg){
  ::reset(arg);
  if(arg) return ;
long_desc = ""+
"  Bodies have been stacked to the ceiling and tossed in heaps.  The\n"+
"number of bodies is enormous.  Piles of them have been layed up against\n"+
"dirt covered walls.  Surprisingly the smell isn't as bad as in other rooms.\n"+
"Little air flows through here and even less light.\n";
items += ({
"piles","Piles of dead dryants rest against the walls",
});
smells = ({
"default","The horrible stench fills the air but is weaker then before",
"room","There is a damp musky smell in the room",
"flesh","It give a horrid stench as it rots from the bodies",
"air","It is very stale as little of it circulates",
});
dest_dir = ({
  PATH+"crypt2b.c","west",
});
}
