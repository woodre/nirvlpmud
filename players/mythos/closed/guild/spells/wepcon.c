#include "/players/mythos/closed/guild/def.h"
inherit "obj/treasure";
object ob, con;
reset(arg) {
  if(arg) return;
    set_id("control");
    set_short("Dancing Weapon Control");
    set_long("To make the weapon revert to normal type 'revert'\n");
    set_weight(0);
    set_value(0);
}
 init() {
   ::init();
   add_action("revert","revert");
   }
   
drop() { return 1;}
get() { return 0;}

set_con(ob) { con = ob; }

revert() { write("You make the dancing weapon revert.\n");
           con->norm(); 
return 1;}
