#include "defs.h"

inherit ROOM;

void reset(int arg) {
  object guard;
  int i;
  if(!present("guard")) {
    for(i=random(3); i > 0; i--) {
      guard=clone_object(MON_PATH+"goldcloak.c");
      if(random(2)) guard->set_aggressive(1);
      move_object(guard,this_object());
    }
  }
  if(!present("lieutenant"))
    move_object(clone_object(MON_PATH+"goldcloak4.c"),this_object());
  if(arg) return;
  set_light(1);
  short_desc="Tower of the Righteous";
  long_desc = 
"  This appears to be the sleeping area of the guards.  The room\n"+
"is filled with rows of bunk beds.  An open window on the north\n"+
"wall lets in a breeze.  An unoccupied torch sconce is near the\n"+
"stairwell which leads back down.\n";
  items=({
    "beds", "The bunk beds are old and plain, but solidly constructed.\n"+
            "But they don't look very comfortable",
    "window", "The window looks out on the palace to the north",
    "sconce", "The torch sconce looks odd, and the stone is scraped\n"+
              "near it",
    "stairwell", "The stairs lead back down into the common room",
  });
  dest_dir=({
    PATH+"barrack4.c","west",
    PATH+"barrack2.c","down",
  });
}

void init() {
  ::init();
  add_action("cmd_block","west");
  add_action("cmd_not", "twist");
  add_action("cmd_not", "push");
  add_action("cmd_pull", "pull");
}

int cmd_block(string str) {
  if(present("goldcloak")) {
    write("The Goldcloak blocks your way.\n");
    return 1;
  }
}

int cmd_not(string str) {
  if(str!="sconce") {
    notify_fail(capitalize(query_verb())+" what?\n");
    return 0;
  }
  write("You manage to jostle the sconce, but that doesn't seem to do anything.\n");
  say(TPN+" "+query_verb()+"s the sconce.\n");
  return 1;
}

int cmd_pull(string str) {
  if(str!="sconce") {
    notify_fail("Pull what?\n");
    return 0;
  }
  write("A secret passage opens as you pull on the sconce.  You\n"+
        "step through it into darkness.\n");
  TP->move_player("into a secret passageway#"+PATH+"barrack3a");
  return 1;
}
