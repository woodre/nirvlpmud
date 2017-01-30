#include "/players/cosmo/dc/defs.h"
inherit "players/cosmo/dc/dc_room";

reset(arg) {
  if(arg) return;
  set_room_type("street");
  set_search(DCOBJ+"camera.c");
  set_sound("A distant bird sings happily: "+YEL+"Tweet, tweet. Chirp, chirp."+NORM);
  set_smell(GRN+"You smell the plush green grass. Spring is in the air."+NORM);
  short_desc=GRN+"14th St"+NORM;
  long_desc=
"   You stand between Independence and Constitution Avenues on\n"+
"The Mall, the large field of grass between the "+
BLU+"Washington Monument"+NORM+"\nand the "+BLU+
"Capitol Building"+NORM+".  The Monument is to the west and the\n"+
"Capitol is far off in the eastern sky.  Your surroundings\n"+
"are so scenic and beautiful that you wish you had a camera\n"+
"to capture the moment.  "+GRN+"14th Street"+NORM+" continues north and\n"+
"south from here.\n\n";
 
  items= ({
"grass", "It appears to be Kentucky bluegrass",
"sky", "It's mostly blue with a few puffy white clouds",
"monument", "You stare in awe at its size and structure",
"capitol", "A sense of patriotism overwhelms you",
  });

  dest_dir= ({
    DCSTR+"s003a", "north",
    DCSTR+"s002a", "south",
    DCBLDG+"w/bw01", "west",
  });
}

init() {
  ::init();
}
