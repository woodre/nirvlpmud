#include "/players/softly/closed/ansi.h"
inherit "/room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Beside a Mound";
long_desc ="  The trail is wide but very wet underfoot.  The\n"+
           "forest is not very dense and the undergrowth is absent.\n"+
           "A light mist in the air dampens the skin and makes\n"+
           "visibility difficult.  A slight mound can be seen to\n"+
           "the southeast.\n";

items = ({
  "trail", "A damp forest trail is broad and easy to navigate",
  "forest","The forest has a few pines and many oak and maple\n"+
           "trees.  It is rather open and bright",
  "undergrowth","There is no undergrowth",
  "mist","The air is white with mist making it hard to see",
  "mound","On close inspection there appears to be an opening\n"+
          "to the southeast.  The entrance is blocked",
  });

dest_dir = ({
  "/players/softly/point/rooms/for9.c","north",
  "/players/softly/winter/rooms/for2.c","west",
  });
}




