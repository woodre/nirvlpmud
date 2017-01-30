#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

inherit "room/room";

int X;
int Y;

reset(arg)
{
  if (arg) return 0;
  set_light(1);
  short_desc=("Entrance to the Hall");
  long_desc="     Looming ahead, an imposing building stands. Grey stone\n\
walls rise from the rocky terrain. The dark outlines of many\n\
arrowslits mark the structure as a battle fortress, yet the\n\
sculptures along the building lend an air of sophistication.\n\
Tall gates stand marked with carvings that have faded with time.\n\
Do you dare to enter those gates to see what lies within this\n\
ominous edifice? To the side, a shimmering portal floats in\n\
the center of a bleak landscape marked only by some sparse\n\
flora which lines the footpath leading towards the gates.\n"; 
  items =
  ({
    "walls",      "Tall and dark, the walls stand to guard what lies within",
    "building",   "Perhaps the home of some dark lord",
    "terrain",    "Rough landscape of stone and dust as far as the eye can see", 
    "stone",      "Rough landscape of stone and dust as far as the eye can see", 
    "dust",       "Rough landscape of stone and dust as far as the eye can see", 
    "arrowslits", "Within, darkness",
    "darkness",   "All is dark within the structure", 
    "structure",  "Perhaps the home of some dark lord",
    "sculptures", "Dark stone sculptures of fantastic beasts line the walls",
    "beasts",     "Dark stone sculptures of fantastic beasts line the walls",
    "gates",      "Made of a dark metal, the carvings fill you with ominous thoughts",
    "metal",      "Made of a dark metal, the carvings fill you with ominous thoughts",
    "carvings",   "Bas relief upon the gates, the sculptures are scenes of battle",
    "edifice",    "Perhaps the home of some dark lord",
    "portal",     "Perhaps you should go back now while you have the chance",
    "landscape",  "A plain of dark rock stretching into the distance",
    "plain",      "A plain of dark rock stretching into the distance",
    "flora",      "Some root which might deserve further examination",
    "root",       "Deathbane, said to ward off the powers of necromancy",
    "deathbane",  "A small supply could be aquired here",
    "footpath",   "A narrow path leading to the structure ahead",
    "fortress",   "An imposing and harsh structure",
  });
  dest_dir =
  ({
    "/players/anshar/chamber", "portal",
  });
}

init()
{
  ::init();
  add_action("enter_gates","enter");
  add_action("pick_root","pick");
  add_action("pick_root","dig");
}

enter_gates(str)
{
  if(!str || str != "gates" && str != "gate")
  {
    notify_fail("Enter what?\n");
    return 0;
  }
  if(X==0)
  { 
    move_object(clone_object("/players/anshar/hall/mon/azelane"),this_object());
    write("A lithe figure jumps from above the gates blocking your entrance.\n"); 
    say("A lithe figure leaps down, preventing "+this_player()->query_name()+
        "'s passage.\n");
    X++;
    return 1;
  }
  if(X==1 && present("azelane"))
  { 
    write("Azelane tells you: Do not enter here at risk of your life.\n"); 
    say("The beautiful woman prevents "+this_player()->query_name()+
        " from entering.\n");
    X++;
    return 1;
  }
  if(X==2 && present("azelane"))
  {
    write("Azelane tells you: You were warned, now pay the consequences.\n"); 
    present("azelane",this_object())->attack_object(this_player());
    return 1;
  }
  this_player()->move_player("gates#/players/anshar/hall/room/hall2");
  return 1; 
}

pick_root(str)
{
  if(!str || str != "root" && str != "deathbane")
  { 
    notify_fail("What?\n");
    return 0;
  }
  if(present("azelane"))
  {
    write("Azelane prevents you from getting the root.\n"); 
    say("The beautiful woman prevents "+this_player()->query_name()+" from getting the root.\n");
    return 1;
  }
  if(Y==0)
  {
    move_object(clone_object("/players/anshar/hall/item/root"),this_player());
    write("You get one of the tender roots.\n"); 
    say(""+this_player()->query_name()+" gets a root from the side of the path.\n");
    Y++;
    return 1;
  }
  write("There are no roots to get.\n");
  say(""+this_player()->query_name()+"b ends at the side of the path, but comes up empty handed.\n");
  return 1;
}
