#include "defs.h"

inherit ROOM;

int knifeguy;

void reset(int arg) {
  if(!present("tricky"))
    knifeguy=0;
  if(!present("xexia"))
    move_object(clone_object(MON_PATH+"brigand6.c"),this_object());
  if(arg) return;
  set_light(1);
  short_desc="Brigand Cave";
  long_desc=
"  Blankets and sheets are strewn about this cave, which serves as\n"+
"the brigands' sleeping chamber.  A guttering torch, which provides\n"+
"the only light, is wedged between two rocks.  A hammock is strung\n"+
"up high.  A passageway to the north leads deeper into the caves,\n"+
"while a crevice to the west leads into an alcove.\n";
  items=({
    "blankets","Worn cotton blanks littered with crumbs",
    "sheets","The sheets are made of silk.  Probably looted from a caravan",
    "torch","A simple wooden torch wedged between two rocks",
    "rocks","Rocks are strewn about the cave",
    "passageway","It seems to lead deeper into the cave",
    "crevice","It leads into an alcove",
    "alcove","You think you see some light in there",
    "hammock","The hammock is tied up high where you can't reach it",
  });
  dest_dir=({
    PATH+"rocks5.c","north",
    PATH+"rocks4.c","west",
    PATH+"rocks2.c","south",
  });
}

void init() {
  ::init();
  add_action("cmd_north","north");
  add_action("cmd_west","west");
}

int cmd_west(string str) {
  object brig;
  brig=present("brigand");
  if(brig) {
    tell_room(this_object(),(string)brig->query_name()+" says: Where do you think YOU'RE going?\n");
    brig->attack_object(TP);
    return 1;
  }
}

int cmd_north(string str) {
  object brig;
  brig=present("brigand");
  if(!brig && !knifeguy) {
    brig=clone_object(MON_PATH+"brigand7.c");
    move_object(brig,this_object());
    tell_room(this_object(),
      "Somebody deftly rolls out of the hammock and lands before you.\n"+
      "Tricky says: Tricky wants to know where you think YOU'RE going!\n");
    knifeguy=1;
    return 1;
  }
  if(brig) {
    tell_room(this_object(),(string)brig->query_name()+" says: Where do you think YOU'RE going?\n");
    brig->attack_object(TP);
    return 1;
  }
}
  