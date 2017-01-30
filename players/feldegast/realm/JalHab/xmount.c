#include "defs.h"

inherit MAPROOM;

void reset(int arg)
{
  if(arg)return;
  set_light(1);
  short_desc=YEL+"Jal-Hab Desert"+NORM;
  long_desc=
"  The great rolling dunes of the Jal-Hab desert mellow and become\n\
loose rocky soil.  The land begins to tilt upwards and gradually\n\
becomes more fertile as the desert finally ends in a range of\n\
mountains said to be the ancestral home of dwarves.\n";
  items=({
    "dunes","Hills and valleys of sand, shifting and blowing about\n"+
            "like an inconstantant sea",
    "soil","From east to west, the soil changes from sand to rock",
    "mountains","The mountains have known many names in many different\n"+
                "tongues.  To humans, they are often called the Demon's Horns",
  });
  dest_dir=({
    "blank","north",
    "blank","west",
    "blank","east",
    "blank","south",
  });
}

void init() {
  ::init();
  add_action("cmd_west","west");
}

int cmd_west(string str) {
  write("You can't find a way through the mountains here.\n");
  return 1;
}

