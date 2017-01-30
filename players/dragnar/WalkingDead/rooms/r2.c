inherit "players/dragnar/WalkingDead/rooms/WalkingDeadRM";

#include <ansi.h>
#include "../defs.h"

status open_flag;

reset(arg) {
	
  open_flag = 0;
  
  if(arg) return;
  
  short_desc = "King County Route "+HIB+"19"+NORM;
  set_light(1);
  items=({
  "shoulder",
"The hard shoulder is only a foot wide, but the grassy soft shoulder\n\
stretches 20 feet wide here. The trees from the forest start to grow\n\
immediately where the soft shoulder ends",
    "road",
"A two lane country road with a "+HIY+"double line"+NORM+" running down the middle and\n\
"+GRY+"white lines"+NORM+" that mark the edges.  The paint is a bit faded, and the road\n\
has some small pot holes starting.  It seems like the road hasn't been\n\
properly maintained recently.  There is a car on the east side of the\n\
shoulder, apparently abandoned",
    "forest",
"The trees are fairly thick even close to the clearing, although it is\n\
passable. They block out much of the sunlight and make it quite gloomy.\n\
It is quiet in the forest, perhaps a bit too quiet",
    "trees",
"The trees dominate the forest.  Most are leafy trees such as poplar and\n\
dogwood, but there are some evergreen pines as well. Many of the pines\n\
grow in "+GRN+"dark green"+NORM+" patches",
    "grass",
"The grass grows wildly between the hard shoulder of the road and\n\
the tree line.  It is over a foot high and the "+GRN+"green"+NORM+" stems sway\n\
lazily in the breeze.  Some of the grass has seed heads that are so\n\
heavy they bend the grass down toward the ground",
    "clearing",
"The clearing is just overgrown grass that separates the road from\n\
the forest",
    "pot holes","Only a handful of small 1 inch holes in the pavement",
    "pines",GRN+"Darker "+NORM+"varieties of pine grow in that part of the forest",
    "trunk","It looks like it could easily be popped open",
    "door","With the car door hanging open it makes this area seem very eerie",
    "shards","The glass shards look sharp, but they are too small to be a danger",
    "car",
"This is a "+BLU+"Ford"+NORM+" Focus with the driver side door left wide open.\n\
There is an obvious "+RED+"blood spatter stain"+NORM+" on the wind-shield, and the\n\
passenger door window is shattered.  The glass shards reflect the\n\
"+HIY+"sunlight"+NORM+" in the grass. The trunk has taken some damage, and is a\n\
bit crumpled. Someone died here, but no one is visible now"
  });
  dest_dir=({
    "/players/dragnar/WalkingDead/rooms/r3","north",
    "/players/dragnar/WalkingDead/rooms/r1","south",
    "/players/dragnar/WalkingDead/rooms/f10","east",
    "/players/dragnar/WalkingDead/rooms/f9","west",
  });
  long_desc=
"A road runs directly north and south here. The soft shoulder of\n\
the road was created wide here to create a clearing between the\n\
road and the trees of the forest. The "+GRN+"grass"+NORM+" however has not been cut\n\
and it grows wild and unevenly in the clearing. In the clearing on\n\
the east side of the road there is what seems to be an abandoned car.\n\
Further north the road continues, and the forest looms into the sky\n\
on the east and west sides just past the clearing of the shoulder.\n",
  
  reanimate_corpse();
  set_call_out( "trunk_effect", 5, 10 );
}

init() {
	::init();
  add_action("Pop","pop");
}

Pop( string str ) {
  object walker;
  if( !str )
    return 0;
  if( str == "open trunk" || str == "trunk" ) {
    if( !open_flag++ ) {
      walker = clone_object("/players/dragnar/WalkingDead/mons/walker");
      walker->set_walker_level( WALKER_START );
      move_object( walker, this_object() );
      
      write("You pop open the trunk of the car.\n");
      say( this_player()->query_name()+" pops open the trunk of the car.\n");
      tell_room(this_object(), "A Walking Dead growls and stumbles out of the trunk!\n");
      walker->attacked_by( this_player() );
      remove_call_out("trunk_effect");
    }
    else {
      write("The trunk is already open.\n");
    }
    return 1;
  }
  return 0;
}

trunk_effect() {
  if( open_flag ) 
    return;
  
  switch( random(5) ) {
    case 0:
      tell_room(this_object(), "From the corner of your eye you see the car rock slightly.\n");
      break;
    case 1:
      tell_room(this_object(), "You hear a muffled thump from the back of the car.\n");
      break;
    case 2:
      tell_room(this_object(), "You hear what sounds like scratching from the back of the car.\n");
      break;
    case 3:
      tell_room(this_object(), "You hear a grunt from the direction of the car.\n");
      break;
    default:
      tell_room(this_object(), "You hear a muffled moan from the trunk of the car.\n");
      break;
  }
  
  call_out("trunk_effect", call_out_int + random( call_out_int_rand ) );
}
