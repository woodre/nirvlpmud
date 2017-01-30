#include "def.h"
inherit MYROOM;
int need;
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="A bathroom";
  long_desc=
"     This is a seedy looking bathroom with a tile floor.  There is a\n\
bathtub, a sink, and a toilet.  There's a chair by the door that leads\n\
out.\n";
  items=({
    "bathtub","A dirty old bathtub filled with pinkish water and a\n"+
              "somewhat bewildered goldfish",
    "tub","A dirty old tub filled with pinkish water and a\n"+
              "somewhat bewildered goldfish",
    "sink","The sink is dirty.  You notice a spot of blood on it",
    "toilet","The toilet is broken.  It won't flush",
    "chair","A simple wooden chair, probably for putting clothes on",
    "door","A wooden door"
  });
  dest_dir=({
    PATH+"murdroom","west",
  });
  need=1;
}   
init() {
  ::init();
  add_action("search","search");
}
search(str) {
  object needle;
  if(!need) { write("You find nothing.\n");return 1;}
  write("You find a needle by the bathtub.\n");
  needle=clone_object(PATH+"Wep/needle");
  move_object(needle,this_player());
  this_player()->add_weight(1);
  need=0;
  return 1;
}
