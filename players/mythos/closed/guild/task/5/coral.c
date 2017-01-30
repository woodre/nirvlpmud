#include "/players/mythos/closed/guild/def.h"

id(str) { return str == "coral";}
                 
reset(arg) {
  if(arg) return;
  call_out("checks",400);
}

query_weight() { return 1;}

query_value() { return 0; }

query_save_flag() { return 1; }

drop() { return 0;}
get() { return 1;}

short() { return "A piece of red coral"; }

long() {  write("Something about this coral speaks of danger.\n");
        }
       
init() { 
  add_action("invoke","embrace");
}

checks() {
  if(!ep) return 1;
  tell_object(ep,"The coral disappears.\n");
  destruct(this_object());
return 1;}

invoke() {
  object ob;
  if(pp && tgl == 4 && tl > 8) {
  if(living(ep)) { move_object(this_object(),environment(ep)); }
   ob=clone_object("/players/mythos/amon/forest/ryo3.c");
    ob->set_haunt(tpn);
    move_object(ob,environment(this_object()));
  write("A black aura wafts from the coral!\nDanger seeks you out!\n");
  pp->set_dark_level(5);
  pp->add_sacrifice(1000);
  pp->save_dark();
  pp->update_me();
destruct(this_object()); }

return 1;}
