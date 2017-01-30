inherit "players/dragnar/WalkingDead/rooms/WalkingDeadRM";

#include <ansi.h>
#include "../defs.h"

reset(arg) {

  if( !present("lucas") )
    move_object(clone_object("/players/dragnar/WalkingDead/mons/lucas"), this_object());

	if(arg) return;
    
  short_desc = BGRN+BLK+"Black Creek"+NORM+" Survival Shop";
  set_light(1);
  items=({
    "door","Solid Oak with a brass lock. It would take a wizard to unlock it",
    "lock","The "+YEL+"brass"+NORM+" lock looks normal, but somehow unable to be unlocked",
    "sticks","An STX Super Power Lacrosse stick",
    "gloves","A rack of Mizuno MVP Primes and Classic Pro X's",
    "junk","Sporting equipment like baseball gloves and lacrosse sticks",
    "shelves","Full of what is now useless junk in the new world, except for some\n\
empty spots where the weapons, ammo, and other survival gear used to be",
  });
  dest_dir=({
    "players/dragnar/WalkingDead/rooms/r5","west",
    "players/dragnar/WalkingDead/rooms/store","enter",
  });
  long_desc=
"This is what used to be a local sporting goods store. It seems it was\n\
a small mom and pop type store that you would find in a small village\n\
like Black Creek. The shelves still hold all of the junk that is now\n\
useless like baseball gloves and lacrosse sticks. In the back of the\n\
store there is a solid looking door that has a large lock on it. Perhaps\n\
the more useful items are locked in the back room.\n";
  
  reanimate_corpse();
}

init() {
	::init();
  add_action("Enter","enter");
}

exit() {
  if(this_player() && this_player()->queryShopShadow())
    this_player()->deShopShadow();
}

Enter() {
  if ( this_player()->query_level() < 30) {
    write("The door is locked, and you have no idea how to unlock it.\n");
    return 1;
  }
  write("You unlock the door and enter the storeroom.\n");
  return 0;
}
