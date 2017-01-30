#include "defs.h"

inherit ROOM;

int lock,open;

void reset(int arg) {
  if(!present("mage"))
    move_object(clone_object(MON_PATH+"brigand8.c"),this_object());
  lock=1;
  open=0;
  if(arg) return;
  set_light(1);
  short_desc="Brigand Cave";
  long_desc=
"  This is a small alcove off of a larger cavern.  It is cluttered\n"+
"with the typical debris of a messy person: torn shirts, dry crusts,\n"+
"and a messy bunk.  A wooden chest is in the corner between the\n"+
"bunk and the cave wall.\n";
  items=({
    "debris","The debris is strewn about the the alcove",
    "shirts","They're torn and useless",
    "crusts","They look like they came from a pizza, but that's impossible",
    "bunk","A simple bunk that hasn't been made in a while",
    "chest","A wooden chest with a strong magical lock on it",
    "wall","The cave wall",
  });
  dest_dir=({
    PATH+"rocks3.c","east",
  });
}

void init() {
  ::init();
  add_action("cmd_unlock","unlock");
  add_action("cmd_open","open");
}

cmd_unlock(str) {
  if(str!="chest") {
    notify_fail("Unlock what?\n");
    return 0;
  }
  if(!present("key#1010101",TP)) {
    notify_fail("You don't have the right key.\n");
    return 0;
  }
  lock=0;
  write("You unlock the chest.\n");
  say(TPN+" unlocks the chest.\n");
  return 1;
}
  
cmd_open(str) {
  int i,file;
  object ob;
  if(str!="chest") {
    notify_fail("Open what?\n");
    return 0;
  }
  if(lock) {
    write("The chest is locked.\n");
    return 1;
  }
  if(open) {
    write("The chest has already been opened and looted.\n");
    return 1;
  }
  for(i=0; i < 3; i++) {
    switch(i) {
      case 0: ob=clone_object(OBJ_PATH+"charm.c"); break;
      case 1: ob=clone_object(WEP_PATH+"weedslay.c"); break;
      case 2: ob=clone_object(WEP_PATH+"death-hoe.c"); break;
    }
    write("You find: "+ob->short()+"\n");
    move_object(ob,this_object());
  }
  say(TPN+" opens the chest.\n");
  open = 1;
  return 1;
}
 
