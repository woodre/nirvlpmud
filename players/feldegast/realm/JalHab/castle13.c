#include "defs.h"

inherit ROOM;

int dial1;
int dial2;
int open;

void reset(int arg) {
  if(!present("dreadknight"))
    move_object(clone_object(MON_PATH+"dreadknight.c"),this_object());
  dial1=random(24);
  dial2=random(24);
  if(arg) return;
  set_light(1);
  short_desc=BOLD+BLK+"Castle Magnarn"+NORM;
  long_desc=
"  A large metal dome is the most prominent feature of this chamber.\n\
It sits in the middle of the room.  The room itself has been carved\n\
from the rocks into a nearly perfect square.  Another archway leads\n\
east.\n";
  items=({
    "chamber", "reflexive",
    "room", "reflexive",
    "rocks", "The wall consists predominantly of limestone",
    "archway", "A few steps lead up to the archway and into a large chamber\n"+
               "to the east",
    "dome", "see long func",
  });
  dest_dir=({
    PATH+"castle15.c","east",
    PATH+"castle10.c","south",
  });
}

void init() {
  ::init();
  add_action("cmd_push","push");
  add_action("cmd_press", "press");
  add_action("cmd_block","down");
}

long(str) {
  if(str=="dome") {
    if(!open) {
      write("The dome is constructed of two semi-spherical plates of iron.\n"+
            "At the top of the dome where the two plates meet there is a\n"+
            "dial with two buttons next to it.  The dial has two indicators\n"+
            "on it, and twenty-four marks.  The two buttons can be 'push'ed\n"+
            "and 'press'ed respectively.\n");
      write("Dial one: "+dial1+"\n");
      write("Dial two: "+dial2+"\n");
      return;
    } else {
      write("The dome is open, revealing a dark pit.\n");
      return;
    }
  }
  ::long(str);
}

void check_answer() {
  if(!random(10))
  {
    write(HIY+"The button shocks you lightly.\n"+NORM);
    say(HIY+TPN+" is lightly shocked.\n"+NORM);
    TP->do_damage( ({ 10+random(10) }), ({ "other|electricity" }));
  }
  if(dial1 == 0 && dial2 == 0) {
    write("The dome splits open, revealing a deep pit.\n");
    write_file("/players/feldegast/log/event.log",ctime(time())+" "+pad(TPN,20)+" Dome Puzzle\n");
    dest_dir=({
      PATH+"castle15.c","east",
      PATH+"castle10.c","south",
      PATH+"castle14.c","down",
    });
    open=1;
    add_action("cmd_block","down");
  }
}

int cmd_push(string str) {
  if(open) return 0;
  dial1=(dial1 + 3) % 24;
  dial2=(dial2 + 5) % 24;
  write("You push button #1 and the dial changes.\n");
  write("Dial one: "+dial1+"\n");
  write("Dial two: "+dial2+"\n");
  check_answer();
  return 1;
}

int cmd_press(string str) {
  if(open) return 0;
  dial1=(dial1 + 2) % 24;
  dial2=(dial2 + 1) % 24;
  write("You press button #2 and the dial changes.\n");
  write("Dial one: "+dial1+"\n");
  write("Dial two: "+dial2+"\n");
  check_answer();
  return 1;
}

int cmd_block(string str) {
  if(present("dreadknight")) {
    TP->attacked_by(present("dreadknight"));
    return 1;
  } else return (int)::cmd_move(str);
}

