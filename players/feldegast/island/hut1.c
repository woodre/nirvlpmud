#include "/players/feldegast/defines.h"
inherit ROOM;
reset(arg) {
  object chief;
  if(!present("chief")) {
    chief=clone_object("/players/feldegast/island/npc/chief");
    move_object(chief,this_object());
  }
  if (arg) return;
  set_light(1);
  short_desc="A tidy hut";
  long_desc=
"     The chief man's hut also doubles as an office and\n"+
"meeting hall for the rest of the village.  A long table\n"+
"surrounded by chairs runs the length of the hut.  A cot\n"+
"lies in the back of the hut for the chief man to sleep in.\n";
  items=({
    "table","An old table approximately 3 meters long made out\n"+
            "of bamboo",
    "chairs","Wicker chairs with cushions on each seat",
    "cot","A spartan pallet"
  });
  dest_dir=({
    "/players/feldegast/island/village1","south"
  });
}

