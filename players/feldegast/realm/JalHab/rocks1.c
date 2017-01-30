#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(!present("borgas"))
    move_object(clone_object(MON_PATH+"brigand1.c"),this_object());
  if(!present("slika"))
    move_object(clone_object(MON_PATH+"brigand2.c"),this_object());
  if(!present("natarios"))
    move_object(clone_object(MON_PATH+"brigand3.c"),this_object());
  if(arg) return;
  set_light(1);
  short_desc=MAG+"The Fingers of God"+NORM;
  long_desc=
"  Hidden among the jagged rock formation known as the Fingers of God\n\
you find a bandit camp.  In the center of the camp is a slow burning\n\
fire of cactus and tumbleweed surrounded by black rocks.  Placed around\n\
it are a disheveled mess of blankets, cooking utensils and bones\n\
discarded from previous meals.  An open cave mouth leads deeper into\n\
the rocks.\n";
  items=({
    "cactus","It is crackling and popping in the fire",
    "tumbleweed","The tumbleweed doesn't seem to be generating much heat\n"+
                 "but it produces an awful lot of smoke",
    "rocks","The jagged rocks around you are filled with nooks and crannies,\n"+
            "rather like an english muffin",
    "blankets","You reluctantly decide that the blankets are not worth\n"+
               "salvaging",
    "utensils","You turn your nose at the bent and dented pots and pans\n"+
               "that are filled with some crusty substance that you can't\n"+
               "identify",
    "cooking utensils","You turn your nose at the bent and dented pots and pans\n"+
                       "that are filled with some crusty substance that you can't\n"+
                       "identify",
    "bones","The bones have been picked clean, cracked and emptied of marrow.\n"+
            "You suspect they were once the skeletal structure of small desert\n"+
            "rats or other small prey",
    "cave","The narrow cave opening leads deep into the rocks",
    "mouth","The narrow cave opening leads deep into the rocks",
  });
  dest_dir=({
    "blank","leave",
  });
}
void init() {
  ::init();
  add_action("cmd_leave","leave");
  add_action("cmd_enter","enter");
}

int cmd_leave(string str)
{
  say(TPN+" leaves.\n");
  move_object(TP,(object)MAP->query_location(2,8));
  say(TPN+" walks out of the rocks.\n");
  command("look",TP);
  return 1;
}

int cmd_enter(string str) {
  if(str!="rocks" && str!="cave" && str!="mouth") {
    notify_fail("Enter what?\n");
    return 0;
  }
  if(present("brigand")) {
    write("You cannot enter the cave while there are brigands here.\n");
    return 1;
  }
  write("You enter the cave.\n");
  say(TPN+" enters the cave.\n");
  move_object(TP,PATH+"rocks2.c");
  command("look",TP);
  say(TPN+" enters the cave.\n");
  return 1;
}

query_coords() { return ({ 2,8 }); }
