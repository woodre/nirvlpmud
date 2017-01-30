#include "../def.h"
inherit MYROOM;
reset(arg) {
  if (arg) return;
  short_desc="An ascending tunnel";
  long_desc=
"    This tunnel slopes steeply upward and to the north.  At\n"+
"the end of the tunnel you can just barely make out flickering\n"+
"torchlight.  The floors and walls of this tunnel are smooth\n"+
"rounded, and comfortably wide, possibly an effect of an under-\n"+
"ground stream at one time.\n";
  items=({
    "torchlight","It is perhaps fifty feet up the tunnel from where you are",
    "floors","The floors and walls of this relatively straight tunnel are\n"+
             "smooth and rounded",
    "walls","The floors and walls of this relatively straight tunnel are\n"+
            "smooth and rounded"
  });
  dest_dir=({
    PATH+"Quad/cave12","north",
    PATH+"Quad/cave3","south",

  });
}   
init() {
  ::init();
  add_action("search","search");
}
search(str) {
  write("You find nothing.\n");
  return 1;
}
