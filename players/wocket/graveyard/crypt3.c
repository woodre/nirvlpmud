#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/graveyard/"
inherit "/players/wocket/graveyard/crypt1.c";

reset(arg){
  ::reset(arg);
  if(arg) return ;
long_desc = ""+
"   This small little nook in the dryants' crypt is filled with dead bodies.\n"+
"Many of them lie in a heap, rotting and giving off a foul stench.  The\n"+
"walls are lined with corpses and scattered bones.  Dirt cover the stone walls\n"+
"as little light makes its way into the crypt.\n";
items += ({
  "corpses","They are corpses of passed dryants",
           "bones","The flesh has been eaten away by time and now dirt covers them",
});
dest_dir = ({
PATH+"crypt2.c","west",
});
}
