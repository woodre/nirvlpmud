#include "/players/pavlik/closed/colors.h"
#define IT capitalize(target->query_name())
#define ME capitalize(owner->query_name())

/*
 * See file: /players/pavlik/mages/spells/curse
 * for details of this object.
 */

object target;
object owner;
int wc_reduce;
int ac_reduce;
int rate_change;
int interval_change;
int count;
int org_rate;
int org_interval;

reset(arg){
 if(arg||root()) return;
 call_out("curse_emote", 6);
 call_out("curse_check", 10);
}

short(){ return; }
long(){ write("a mages curse.\n"); return; }
id(str){ return str == "curse" || str=="generic_wc_object"; }
get(){ return 0; }
drop(){ return 1; }
extra_look(){ return IT+" is "+HIR+"CURSED"+NORM+"!"; }

set_owner(ob){ owner = ob; }
query_owner(){ return owner; }
set_target(ob){ target = ob; }


int gen_wc_bonus()
{
  return -wc_reduce;
}

do_wc_reduce(amt) {
  int target_wc,min_wc;
  wc_reduce = amt;

  if(owner->query_level() > 20)
    tell_object(owner, "Weapon Class reduction: "+wc_reduce+"\n");

  return 1;
}

do_ac_reduce(amt) {
  int target_ac,min_ac;

  ac_reduce = amt;
  
  environment()->RegisterArmor(this_object(),
    ({"physical", -ac_reduce, 0, 0 }));

  if(owner->query_level() > 20)
    tell_object(owner, "Armor Class reduction: "+ac_reduce+"\n");

  return 1;
}

do_heal_change(rate, inv) {
  if(!target) return;
  org_rate = target->query_heal_rate();
  org_interval = target->query_heal_intv();
  target->set_heal_rate(rate, inv);
  if(owner->query_level() > 20)
    tell_object(owner, "New heal rate is: "+rate+" / "+inv+"\n");
  return 1;
}

curse_check() {

  if(!target) {
    destruct(this_object());
    return 1;
  }

  if(!owner || !present(owner, environment(target))) {
    count++;
  }

  if(!present(owner, environment(target))->query_attack() == target) {
    count++;
  }

  if(count >= 5) {
    restore_all_stats();
    destruct(this_object());
    return 1;
  }

  /* if valid check then reset counter */
  count = 0;

  call_out("curse_check", 10);
  return 1;
}

restore_all_stats() {
  target->set_heal_rate(org_rate,org_interval);
  target->RemoveArmor(this_object());
  return 1;
}

curse_emote() {
  tell_room(environment(target),
  "\n"+
  ME+" completes an evil "+HIG+"Curse"+NORM+" on "+IT+"'s soul!\n"+
  "A dark "+MAG+"cloud of despair"+NORM+" descends on "+IT+"!\n\n");
  return 1;
}
