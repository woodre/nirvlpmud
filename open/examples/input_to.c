#define SIGN "\"A rock flew over the cuckoo's nest.\""
#define COUNTERSIGN "And hit the Sultan's cat."

#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc="An alley";
  long_desc=
"  This is an alley just off of the plaza of the merchants, between\n"+
"two shops.  At the end of the alley is a strong oak door with a\n"+
"peephole at eye level.\n";
  items=({
    "shops", "You can't see them well from here",
    "door", "It is a strong oak door with a peephole at eye level",
    "peephole", "It is a rectangle cut into the door, covered by a\n"+
                "piece of iron",
  });
  dest_dir=({
    PATH+"smerch.c","out",
  });
}

void init() {
  ::init();
  add_action("cmd_open", "open");
  add_action("cmd_enter", "enter");
  add_action("cmd_pull", "pull");
  add_action("cmd_pull", "push");
  add_action("cmd_knock", "knock");
}

int cmd_open(string str) {
  if(str=="door") {
    write("It is locked.\n");
    return 1;
  }
}

int cmd_enter(string str) {
  if(str=="door") {
    write("It is closed.\n");
    return 1;
  }
}

int cmd_pull(string str) {
  if(str=="door") {
    write("You push and pull on the door with little effect.\n");
    return 1;
  }
}

int cmd_knock(string str) {
  if(str!="door" && str!="on door") {
    notify_fail("Knock on what?\n");
    return 0;
  }
  write("The peephole opens and a pair of dark black eyes stare at you.\n"+
        SIGN+"\nYou reply: ");
  input_to("answer");
  return 1;
}

void answer(string str) {
  if(str!=COUNTERSIGN) {
    write("\"Bugger off, pal.\"\n");
    write("The peephole slides shut.\n");
    return;
  }
  write("The door opens and you are escorted inside.\n");
  say(TPN+" enters the door.\n");
  move_object(TP,PATH+"sakadi.c");
  say(TPN+" arrives.\n");
  return;
}
