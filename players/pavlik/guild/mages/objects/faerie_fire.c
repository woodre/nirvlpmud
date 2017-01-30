#include "/players/pavlik/closed/colors.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"

#define EN environment(this_object())

/* count until the spell expires */
int expire;
int count;

/* the owner of this spell */
object owner;

reset(arg){
  if(arg) return;
  expire=8;
  count=0;
}

id(str){
  return str == "faerie_fire" || str == "mage_alteration";
}

short(){ return; }
long(){ write("A Mages Faerie Fire.\n"); return; }
get(){ return 0; }
drop(){ return 1; }
query_expire(){ return expire; }
query_count(){ return count; }

extra_look()
{
  return capitalize(EN->query_name())+" is surrounded by a brightly "+
   "glowing "+HIY+"faerie fire"+NORM+"!";
}

/*
 * Set up the spell and start the call_outs
 */
do_spell(ob)
{
  int amount;
  owner = ob;

  amount = FFIRE_AC_REDUCTION;
  if(amount > FFIRE_MAX_REDUCTION) amount = FFIRE_MAX_REDUCTION;

  EN->RegisterArmor(this_object(), ({"physical", -amount, 0, 0 }));
  expire = expire + present("mageobj", owner)->query_total_power() / 8;
  call_out("exe_spell", 4);
  return 1;
}


/*
 * Continuing call outs for the spells
 */
exe_spell()
{
  int i;

  /* if the target is gone dest this */
  if(!EN || !living(EN))
  {
	if(owner && present("mageobj", owner))
		present("mageobj", owner)->remove_spell_object("ffire");
	destruct(this_object());
	return 1;
  }

  /* if the owner isn't here any more end this spell */
  if(!owner || !present(owner, environment(EN)))
	count = expire + 1;

  if(owner->query_attack() != EN)
	count = expire + 1;

  /* is it time for spell to end? */
  if(count > expire)
  {
	tell_room(environment(EN),
	 ">>> The "+HIY+"faerie"+NORM+" "+HIR+"fire"+NORM+" surrounding "+capitalize(EN->query_name())+" "+HIBLK+"dims"+NORM+" and "+HIM+"vanishes"+NORM+".\n");
	if(owner && present("mageobj", owner))
		present("mageobj", owner)->remove_spell_object("ffire");
	destruct(this_object());
	return 1;
  }

  i = random(5);

  if(i == 0)
	tell_room(environment(EN),
	 "The "+HIY+"faerie"+NORM+" "+HIR+"fire"+NORM+" surrounding "+capitalize(EN->query_name())+HIY+" glows brightly"+NORM+".\n");
  else if(i == 3)
	tell_room(environment(EN),
	 "The "+HIY+"faerie"+NORM+" "+HIR+"fire"+NORM+" makes "+capitalize(EN->query_name())+" an easy target!\n");

  count++;
  call_out("exe_spell", 4);
  return 1;

}

remove_object()
{
  if(owner && present("mageobj", owner))
	present("mageobj", owner)->remove_spell_object("ffire");
  if(environment())
	environment()->RemoveArmor(this_object());
}
