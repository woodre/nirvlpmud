inherit "players/dragnar/WalkingDead/rooms/WalkingDeadRM";

#include <ansi.h>
#include "../defs.h"

status search_flag;

reset(arg) {

	search_flag = 0;
  
  if(arg) return;
    
  short_desc = BGRN+BLK+"Black Creek Pharmacy"+NORM;
  set_light(1);
  items=({
    "glass","Broken and sharp and now useless",
    "shelves","They are made of metal and tipped onto their sides",
    "items", "Toys, music CDs, greeting cards which are worthless now",
    "junk", "Items that were once valued, which are now garbage",
    "ground","Made from a pattered tile of tan and dark brown",
    "entrance","A double glass entrance which is mostly destroyed",
    "street","The street outside can be viewed through the empty entrance",
  });
  dest_dir=({
    "/players/dragnar/WalkingDead/rooms/r7","west",
  });
  long_desc=
"The glass in the entrance to the pharmacy has been smashed and glass\n\
is scattered all over the ground. The shelves have been tipped over\n\
and many items litter the area. Anything useful has already been\n\
looted and left behind is the junk that is no longer useful. The only\n\
passage is west through the shattered entrance back toward the street.\n";
  
  reanimate_corpse();
}

init() {
	::init();
  add_action("Search","search");
}


Search(string str ) {
  object treasure;
  if( !str )
    return 0;
  
  if( str == "shelves" || str == "shelf" ) {
    if( !search_flag++ ) {
      treasure = clone_object("/players/dragnar/WalkingDead/heals/mons/vicodin");
      treasure->set_found(1);
      move_object( treasure, this_object() );
      write("You find something hiding in the shelves!\n");
      say( this_player()->query_name()+" finds something in the shelves!\n");
    }
    else {
      write("You search the shelves but find nothing after all.\n");
      say( this_player()->query_name()+" searches the shelves and finds nothing.\n");
    }
  }
  return 1;
}




