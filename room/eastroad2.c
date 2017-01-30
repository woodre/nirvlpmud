#include "room.h"

init() {
     ::init();
     add_action("look", "look");
     add_action("look", "l");
     add_action("look", "examine");
}

look(str) {
  if (!str) return 0;
  if (str == "at temple"||str=="at walls"||str=="at granite walls"
     ||str=="at wall"||str=="at granite wall"){
    write("The thirty foot high walls block your view of the temple\n"+
      "and anything going on inside. They are of a quality construction\n"+
      "with anti-climbing spikes located near the top.\n");
    return 1;
  }
  if (str == "at drop" || str == "at sheer drop" || str=="at cliff") {
     write("A straight drop about eighty feet to the rocks and water\n"+
     "below.\n");
     return 1;
  }
  return 0;
}

TWO_EXIT("room/eastroad3","north",
         "room/eastroad1","south",
"East road",
"The East Road runs north-south parallel to the village shore. The\n"+
"wall of the temple turns west and to either side of the road green\n"+
"grass grows. About 10 feet off the road to the east there is a sheer\n"+
"drop to the shoreline below. The road continues to the north and south\n"+
"The soil is rocky here, there are only a couple of trees.\n",1)
