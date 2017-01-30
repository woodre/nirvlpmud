/*  augmented finger command | Last mod:  apr2002.11  */

#include "/players/forbin/define.h"

main(str)
  {
  object f;
  if(!str) return 0;
  f = clone_object("/players/pestilence/closed/pestyfin.c");
  MO(f,TP);
  command("fin "+str,TP);
  destruct(f);
    return 1;
  }
