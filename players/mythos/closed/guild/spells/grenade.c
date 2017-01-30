#include "/players/mythos/closed/ansi.h"
#define epp   environment(environment(this_object()))
inherit "obj/treasure";

reset(arg) {
  if(arg) return;
    set_id("grenade");
    set_weight(0);
    set_value(0);
    call_out("check",3);
}

drop() { return 1;}
get() { return 0;}

check() {
if(epp) {
  if(!living(epp)) {
  call_out("bomb",10); 
  return 1;} }
call_out("check",3);
return 1;}

bomb() {
int bo;
object ob;
if(epp) {
  ob = all_inventory(epp);
  tell_room(epp,HIR+"\n             >>> >>  *  <<  <<<\n"+NORM+
            "You hear a great explosion as "+environment(this_object())->short()+
            " explodes like a grenade!\n");
  for(bo=0; bo<sizeof(ob); bo++) {
    if(living(ob[bo]) && ob[bo]->query_npc()) {
    ob[bo]->heal_self(-random(10));
    }
    }
destruct(environment(this_object()));
destruct(this_object()); }
return 1;}
