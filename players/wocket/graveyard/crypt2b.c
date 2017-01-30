#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/graveyard/"
inherit "/players/wocket/graveyard/crypt1.c";

reset(arg){
  ::reset(arg);
  if(arg) return ;
long_desc = ""+
"   Bodies lay scattered across the floor.  Some have been randomly tossed\n"+
"into a large heaps while others have been carefully positioned.  The smell\n"+
"has grown very strong as flesh rots from the bone.  Dirt has begun to\n"+
"cover everything including the stone walls of the crypt, giving a cave\n"+
"like atmosphere.\n";
smells += ({
  "flesh","It gives off a horride stench as it rots from bones",
});
items += ({
  "bone","They are the bones of passed dryants.  Flesh rots from them",
  "flesh","Rotting flesh that gives off a horrible stench",
  "bones","They are white and scattered everywhere",
});
dest_dir = ({
  PATH+"crypt3b.c","east",
  PATH+"crypt4b.c","south",
  PATH+"crypt1b.c","up",
});
}
