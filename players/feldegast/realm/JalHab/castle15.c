#include "defs.h"

inherit ROOM;

int found;

void reset(int arg) {
  if(!present("cleric")) 
    move_object(clone_object(MON_PATH+"dcleric.c"),this_object());
  if(arg) return;
  set_light(1);
  short_desc=BOLD+BLK+"Dark Temple"+NORM;
  long_desc=
"  This temple has a lingering aura of ancient evil.  Thirteen obsidian\n\
pillars circle a platform in the center of the temple.  On the platform\n\
is a sacrificial altar that has been blackened by the blood of its\n\
victims.\n";
  items=({
    "temple", "reflexive",
    "pillars", "The obsidian pillars are each as black as a demon's heart",
    "platform", "The platform is twenty meters across with thirteen points,\n"+
                "a pillar at each point",
    "altar", "The sacrificial altar is squarish, with an inscription carved\n"+
             "along its edge",
    "inscription", "It is in a language that you understand",
  });
  dest_dir=({
    PATH+"castle13.c","west",
  });
}

void init() {
  ::init();
  add_action("cmd_read", "read");
  add_action("cmd_search","search");
}

int cmd_read(string str) {
  if(str=="inscription") {
    write("The inscription reads:\n"+
          HIR+"Hail Mighty Kruarg, accept our gifts in exchange for succor when thy kingdom is at hand.\n"+NORM);
    return 1;
  }
  notify_fail("Read what?\n");
}

int cmd_search(string str) {
  object cleric;
  if(str!="altar") {
     notify_fail("Search what?\n");
     return 0;
  }
  if(found) {
    notify_fail("You find nothing.\n");
    return 0;
  }
  cleric=present("darke cleric");
  if(cleric) {
    write("Darke Cleric says: Do not touch that!\n");
    cleric->attacked_by(TP);
    return 1;
  }
  found=1;
  write("You find a hidden panel on the altar.  Inside of it you find a\n"+
        "white, powdery ball, and a scrap of paper.\n");
  move_object(clone_object(OBJ_PATH+"paper1.c"),this_object());
  move_object(clone_object(OBJ_PATH+"ball.c"),this_object());
  return 1;
}
