#include "/players/forbin/rev/blue/pathdef.h"
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;
  short_desc = "An entrance";
  long_desc = 
    "Sunlight filters through the rotting castle door to lighten a very\n"+
    "dusty entryway.  Opposite the main pair of doors, a closed metal\n"+
    "gate hangs down from an arched opening and rests firmly on the\n"+
    "ground.  Something lies pinned underneath its spikes at the left\n"+
    "end; whatever it is looks as old as the dust covering it.  A thick\n"+
    "woven rope passes down from a hole in the ceiling above.  A large\n"+
    "sign has broken and fallen to the ground.\n";
  set_light(1);
  add_item(({"sunlight","light"}),
    "Bright beams of sunlight stream into the room and illuminate all\n"+
    "but the darkest corners");
  add_item("castle",
    "The castle is in a tremendous state of disrepair");
  add_item(({"door","doors","pair of doors"}),
    "The main doors are fairly rotten.  One is slightly wider than the\n"+
    "the other; the slender doors hangs tenuously from its hinges.");
  add_item(({"gate","metal gate"}),
    "A massive metal gate blocks travel through the arched opening\n"+
    "opposite the main doors.  One inch thick bars spaced about five\n"+
    "inches apart leave little room to squeeze through.  One might be\n"+
    "able to lift the gate and pass beyond");
  add_item(({"opening","arched opening","arch"}),
    "The arched opening leads into what looks like a short passageway\n"+
    "that leads back outside");
  add_item("ground",
    "The ground here is caked with dust");
  add_item(({"spike","spikes"}),
    "The metal spikes at the bottom of the gate rest firmly in the\n"+
    "ground.  It would take someone big to free the gate");
  add_item("dust",
    "A rather thick layer of dust covers almost everything here.  It\n"+
    "makes the area looked unused for decades");
  add_item(({"rope","woven rope","thick rope","thick woven rope"}),
    "A thick rope of a rough woven material hangs down from the ceiling\n"+
    "Several dozen knots have been tied at intervals along its lenght\n"+
    "Oddly enough, it isn't covered with dust like everything else here");
  add_item("hole",
    "A large hole has been cut into the ceiling.  A rope snakes its way\n"+
    "upward and disappears into the darkness beyond");
  add_item("ceiling",
    "The ceiling towers high above.  It looks in rather good shape\n"+
    "except for a large hole in it");
  add_item(({"sign","large sign"}),
    "A large sign has fallen over onto the ground.  One could read it");                
  add_exit(ROOT+"castle/entry1b","north");
  add_exit(ROOT+"castle/entrance","south");
  add_exit(ROOT+"fire/passage", "west");
  add_exit(ROOT+"castle/entry2", "up");
  add_exit(ROOT+"dungeon/entrance", "down");
}

void init() {
  ::init();
  add_action("cmd_move","north");
  add_action("cmd_lift", "lift");
  add_action("cmd_read","read");
  add_action("cmd_move","up");
  add_action("cmd_move","down");  
}

status cmd_move() {
  if(query_verb() == "north") {
    write(
      "The metal gate blocks your path.  Maybe if you lifted it, you\n"+
      "could hurry pass.\n");
    return 1;
  }
  if(query_verb() == "up") {
    if(this_player()->query_level() > 7) {
      write(
        "You tug on the rope and find it may not support you.\n"+
        "You are too powerful to go up there.\n");
      return 1;    
    }
  }
  if(query_verb() == "down") {
    if(this_player()->query_level() > 2) {
      write(
        "You decide you are too powerful to go down there.\n");
      return 1;    
    }
  }  
}

status cmd_lift(string str) {
     if(!str || str != "gate") return 0;
     if (this_player()->query_level() < 13) {
       write(
         "You pull with all your might, but the gate refuses to budge.\n"+
         "You are too small to lift the gate.\n");
       return 1;
     }
     write(
       "You lift the gate and quickly walk under it.\n"+
       "It crashes down loudly down behind you.\n");
     this_player()->move_player("beyond the gate#"+ROOT+"castle/entry1b");
     return 1;
}

status read_sign(string str) {
  if(!str || str != "sigh") return 0;
  write(
  "        Welcome to my castle!\n\n\n"+
  "You will hopefully find this castle interesting and well stocked. There are\n"+
  "areas for new-newbies, kinda newbies, and players with big...swords.\n"+
  "And finally, and intermediate zone for players up to level 14.  I'm sure\n"+
  "you can find plenty to do, whatever your level...\n\n"+
  "NEW-NEWBIES - DOWN - Check out the cellar\n\n"+
  "NEWBIES-UP - Take a peek at the uglies upstairs\n\n"+
  "MID-LEVELS - WEST! Brand new!!!! Visit the tower of fire....\n\n"+
  "HIGH-LEVELS - Lift the gate. You will have to be more creative.\n\n"+
  "Please mail me with any problems, complaints or opinions!\n\n"+
  "                                    -Blue\n");
   return 1;
}
