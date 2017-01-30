#include "/players/feldegast/defines.h"
inherit ROOM;
reset(arg) {
  object lady;
  if(!present("birdtalker")) {
    lady=clone_object("/players/feldegast/island/npc/birdtalker");
    move_object(lady,this_object());
  }
  if (arg) return;
  set_light(1);
  short_desc="A cozy hut";
  long_desc=
"     This is a cozy yet messy hut strewn with pillows and\n"+
"couches.  Some light comes in through a window.  You smell\n"+
"incense and other strange odors.  For some reason, it reminds\n"+
"you of a nest.\n";
  items=({
    "pillows","Comfy feather pillows",
    "couches","Comfortable couches with silk covers",
    "window","You can see the jungle a few meters away"
  });
  dest_dir=({
    "/players/feldegast/island/hut3","south"
  });
}

