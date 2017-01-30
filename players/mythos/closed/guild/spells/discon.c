#include "/players/mythos/closed/guild/def.h"
inherit "obj/treasure";
object ob,ob2;
reset(arg) {
  if(arg) return;
    set_id("shadowcon");
    set_short();
    set_weight(0);
    set_value(0);
}

 init() {
   ::init();
   add_action("shadow","shadow_me");
   add_action("soff","doff");
   }
   
shadow() {
ob=clone_object("/players/mythos/closed/guild/spells/distr.c");
ob->set_owner(this_player()->query_real_name());
ob->set_num(qtf);
ob2 = ob;
move_object(ob,environment(this_player()));
return 1;}

soff() {
destruct(ob2);
destruct(this_object());
write("Shadow is gone.\n");
return 1;}

drop() { return 1;}
get() { return 0;}
