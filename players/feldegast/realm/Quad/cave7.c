#include "../def.h"
inherit MYROOM;

int locked,chest=1;

reset(arg) {
  if(!present("blacksmith")) {
    move_object(clone_object("/players/feldegast/mon/qmaster"));
  }
  if (arg) return;
  set_light(1);
  short_desc="The Blacksmith's Quarters";
  long_desc=
"    This cozy nook is filled almost completely by a large\n"+
"cot and a tightly banded chest.  The rest of the floor is\n"+
"covered in old blankets, scrap metal, and other detritus.\n";
  items=({
    "cot","A simple, but large bed",
    "floor","The floor is covered in old blankets, scrap metal, and other detritus",
    "chest","The tightly banded chest has a huge lock on it.  You'll need a key to open it",
    "blankets","Ragged old pieces of cloth",
    "scrap metal","Pieces of metal whose former purpose you cannot decipher",
    "detritus","Bones, the remnants of old meals, and useless rags"
  });
  dest_dir=({
    PATH+"Quad/cave6","south"
  });
}   
init() {
  ::init();
  add_action("search","search");
  add_action("cmd_unlock","unlock");
  add_action("cmd_open","open");
}
search() {
  write("You find nothing.\n");
  return 1;
}
cmd_unlock(str) {
  if(!str || str!="chest") { notify_fail("Unlock what?\n");return 0;}
  if(!present("key101",this_player())) { notify_fail("You don't have the key.\n"); return 0; }
  write("You unlock the chest.\n");
  say(this_player()->query_name()+" unlocks the chest.\n");
  locked=0;
  return 1;
}
cmd_open(str) {
  if(!str || str!="chest") { notify_fail("Open what?\n"); return 0; }
  if(locked) { write("The chest is locked.\n"); return 1; }
  {
  chest=0;
    write("You open the chest and spread its contents onto the floor.\n");
    move_object(clone_object("/players/feldegast/wep/dhammer"),environment(this_player()));
  }
  return 1;
}
