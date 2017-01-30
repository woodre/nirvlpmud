#include "def.h"
inherit MYROOM;
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="Dr. Schreber's Office";
  long_desc=
"     The centerpiece of Dr. Schreber's office is a spiralling maze\n\
filled with a lab rat desperately attempting to find an exit that\n\
doesn't exist.  The rest of the office is cluttered with messy old\n\
papers and notebooks.\n";
  items=({
    "maze","The spiralling maze is perfectly circular with removable\n"+
           "walls and other obstacles.  There doesn't seem to be a way\n"+
           "out of it for some reason",
    "rat","A little white lab rat that runs through the maze despite the\n"+
          "fact that there is no real exit",
    "papers","Complicated psycho-babble which you can't begin to comprehend",
    "notebooks","One dusty old journal catches your eye.  You might want to read it"
  });
  dest_dir=({
    PATH+"lobby2","down"
  });
}   
init() {
  ::init();
  add_action("cmd_read","read");
}
cmd_read(str) {
  if(!str || str!="journal") {
    notify_fail("Read what?\n");
    return 0;
  }
  write(
"You open the old journal and skim through it.  One entry catches your eye:\n"+
"  I have at last found a way to transfer memories between two lab rats.\n"+
"  I placed Rat A in the maze and through negative reinforcement taught\n"+
"  it to navigate between point A and point B in the maze.  Then, I\n"+
"  extracted Rat A's memory using the aforementioned process.  Using\n"+
"  the aforementioned specially designed needle, I injected the 'memory\n"+
"  extract' into Rat B.  Rat B was immediately able to navigate the maze\n"+
"  despite no prior contact.\n");
  say(this_player()->query_name()+" reads a journal on Dr. Schreber's desk.\n");
  return 1;
}

