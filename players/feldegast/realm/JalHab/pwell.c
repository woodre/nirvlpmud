#include "defs.h"

inherit ROOM;

int well;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc=GRN+"P'kalian Village"+NORM;
  long_desc=
"  The buildings of the village are all arranged in a circular fashion\n\
around a brownstone well that is the only source of water for miles\n\
in any direction.  To the southeast is a squat building with a tankard\n\
stenciled over the door.  To the south is a yellow building with a\n\
potion stenciled over the door.  In a large squarish building to the\n\
north you hear the sounds of fighting.  Ivy clings to a building on\n\
the western side of the circle.  To the northwest is a building made\n\
out of granite and oak with a sign in dwarven script.\n";
  items=({
    "buildings", "The buildings are made out of sandstone and clay",
    "well", "The well is covered by a wooden hatch with a lock on it",
    "squat building", "The squat building appears to be a drinking establishment\n"+
                      "of some kind",
    "yellow building", "The yellow building appears to be an apothecary",
    "squarish building", "It appears to be some sort of training hall",
    "ivy building", "The ivy covered building appears to be the oldest in the entire\n"+
                    "village.  It might be a meeting hall",
    "granite building", "The building is short and squat, and obviously of dwarven\n"+
                        "design",
  });
  dest_dir=({
    "blank","leave",
    PATH+"padvance.c","north",
    PATH+"ptrader.c","northwest",
    PATH+"phall.c","west",
    PATH+"papoth.c","south",
    PATH+"pbar.c","southeast",
  });
}

void init() {
  ::init();
  add_action("cmd_leave","leave");
  add_action("cmd_break", "break");
  add_action("cmd_break", "shatter");
  add_action("cmd_break", "smash");
  add_action("cmd_break", "force");
  add_action("cmd_open", "open");
  add_action("cmd_unlock", "unlock");
}

cmd_break(str) {
  if(str!="hatch") return 0;
  write("The hatch is too strong.  You'll have to think of something else.\n");
  return 1;
}

cmd_unlock(str) {
  if(str!="hatch" && str!="well") {
    notify_fail("Unlock what?\n");
    return 0;
  }
  if(well != 0) {
    write("The well has already been opened.\n");
    return 1;
  }
  if(!present("key#30303",TP)) {
    notify_fail("You don't have the key.\n");
    return 0;
  }
  write("You unlock the hatch.\n");
  well++;
  destruct(present("key#30303",TP));
  this_player()->add_weight(-1);
  return 1;
}
    
cmd_open(str) {
  if(str!="hatch" && str!="well") {
    notify_fail("Open what?\n");
    return 0;
  }
  if(well==0) {
    write("The hatch is locked.\n");
    return 1;
  }
  if(well==2) {
    write("The hatch has already been opened.\n");
    return 1;
  }
  write("You find the Key of Water inside the well.\n");
  move_object(clone_object(OBJ_PATH+"key-water.c"),TP);
  this_player()->add_weight(2);
  well++;
  return 1;
}

int cmd_leave(string str)
{
  say(TPN+" leaves.\n");
  move_object(TP,(object)MAP->query_location(3,2));
  say(TPN+" walks out of the village.\n");
  command("look",TP);
  return 1;
}

query_coords() { return ({ 3,2 }); }
