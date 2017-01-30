#include "/players/coldwind/define.h"

inherit "room/room";
reset(arg) {	
  if(arg) return;
set_light(1);

short_desc = ""+HIY+"Dahna desert"+NORM+"";
long_desc =
"    You are standing about a thousand feet above the sandy ground.\n"+  
"Some holes and many curves shape the face of the mountain.  The air \n"+
"is somewhat thick here making you do some effort to breathe.  You \n"+
"feel little beside the rocky mountain that towers high reaching the\n"+
"clouds, while downward the sandy desert spreads reaching infinity.\n"+
"Palm trees are growing heavily toward the south.\n";

items = ({
  "oasis",
  "You can see a small pool and many palm trees standing to\n"+
  "the south or the southeast",
  "palm trees",
  "Tall trees carrying red palms and growing to the south\n"+ 
  "or the southeast in what looks like an oasis",
/* Added description for 'trees' to match 'palm trees' 11-24-07 -Rumplemintz */
  "trees",
  "Tall trees carrying red palms and growing to the south\n"+
  "or the southeast in what looks like an oasis",
  "pool",
  "You can see the reflection of the sun on the surface of\n"+
  "the water, while some palm trees grows tall around it",
  "desert",
  "The sandy dunes spread around covering the face of the desert",
  "sand",
  "The golden sand spreads covering the face of the ground",
  "dune",
  "Small dunes of yellow sand scattered around covering the\n"+
  "face of the desert",
  "cave",
  "A large cave seems inviting to the east",
  "ground",
  "The golden sand spreads covering the face of the ground",  
  "mountain",
  "This is a rocky mountain with random caves and curves decorate its body",
  "caves",
  "Large holes were formed by nature in the rocky mountain. They\n"+
  "would make perfect shelters. You notice a nearby cave to the "+BOLD+"east"+NORM+"",
  "holes",
  "Large caves were formed by nature in the rocky mountain.",
  "curves",
  "It might be possible to "+BOLD+"descend or climb"+NORM+" up using the natural curves in the rocky mountain",
  
});


}

init(){
  ::init();
  add_action("climb_up", "climb");
  add_action("east_cave", "east");
  add_action("east_cave", "e");
  add_action("descend_mountain", "descend");
      add_action("find_it", "search");
  }
  find_it(){
  write("You notice many caves and curves in the mountain.\n");
  return 1;
  }
  
  climb_up(){
move_object(this_player(), "/players/coldwind/desert/rooms/ma5.c");
say(""+tpn+" arrives.\n");
command("look", this_player());
return 1;
}	

  east_cave(){
move_object(this_player(), "/players/coldwind/desert/rooms/ma4.c");
say(""+tpn+" arrives.\n");
command("look", this_player());
return 1;
}

descend_mountain(){
move_object(this_player(), "/players/coldwind/desert/rooms/ma1.c");
say(""+tpn+" arrives.\n");
command("look", this_player());
return 1;
}

	
