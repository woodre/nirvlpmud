#include "defs.h"

inherit MNDROOM;

void reset(int arg)
{
  if(!arg) {
    short_desc=RED+"The Myrmidar Mound"+NORM;
    long_desc=
"  The Myrmidar mound is a labyrinthine maze of twisting tunnels that seem\n\
to connect at random.  The tunnels are cool and humid, with a slightly sweet\n\
odor to them.  This tunnel widens into a cave with a sand floor.  The sand is\n\
gritty and blackish, as though it had been repeatedly stained with blood.  The\n\
tunnels continues to the south and east.\n";
    items=({
      "tunnels", "The passages are perhaps six feet high, circular, and well-travelled",  
      "cave", "The cave is about four meters wide and three long, and is\n"+
              "approximately egg shaped",
      "sand", "The sand is gritty and blackish, as though it had been repeatedly\n"+
              "stained with blood",
    });
    dest_dir=({
      PATH+"mound1.c","east",
      PATH+"mound3.c","south",
    });
  }
  if(!present("corpse"))
  {
    object corpse;
    corpse=clone_object("/obj/corpse.c");
    corpse->set_name("animal");
    move_object(corpse,this_object());
  }
  if(!present("myrmidar") && random(2))
    move_object(clone_object(MON_PATH+"myrm-worker.c"),this_object());

}
