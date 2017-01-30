inherit "/players/earwax/housing/land.c";
inherit "players/dragnar/WalkingDead/rooms/WalkingDeadRM";

#include <ansi.h>
#include "../defs.h"

reset(arg) {

	if(arg) return;
    
  short_desc = BGRN+BLK+"Black Creek"+NORM;
  set_light(1);
  items=({
    "spear", "A shaved wooden stick with the end carved into a sharp point",
    "gore", "Covered in bits of "+HIBLK+RED+"blood and rotted flesh"+NORM,
    "point","A simple point made from sharpening the end of the stick",
    "sticks", "Wooden shafts made from hard maple trees",
    "flesh", "Impossible to tell what left these chunks behind",
    "blood","Dark red "+RED+"blood"+NORM+" that is almost black",
  });
  dest_dir=({
    "/players/dragnar/WalkingDead/rooms/r8","up",
  });
  long_desc=
"Somebody dug a pit under the Welcome mat to trap any walkers that\n\
got through the barriers and you managed to land in it. There is a\n\
spear sticking up from the center of the hole that has some slimy\n\
gore covering the end. The only thing you can do from here would be\n\
to climb out.\n";
  
  set_realm_name("Walking Dead");
  set_cost(150000);
  set_lot_size(100);
  setup_land();
}

init() {
	::init();
  hurt_me();
}

hurt_me() {
  int dam;
  
  dam = random(75);
  if( this_player() ) {
    write(HIBLK+"You step on the Welcome mat and fall into a deep hole!"+NORM+"\n");
    if( random(this_player()->query_stat("luck")) > 15 )
      write("Luckily, you narrowly avoid being gutted by a spear sticking up in the hole.\n");
    else {
      write("Your guts are "+RED+"IMPALED"+NORM+" by a spear jutting up from the hole!\n");
      dam += random(120);
    }
    this_player()->hit_player(dam, "physical");
  }
}
