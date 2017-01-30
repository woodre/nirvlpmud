#include "/players/pavlik/closed/colors.h"
#define EN environment(this_object())

int y, count;

/* the owner of this spell */
object owner;

/* the target of the spell */
object target;

reset(arg){
 if(arg)
   return;
  count=0;
  y = random(3);
}

short(){ return; }
long(){ write("phantasmagoria.\n"); return; }
id(str){ return str == "phantasmagoria"; }
get(){ return 0; }
drop(){ return 1; }

set_owner(ob){ owner = ob; }
query_owner(){ return owner; }
set_target(ob){ target = ob; }
query_target(){ return target; }

do_casting() {
  if(!valid()) {
    destruct(this_object());
    return 1;
  }
}


valid() {
  object obj;
  int x;
  x = time();
  if(!owner) return 0;
  obj = present("mageobj", owner);
  if(!obj) return 0;
  if(!target) {
    obj->set_next_dmg(x);
    obj->set_next_prot(x);
    obj->set_next_heal(x);
    obj->set_next_altr(x);
    return 0;
  }
  if(!owner->query_attack() == target) {
    obj->set_next_dmg(x);
    obj->set_next_prot(x); 
    obj->set_next_heal(x);
    obj->set_next_altr(x + 180); 
    return 0;  
  }
  return 1;
}

