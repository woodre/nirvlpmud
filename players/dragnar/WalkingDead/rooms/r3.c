inherit "players/dragnar/WalkingDead/rooms/WalkingDeadRM";

#include <ansi.h>

status search_flag;

reset(arg) {
	
  search_flag = 0;
  
  if(arg) return;
  
  short_desc = "King County Route "+HIB+"19"+NORM;
  long_desc=
"The road here is a disaster of wrecked cars, charred pavement, and\n\
corpses.  There are six cars here in various states of disarray.\n\
Almost all of the cars have corpses in them, and there is a\n\
disturbing amount of blood stains on the cars and the pavement of the\n\
road. One of the cars caught fire and the grass on the shoulder is\n\
burned and blackened. The forest continues to border the road on the\n\
east and west, undaunted by the tragic events that occurred here.\n",
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
properly maintained recently.  There are a group of cars on the west\n\
side of the road, and the pavement around them is marked with "+RED+"blood"+NORM,
    "forest",
"The trees are fairly thick even close to the clearing, although it is\n\
passable. They block out much of the sunlight and make it quite gloomy.\n\
It is quiet in the forest, perhaps a bit too quiet",
    "trees",
"The trees dominate the forest.  Most are leafy trees such as ash and\n\
cherry, but there are some evergreen pines as well. Many of the pines\n\
grow in "+GRN+"dark green"+NORM+" patches",
    "stains",
RED+"Dark red, these stains"+NORM+" have been here in the sun for some time",
    "clearing",
"The clearing is just overgrown grass that separates the road from\n\
the forest",
    "pot holes","Only a handful of small 1 inch holes in the pavement",
    "pines",GRN+"Darker "+NORM+"varieties of pine grow in that part of the forest",
    "glass","The glass shards look sharp, but they are too small to be a danger",
    "gore","Dark red "+RED+"stains"+NORM+" mark the pavement",
    "arrow","A camouflage aluminium shaft with green "+GRN+"fletching"+NORM,
    "windows","They are smashed in like something was breaking into the cars",
    "doors","With the car doors hanging open it makes this area seem very eerie",
    "pavement",
"Covered in glass and "+BRED+"gore"+NORM+" from the corpses here, but the road\n\
continues to the north and south, perhaps to less gruesome and better\n\
smelling environments",
    "grass",
"The grass is "+HIBLK+"black and charred"+NORM+".  As bad as the burned grass looks,\n\
it is one of the best looking features of this spot",
    "corpses",
"Four of the cars have a corpse in them, and three more are lying\n\
in various positions on the ground.  They are all grotesque,\n\
mutilated and seemingly with bites out of them.  The smell is\n\
overpowering, so getting too close is out of the question. One\n\
thing you can see is that a corpse laying in the road has an arrow\n\
shaft sticking out of her head.  That certainly did not happen in a\n\
standard auto accident..",
    "cars",
"Six different cars, mostly sedans of various makes and colors are\n\
grouped on the west side of the road.  At first it seems like this\n\
must have been an accident, but on closer inspection the cars don't\n\
have a lot of damage that would correlate to an accident. Windows are\n\
broken, doors are open, but there is little damage to the outsides of\n\
the cars.  It almost looks like the cars pulled off the road, at\n\
which point something terrible transpired. Perhaps you should brave\n\
the stench and search them to see if you can find anything useful",
  });
  dest_dir=({
    "/players/dragnar/WalkingDead/rooms/r4","north",
    "/players/dragnar/WalkingDead/rooms/r2","south",
    "/players/dragnar/WalkingDead/rooms/f16","east",
    "/players/dragnar/WalkingDead/rooms/f15","west",
  });
  
  reanimate_corpse();
}

init() {
	::init();
}

Search( string str ) {
  object treasure;
  if( !str ) {
    write("Your general search leads you to notice the cars.\n");
    return 1;
  }
  if( str == "car" || str == "cars" ) {
    if( !search_flag++ ) {
      treasure = clone_object("/players/dragnar/WalkingDead/obj/walker_obj");
      treasure->set_value_tier( 1 );
      treasure->set_object_stats();
      move_object( treasure, this_object() );
      write("You find something in one of the vehicles!\n");
      say( this_player()->query_name()+" finds something in one of the vehicles!\n");
    }
    else {
      write("You search the cars but find nothing but the smell of the dead.\n");
      say( this_player()->query_name()+" searches the cars and finds nothing but the smell of the dead.\n");
    }
    return 1;
  }
  return 0;
}
