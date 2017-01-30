inherit "players/dragnar/WalkingDead/rooms/WalkingDeadRM";

#include <ansi.h>
#include "../defs.h"


reset(arg) {

  if( !present("walker") )
    move_object( clone_object("/players/dragnar/WalkingDead/mons/walker_pet"), this_object() );
 
  if(arg) return;
    
  short_desc = BGRN+BLK+"Black Creek"+NORM;
  set_light(1);

  dest_dir=({
    "/players/dragnar/WalkingDead/rooms/t2","out",
  });
  long_desc=
"It is dark.\n";
  
  reanimate_corpse();
}

