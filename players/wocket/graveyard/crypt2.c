#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/graveyard/"
inherit "/players/wocket/graveyard/crypt1.c";

reset(arg){
  ::reset(arg);
  if(arg) return ;

long_desc = ""+
"   The stench is dreadfull from the rotting bodies that litter the\n"+
"ground.  Heaps of dead dryants rest in unorganized array while others are\n"+
"layed in a more natural position.  The stone walls are covered with caked\n"+
"dirt making it almost look like a cave.\n";
items += ({
  "bodies","They are the rotting corpses of passed dryants.  Much of their skin\nhas been torn away",
});
dest_dir = ({
  PATH+"crypt3.c","east",
  PATH+"crypt4.c","north",
  PATH+"crypt5.c","west",
  PATH+"crypt1.c","up",
});

}

