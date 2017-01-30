/* Based on Feld's arena */
#include "/players/pestilence/define.h"
inherit ROOM;

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc=""+HIK+"MORGUE"+NORM+"";
  long_desc=
"This is the morgue.  When someone dies in the arena, this is where their body\n"+
"is brought to.  Then it is healed back into a living state.  The exit upwards\n"+
"leads back to the entry way to the arena.\n";
  dest_dir=({
    "/players/pestilence/arena/room/entry.c","up"
  });
}
init(arg) {
  ::init();
  add_action("regenerate","resurect");
}
regenerate() {
  return this_player()->remove_ghost();
}
query_no_fight() {
  return 1;
}

