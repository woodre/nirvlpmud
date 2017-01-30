#include "/players/grimm/header"
inherit "room/room";
int outdoorness;
realm() { return "NT"; }
reset(arg) {
  if(arg) return ;

  short_desc="Castle Entrance";
  long_desc="You have found the entrace to the Castle of Malachi.  As you\n"+
     "stand looking at the castle you can feel the imense darkness and evil\n"+
     "that is generated inside.  To the west you can see a path leading into\n"+
     "the dark forest and to the east is the castle bridge.\n",
  items=({"bridge","This is a very old bridge made of wood from the forest",
          "castle","You see a extremely large and dark castle"});
  dest_dir=({DIR5(castle2),"east",
             DIR6(forest37),"west"});
  set_light(0);
  outdoorness = 4;
}
