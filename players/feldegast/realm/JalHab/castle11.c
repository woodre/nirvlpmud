#include "defs.h"

inherit ROOM;

int answered;

void reset(int arg) {
  answered=0;
  if(arg) return;
  set_light(1);
  short_desc=BOLD+BLK+"Castle Magnarn"+NORM;
  long_desc=
"  The tunnel is dusty and strewn with rubble, but it appears to be\n\
man-made.  After fifty feet the tunnel ends in a pair of steel doors\n\
with an inscription on them.\n";
  items=({
    "tunnel","reflexive",
    "rubble", "Piles of dirt and rock obstruct the tunnel occasionally",
    "doors", "The doors have an inscription on them in a language that you\n"+
             "understand",
    "inscription", "The doors have an inscription on them in a language that you\n"+
                   "understand",
  });
  dest_dir=({
    PATH+"castle16.c","west",
    PATH+"castle10.c","east",
  });
}

void init() {
  ::init();
  add_action("cmd_answer", "answer");
  add_action("cmd_open", "open");
  add_action("cmd_read", "read");
  add_action("cmd_west", "west");
}

int cmd_read(string str) {
  if(str=="inscription" || str=="doors") {
    write(
"The inscription reads:\n\
  'The MageLord of Magnarn had twice as many concubines as wives.\n\
   Each of his wives bore him three sons or daughters and each of\n\
   his concubines bore him two sons or daughters except for his\n\
   favorite, Marissa, who was murdered out of petty jealousy before\n\
   she could bear him a child.  If the MageLord of Magnarn had three\n\
   wives, then how many children did he have?\n\
When you think you know the answer, you may "+BOLD+"answer"+NORM+" the puzzle.\n");
    return 1;
  }
  notify_fail("Read what?\n");
}

int cmd_answer(string str) {
  if(!str) { notify_fail("Usage: answer <answer>\n"); return 0; }
  if(answered==1) {
    write("The doors are already open.\n");
    return 1;
  }
  if(answered==-1) {
    write("Nothing happens.  The mechanism seems to be jammed.\n");
    return 1;
  }
  if(str!="19") {
    write("A discordant *bong* rings through the tunnels.\n"+
          "You answered incorrectly.\n");
    answered=-1;
    return 1;
  }
  write("You hear a chime as you utter the answer and the doors slowly\n"+
        "swing open.\n");
  say("The doors swing open.\n");
  answered=1;
  write_file("/players/feldegast/log/event.log",ctime(time())+" "+pad(TPN,20)+" Algebra Puzzle\n");
  return 1;
}

int cmd_open(string str) {
  if(str=="doors" || str=="door") {
    write("You cannot open them.\n");
    return 1;
  }
  notify_fail("Open what?\n");
}

int cmd_west(string str) {
  if(answered==1)
    return (int)cmd_move(str);
  else {
    write("The doors block the way.\n");
    return 1;
  }
}
