#define ANSWER "4"
#include "defs.h"

inherit ROOM;

int answer;

void reset(int arg) {
  answer=0;
  if(!present("revanche"))
    move_object(clone_object(MON_PATH+"sir_rev.c"),this_object());
  if(arg) return;
  short_desc=BOLD+BLK+"Castle Magnarn"+NORM;
  long_desc=
"  This was once a cellar or storage room.  It is filled with rotting\n\
pieces of wood that may've once been crates or barrels.  On the\n\
eastern wall there is a stone portal with a fascinating design on\n\
the door.\n";
  items=({
    "wood", "Rotting pieces of wood cover the floor",
    "crates", "They are just splinters now",
    "barrels", "They are just splinters now",
    "wall", "It is made of stone",
    "design",
"It appears to be a puzzle.\n\
                   +-+-+-+\n\
                   |5|3|2|\n\
                   +-+-+-+\n\
                   |3|5|1|\n\
                   +-+-+-+\n\
                   |1|2|4|\n\
                   +-+-+-+\n\
You sense that the solution to this puzzle is a number.\n\
When you know the answer you may 'answer' it",
    "pattern",
"It appears to be a puzzle.\n\
                   +-+-+-+\n\
                   |5|3|2|\n\
                   +-+-+-+\n\
                   |3|5|1|\n\
                   +-+-+-+\n\
                   |1|2|4|\n\
                   +-+-+-+\n\
You sense that the solution to this puzzle is a number.\n\
When you know the answer you may 'answer' it",
   "door", "You cannot open this door with force.  You suspect that the\n"+
           "only way to open the door is to answer the riddle posed\n"+
           "by the pattern",
   "portal", "You cannot open this door with force.  You suspect that the\n"+
           "only way to open the door is to answer the riddle posed\n"+
           "by the pattern",

  });
  dest_dir=({
    PATH+"castle3.c","up",
    PATH+"castle16.c","east",
  });
}

void init() {
  ::init();
  add_action("cmd_answer", "answer");
  add_action("cmd_open", "open");
  add_action("cmd_east", "east");
}

int cmd_open(string str) {
  if(str=="portal" || str=="door") {
    write("You can't even budge the door.\n");
    return 1;
  }
}

int cmd_answer(string str) {
  if(!str) {
    notify_fail("Answer <number>\n");
    return 0;
  }
  if(answer==-1) {
    write("The mechanism behind the portal doesn't appear to be working\n"+
          "anymore.\n");
    return 1;
  }
  if(str!=ANSWER) {
    write("You hear a discordant gong.  Your answer was incorrect.\n"); 
    answer=-1;
    return 1;
  }
  tell_room(this_object(),"You hear a loud gong.  The portal swings open.\n");
  items[9]="It is already open",
  answer=1;
  write_file("/players/feldegast/log/event.log",ctime(time())+" "+pad(TPN,20)+" Box Puzzle\n");
  return 1;
}

int cmd_east(string str) {
  if(answer!=1) {
    write("The portal is closed.\n");
    return 1;
  }
  if(present("revanche")) {
    write("Sir Revanche says: Forgive me, but I can't let you go in there.\n");
    return 1;
  }
  return (int)cmd_move(str);
}
