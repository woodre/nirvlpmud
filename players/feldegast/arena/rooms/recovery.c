#include "/players/feldegast/log/logs.h"
#include "/players/feldegast/defines.h"
inherit ROOM;

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="Recovery Room";
  long_desc=
"This is the coliseum's recovery room.  Type 'regenerate' to recover from a\n"+
"ghostly state.  To the east is a staircase leading back up to the coliseum.\n";
  dest_dir=({
    "/players/feldegast/arena/rooms/foyer","up"
  });
}
init(arg) {
  ::init();
  add_action("regenerate","regenerate");
  add_action("logme","logme");
}
regenerate() {
  return this_player()->remove_ghost();
}
query_no_fight() {
  return 1;
}
logme() {
#ifdef SPAR_LOG
  write_file(SPAR_LOG,ctime(time())+" "+capitalize(this_player()->query_real_name())+" died in the sparring arena.\n");
#endif
  return 1;
}
