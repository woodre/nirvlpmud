/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2005 Forbin
//                  All Rights Reserved.
//  Realm:        Qual'tor Miniquest
//  Function:     room
//  Create Date:  2005.02.18
//  Last Edit:    2005.02.18 -Forbin
*/

#include "/players/forbin/realms/cave/cavedefine.h"
inherit "/players/forbin/closed/std/room.c";

reset(arg) {
  if(arg) return;
  
  if(!present("atticus_miniquest_timer")) 
    add_object("players/forbin/realms/cave/RMS/timerob.c");   
  
  short_desc = "???";
  long_desc = 
    "The cave is dark and musky smelling; an acrid liquid trickles down\n"+
    "the rough walls.  A small, rounded hole leads outside, while a\n"+
    "slight bit of outer light floods in.  Several ruts and cracks\n"+
    "line the walls, floor, and ceiling, with the larger ones further\n"+
    "into the cave.\n";
  set_light(0);
  add_item("liquid",
    "A dark liquid seems to be weeping through the cave wall");
  add_item("hole",
    "A large hole leads back outside.  Light from outside streams in");
  add_item(({"wall","walls",}),
    "The walls are roughly hewn, and their vertical rise is broken in\n"+
    "places by ruts and cracks");
  add_item(({"rut","ruts",}),
    "Scores of ruts criss-cross along the cave's surfaces");
  add_item(({"crack","cracks"}),
    "There are several cracks in the cave floor and walls, but an oddly\n"+
    "large crack catches your eye.  You swear you see a faint, orange\n"+
    "glow coming from beyond it");
  add_item("floor",
    "The floor is trampled dirt and crumbled rocks");
  add_item(({"dirt","rock","rocks"}),
    "The floor is strewn with a black dirt and crumbling black rocks");
  add_item("ceiling",
    "The ceiling is rough and slick with moisture");
  add_item("light",
    "A faint light creeps from the opening of the cave");
  add_smell("main", "You noticed a strange odor.\n");
  add_smell("liquid", "You realize the strange odor is coming from the liquid.\n");
  add_taste("liquid", "That probably wouldn't be such a good idea.\n");    
  add_exit("/players/forbin/realms/flame_forest/RMS/ff05_01","out");   
}


short() { return "???"; }    

init() {
  ::init();
  if(!present("atticus_miniquest_timer")) 
    add_object("players/forbin/realms/cave/RMS/timerob.c");     
  add_action("cmd_search", "search");
}

int cmd_search(string arg) 
{
  if(arg == "crack" || arg == "cracks") 
  {
    tell_object(this_player(), 
      "You carefully search a crack far in the back of the cave.  You\n"+
      "find that you could 'squeeze' through the 'crack'.\n");
    tell_room(this_player(),  
      (string)this_player()->query_name()+
      " carefully searches a crack in the cave wall.\n");
    return 1;
  }
}
