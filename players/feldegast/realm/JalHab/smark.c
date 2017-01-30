#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(!present("vendor"))
    move_object(clone_object(MON_PATH+"vendor.c"),this_object());
  if(arg) return;
  set_light(1);
  short_desc="Sudakan: Market Square";
  long_desc=
"  The market square is by far the largest of the five plazas of\n"+
"Sudakan.  This is where the common folk buy and sell their meager\n"+
"goods.  In the center of the square is a large fountain, decorated\n"+
"with gold leaf.  In its center, a dolphin spits water up in the air\n"+
"in a continuous stream.\n"+
"  Streets: Ruby  Temple  Scroll  Gold\n"+
"  Locations: Shop\n";
  items=({
    "fountain","A large fountain with a marble dolphin spitting water\n"+
               "into its basin",
    "dolphin","The dolphin looks unusually happy to be squirting water\n"+
              "up into the air",
  });
  dest_dir=({
    PATH+"sroy.c","ruby",
    PATH+"stab.c","temple",
    PATH+"smerch.c","scroll",
    PATH+"sgate.c","gold",
    PATH+"sshop2.c","shop",
    PATH+"smhall.c","mercenary",
    PATH+"smhall.c","hall",    
  });
}

string short() {
  return short_desc;
}

void long(string str) {
  if(!str) write(long_desc);
  else ::long(str);
}

void init() {
  ::init();
  add_action("cmd_answer","answer");
}

int cmd_answer(string str) {
  write(BLU+"The dolphin sprays you with water.\n"+NORM);
  return 1;
}

query_coords() { return ({ 6,7 }); }
