#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc="The Viewing Gallery";
  long_desc=
    "Arriving just in time for the best seat in the coliseum, a panoramic\n"+
    "view of the combat arena lays out before you.  Oval in shape, it has\n"+
    "been divided into several smaller, circular fighting pits.  A tall\n"+
    "standard pole shows the colors of each pair of gladiators, and flies\n"+
    "a red flag if the combat is to the death.  All the flags in the arena\n"+
    "are red today.  To watch a matched pair of gladiators during battle,\n"+
    "use the command (blagh) (blagh).\n";
  items=({
  });
  dest_dir=({
    PATH+"room1.c","down",
  });
}

void init() {
  ::init();
  add_action("cmd_watch","watch");
}

void exit() {
  if(TP && interactive(TP))
    MASTER->remove_watcher(TP);
}
int cmd_watch(string str) {
  MASTER->cmd_who(str);
  return 1;
}
