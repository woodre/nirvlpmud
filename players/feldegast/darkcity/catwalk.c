#include "def.h"

inherit MYROOM;

reset(arg) {
  if(!present("stranger"))
    move_object(clone_object(PATH+"Npc/mrquick"),this_object());
  if (arg) return;
  set_light(1);
  short_desc="A Catwalk";
  long_desc=
"     This is an unsteady wooden catwalk beneath a huge mechanical\n\
advertisement for Shell Beach.  A sunny looking girl waves her hand\n\
back and forth as she sits on a warm beach.\n";
  items=({
    "catwalk","The rotten old boards are near to crumbling",
    "advertisement","In big letters, the sign says: Come to Shell Beach",
    "girl","The girl smiles and waves as she sits on the beach",
    "beach","The sign makes it look like a tropical paradise"
  });
  dest_dir=({
    PATH+"alley1","down"
  });
}   
