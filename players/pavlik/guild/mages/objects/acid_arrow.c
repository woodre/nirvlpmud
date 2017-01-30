#include "/players/pavlik/guild/mages/defs.h"

#define TARGET capitalize(target->query_name())
#define MAX_REPS	6

object target;
object owner;
int acid_count;
int acid_damage;

reset(arg){
  if(arg) return;
  target = 0;
  owner = 0;
  acid_count = 0;
  acid_damage = 0;
  set_heart_beat(1);
}

short(){ return; }
long(){ write("a mages acid arrow.\n"); return; }
id(str){ return str == "acid arrow" || str == "acid_arrow"; }
get(){ return 0; }
drop(){ return 1; }

set_owner(ob){ owner = ob; }
query_owner(){ return owner; }

set_target(ob){ target = ob; }
query_target(){ return target; }

set_acid_count(i){ acid_count = i; }
query_acid_count(){ return acid_count; }

set_acid_damage(i){ acid_damage = i; }
query_acid_damage(){ return acid_damage; }


heart_beat()
{
  if(!environment() || !target || environment() != target)
	return destruct(this_object());

  if(!environment(target))
	return destruct(this_object());

  acid_count++;

  if(!owner || owner->query_attack() != target)
	acid_count = MAX_REPS;

  if(acid_damage <= 1)
	acid_count = MAX_REPS;

  if(acid_count >= MAX_REPS)
  {
	tell_room(environment(target),
	  "The "+CYN+"last"+NORM+" of the "+HIBLK+"deadly "+NORM+GRN+"acid"+NORM+" disolves from "+TARGET+"'s skin.\n");
	destruct(this_object());
	return 1;
  }
  else
  {
	tell_room(environment(target),
	  SPELL_PROMPT+" The "+HIBLK+"deadly "+NORM+GRN+"acid"+NORM+" covering "+TARGET+"'s skin " +
	  "continues to "+MAG+"sizzle"+NORM+" and "+RED+"burn"+NORM+".\n");

	if(owner->query_level() > WIZLEVEL)
		tell_object(owner, "[Acid Damage: "+acid_damage+"]\n"); 
	
	target->do_damage(({acid_damage}), ({"other|poison"}));
	acid_damage = acid_damage / 2;
  }
  return 1;
}

