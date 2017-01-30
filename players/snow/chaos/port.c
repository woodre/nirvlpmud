/* Setup room for ChAoS realm */

#include "std.h"
#include "/players/snow/chaos/defs.h"

short() { return "The portal to ChAoS"; }
long(str) {
  write(
"This is the portal to a realm called ChAoS.\n\
ChAoS is a living, breathing entity that spawns dangerous monsters\n\
as a bodily defense mechanism. It is a dangerous place.\n\
If you want to enter, 'meander' in. If you wish to leave this\n\
room, then 'floataway'.\n\
To learn how to do things in ChAoS, type 'chaos'\n");
}

realm() { return "NT"; }

reset(arg) {
  if(arg) return;
}

init() {
  set_light(1);
  add_action("chaos_cmds","chaos");
  add_action("meander_move","meander");
  add_action("float_out","floataway");
}
 
float_out() {
  write("You float away from the realm of ChAoS!\n");
  TR("/players/snow/gate.c",TPN+" floats into the room.\n");
  MO(TP,"/players/snow/gate.c"); command("look",TP);
  return 1;  }

chaos_cmds(str) { BASE->chaos_cmds(str); RE; }
meander_move() {
  write_file("/players/snow/log/chaos",ctime(time())+" "+
    this_player()->query_real_name()+" entered the ChAoS.\n");
  BASE->chaos_move(); RE; }
