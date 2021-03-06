#include "room.h"

init() {
     ::init();
     add_action("look", "look");
     add_action("look", "l");
     add_action("look", "examine");
}

look(str) {
  if (!str) return 0;
  if (str == "at statue"||str=="at buried head" ||str=="at crown" ||
      str == "at buried statue" || str == "at head" ||
      str == "at large statue" || str == "at large head" ) {
    write("The curvature of the shorline cliffs block sight of the\n"+
      "mysterous statue.\n");
    return 1;
  }
  if (str == "at drop" || str == "at sheer drop" || str=="at cliff") {
     write("A straight drop about eighty feet to the rocks and water\n"+
     "below.\n");
     return 1;
  }
  if (str == "at cave" || str == "at opening" || str == "at small cave" ||
      str == "at small cave like opening" || str == "at small opening") {
    write("It is too dark to see within the cave.\n");
    return 1;
    }
  if (str == "at inn" || str == "at east road inn" || 
      str=="at eastroad inn") {
    write("The Eastroad Inn is a large wooden structure much like \n"+
     "hotels in vacations spots of the 19th century.\n");
    return 1;
  }
  return 0;
}

THREE_EXIT("room/eastroad4","south",
                   "players/eurale/VAMPIRES/RMS/vgent.c","north",
"room/inn","west",
"East road",
"East road runs south from here, as this is the north end of the road.\n"+
"A sheer faced cliff rises straight up to the north with a small cave\n"+
"like opening. The drop to the east still present. Along the west side\n"+
"of the road lies the Eastroad Inn. It appears to be built here for\n"+
"looking to stay in a scenic location near the shore.\n",1)
