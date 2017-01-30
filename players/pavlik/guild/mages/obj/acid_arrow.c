#include <ansi.h>
#define IT capitalize(target->query_name())
#define env environment(this_object())

object owner;
object target;
int count;

reset(arg) {
  if(arg) return;
  count = 0;
}

id(str){ return str == "acid_arrow"; }
get(){ return 0; }
drop(){ return 1; }
query_value(){ return 0; }
query_weight(){ return 0; }

set_owner(ob){ owner = ob; }

do_acid(obj) {
  target = obj;
  call_out("do_acid1", 6);
  return 1;
}

do_acid1() {
  int amt;

  if(count > 1) {
    destruct(this_object());
    return 1;
  }

  if(!target || env != target) {
    destruct(this_object());
    return 1;
  }

  if(!owner || owner->query_attack() != target) {
    destruct(this_object());
    return 1;
  }

  if(random(4) < 2)
    tell_room(environment(env),
    GRN+"Toxic acid"+NORM+" burns "+IT+"'s skin.\n");
  else
    tell_room(environment(env),
    IT+"'s flesh sizzles and pops as the "+GRN+"acid"+NORM+
    " burns it away.\n");

  amt = present("mageobj", owner)->query_total_conj();
  amt = random(amt/5);
  owner->set_spell_dam(amt * 3);
  owner->set_spell_dtype("other|poison");

  count++;
  call_out("do_acid1", 6);
  return 1;
}


