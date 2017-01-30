inherit "players/dragnar/WalkingDead/rooms/WalkingDeadRM";
#include <ansi.h>

reset(arg) {

  set_no_clean(1);
  if (!present("sack")) 
    move_object(clone_object("players/dragnar/WalkingDead/obj/rucksack"), this_object());
    
  if (!present("vest")) 
    move_object(clone_object("players/dragnar/WalkingDead/armor/swat_vest"), this_object());
    
  if (!present("helmet")) 
    move_object(clone_object("players/dragnar/WalkingDead/armor/swat_helmet"), this_object());
    
  if (!present("shield"))
    move_object(clone_object("players/dragnar/WalkingDead/armor/riot_shield"), this_object());

	if(arg) return;
  
  short_desc =  BGRN+BLK+"Black Creek"+NORM+" Survival Shop Storage Room";
  set_light(1);

  dest_dir=({
    "players/dragnar/WalkingDead/rooms/shop","out",
  });
  long_desc=
"This is the storage room for the Black Creek Survival Shop.";
  
}

init() {
	::init();
}

query_dont_clean_obs_here() { return 1; }

