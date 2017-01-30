/*
File: 1x8.c
Creator: Feldegast @ nirvana.mudservices.com
Date: 2/1/01
Description:
  Barony of Caladon
  Base of the Tower of Ravens
*/
#include "defs.h"

inherit ROOM;

int open;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  x=1; y=9;
  set_light(1);
  short_desc="Base of the "+BOLD+BLK+"Tower of Ravens"+NORM;
  long_desc=
"  This is a tall hill several miles south of the River Siber.  To\n\
the west the rolling hills rise into the Storncrag mountains.  At the\n\
hill's peak a tall black tower spirals up into the clouds.  At the\n\
base of the tower five steps lead up to a metal door.\n";
  items=({
    "river", "The banks of the river are several miles to the north",
    "siber", "The banks of the river are several miles to the north",
    "mountains", "The mountains to the west of you are tall and frosted with\n"+
                 "snow.  It would be difficult to cross them",
    "storncrag", "The mountains to the west of you are tall and frosted with\n"+
                 "snow.  It would be difficult to cross them",
    "hills", "The hills to the south and west of you are dotted with\n"+
             "trees",
    "hill", "reflexive",
    "trees", "Tall, deciduous trees dot the hills",
    "tower", "The tall black tower sits on top of the highest hill for miles around and\n"+
             "spirals up into the clouds.  There is a door at its base",
    "clouds", "They look white and puffy",
    "steps", "Five short steps lead up to a metal door",
    "door", "The door is made completely out of metal and appears to have no\n"+
            "handles or locks.  An image of a silver raven is on the door.  It\n"+
            "looks so realistic that you have the urge to touch it to see if\n"+
            "it is real",
    "raven", "An image of a silver raven is on the door.  It looks so realistic\n"+
             "that you have the urge to touch it to see if it is real",
  });
  dest_dir=({
    PATH+"1x9.c","north",
    PATH+"2x8.c","east",
    PATH+"1x7.c","south",
  });
}

void init() {
  ::init();
  add_action("cmd_touch", "touch");
  add_action("cmd_answer", "answer");
  add_action("cmd_enter", "enter");
  add_action("cmd_open", "open");
}

int cmd_touch(string str) {
  if(str!="raven" && str!="door") {
    notify_fail("Touch what?\n");
    return 0;
  }
  write("As you touch the raven the silver becomes fluid.  The raven\n"+
        "turns to you and caws:\n"+BOLD+BLK+
        "\tThe part of the bird\n"+
        "\tthat is not in the sky,\n"+
        "\twhich can swim in the ocean\n"+
        "\twithout getting wet.\n"+
        "\tWhat is it?\n"+NORM+
        "If you think you can solve the riddle, you may <answer>.\n"
  );
  say(TPN+" touches the door.\n");
  return 1;
}

int cmd_answer(string str) {
  string j1,j2;
  int sp;
  if(!str) {
    notify_fail("Usage: answer <answer>\n");
    return 0;
  }
  if(open) {
    write("The door is already open.\n");
    return 1;
  }
  write_file("/players/feldegast/log/riddles.log",
    ctime(time())+" "+TPRN+" raven riddle "+str+"\n");
  if(sscanf(str,"%sshadow%s",j1,j2)==2 ||
     sscanf(str,"%sshadow",j1)==1) {
    write("You answer correctly.  The raven turns back into metal and\n"+
          "the door swings open.\n");
    say("The door opens.\n");
    items[21]="The door is open";
    open=1;
    return 1;
  }
  write("You answered incorrectly.  The raven's eyes glow bright and\n"+
        "seem to drain your energy.  You feel weak and helpless.\n");
  say("The raven's eyes glow brightly.\n");
  sp=(int)TP->query_sp();
  TP->add_spell_point(-sp);
  return 1;
}

int cmd_enter(string str) {
  if(str!="tower" && str!="door") {
    notify_fail("Enter what?\n");
    return 0;
  }
  if(!open) {
    write("The door is closed and you can't open it.\n");
    return 1;
  }
  write("You enter the "+BOLD+BLK+"Tower of Ravens"+NORM+".\n");
  say(TPN+" enters the tower.\n");
  move_object(TP,PATH+"raven1.c");
  command("look",TP);
  say(TPN+" arrives.\n");
  return 1;
}

int cmd_open(string str) {
  if(str=="door") {
    write("You can't open the door.  There are no handles nor locks on it.\n");
    return 1;
  }
}
