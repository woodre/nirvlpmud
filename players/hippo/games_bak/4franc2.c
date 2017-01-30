#include "/players/hippo/games/puzzle_3.c"
#include "/players/hippo/rvd.h"
id(str) {return str=="nextpuzzle";}
get() {return 1;}
drop(str) {return 0;}
short() {return("nextpuzzle");}
long()
{ if(CTP=="Francesco" || CTP=="Hippo")
  { write("Here is next weeks puzzle:\n\n");
    description();
    return 1;
  }
  write("This was not meant to be read by you!\n");
  return 1;
}
