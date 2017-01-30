inherit "obj/treasure";
#include "/players/maledicta/ansi.h"

reset (arg) {
if(!arg){
  set_id("mark");
  set_alias("chalk_markings");
  set_short("a "+HIR+"C"+NORM+BLU+"o"+HIY+"l"+NORM+YEL+"o"+HIB+"r"+NORM+RED+"e"+HIM+"d"+NORM+" mark");
  set_long(
  "It looks as though someone has marked this area with chalk.\n");
  set_weight(10000);
  set_value(0);
  call_out("destroy_it", 1200);
    }
  }

destroy_it(){
if(!environment()) return;
tell_room(environment(this_object()),
"The marking disappears...\n");
destme();
}

destme(){
  destruct(this_object());
}
