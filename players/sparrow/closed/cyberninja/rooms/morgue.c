inherit "room/room";
/* Based on Feld's arena */
#include "../DEFS.h"

reset(arg) {
  if(arg) return;

  set_light(1);
short_desc="CyberNetic Revival Chamber";
  long_desc=
"When someone dies in the arena, the CyberDaemon brings thier body here\n"+
"and it is healed back into a living state.  The exit 'surface'\n"+
"leads back to the entry way to the arena.\n";
  dest_dir=({
"/players/dune/closed/guild/rooms/hallway3.c","surface"
  });
}
init(arg) {
  ::init();
add_action("regenerate","surface");
}
enter() {
call_other(TP, "set_home", "/players/dune/closed/guild/rooms/morgue.c");
TP->save_me();
}
regenerate() {
  return this_player()->remove_ghost();
}
query_no_fight() {
  return 1;
}

exit() {
    object pfix;
call_other(TP, "set_home", LOGIN);
TP->save_me();
    while (pfix = present("CYBER_HEAL_ID",this_player())) destruct(pfix);
}

quit(str) {
write("You may not quit from this location.\n");
return 1;
}
