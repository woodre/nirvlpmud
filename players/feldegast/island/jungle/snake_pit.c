#include "/players/feldegast/defines.h"

inherit ROOM;

reset(arg) {
  int x;
  object python;
  if(!present("python")) {
    while(x<4) {
      x++;
      python=clone_object("/players/feldegast/island/npc/python");
      move_object(python,this_object());
    }
  }
  if (arg) return;
  set_light(1);
  short_desc=BOLD+"A jungle ruin"+NORM;
  long_desc=
"     You find yourself in the middle of an ancient ruin deep\n"+
"inside the jungle.  Jungle foliage covers most of it, but\n"+
"ancient stone walls and pillars peek up in some places.\n";
  items=({
    "ruin","Intricate designs are carved into the stone",
    "foliage","Creeping vines, furry moss, and slimy snakes.\n"+
              "Hold it..",
    "designs","Most of the designs appear to center around a serpentine\n"+
              "motif.  One faded mural depicts a python fighting some sort of\n"+
              "fire creature",
    "walls","Crumbling stone walls.  You can't really tell what sort\n"+
            "buildings these were",
    "pillars","Tall pillars which continue the serpentine motif of the\n"+
              "rest of the ruins with stone adders circling around them"
  });
  dest_dir=({
    "/players/feldegast/island/jungle/jungle11","south"
  });
}
   
