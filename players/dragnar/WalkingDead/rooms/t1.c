inherit "players/dragnar/WalkingDead/rooms/WalkingDeadRM";
#include <ansi.h>

reset(arg) {
  
  if( !present("anthony") )
    move_object(clone_object("/players/dragnar/WalkingDead/mons/aj"), this_object());
  if( !present("guard") ) 
    move_object(clone_object("/players/dragnar/WalkingDead/mons/guard"), this_object());
    
  if(arg) return;
  
  short_desc = BGRN+BLK+"Black Creek"+NORM;
  set_light(1);

  items=({
    "lot", "The "+HIY+"lines"+NORM+" are faded and there are many signs of wear. This parking\n\
lot was probably not in the best shape before the world ended. It was\n\
most likely built for trucks to use the loading dock on the warehouse",
    "parking lot", "&lot&",
    "warehouse", "The largest building in the village, it is a 3 story building that has\n\
seen better days. The south side of the building facing you is mostly\n\
loading docks, but they have been boarded up and there is no visible\n\
entrance into the building",
    "building", "&warehouse&",
    "dock", "A loading platform so trucks could back up to the warehouse and unload",
    "platform", "A concrete platform around 3 feet off the ground",
    "lines","Mostly worn away, the "+HIY+"lines"+NORM+" are barely visible now",
    "village","This village seems to be pretty secure compared to the\n\
surrounding forest area",
    "fence", "Eight feet tall with a roll of "+GRY+"barbed wire"+NORM+" at the top, it prevents\n\
Walkers from wandering into the village",
    "barbed wire","Razor wire with 3 inch barbs that change directions",
    "road","From this point it looks a standard small village road",
    "street","From this point it looks a standard small village road",
  });
  dest_dir=({
    "/players/dragnar/WalkingDead/rooms/r5","east",
  });
  long_desc=
"A parking lot stretches out in all directions from here. There is\n\
a 3 story building to the north that used to be some kind of a\n\
warehouse. To the west the fence that borders the village turns north\n\
marking the edge of the small village. To the south the fence runs\n\
just past the end of the parking lot. On the east side of the lot you\n\
can see the main street and a smaller building on the far side of that.\n";
  
  reanimate_corpse();
}

init() {
	::init();
}
