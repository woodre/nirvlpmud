#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"

#define MAX_I_DAMAGE		50
#define NF			GRN+"noxious "+YEL+"fumes"+NORM

object owner;			/* our owner */
int total_damage;		/* how much total damage we can do */
int hbs;			/* how many heart_beats we've been around */
object *targets;		/* objects we are doing damage to */

reset(arg)
{
  if(arg) return;
  owner = 0;
  total_damage = 0;
  hbs = 0;
  targets = ({});
  set_heart_beat(1);
}

id(str)
{
  return str == "cloud" || str == "fumes" || str == "cloudkill" || str == "cloud kill";
}

short()
{
  return YEL+"~"+GRN+"* "+YEL+"~"+GRN+"*"+NORM+
	  " A cloud of "+YEL+"noxious "+GRN+"fumes"+NORM+" fills the air "+
	  GRN+"*"+YEL+"~ "+GRN+"*"+YEL+"~"+NORM;
}

long()
{
  write(short()+".\n");
  if(this_player() && this_player()->query_level() > 20)
  {
	write("wiz notice: This is a "+CYN+"Mages's"+NORM+" Cloudkill spell.\n");

  }
  return;
}

query_value(){ return 0; }
get(){ return 0; }
drop(){ return 1; }

set_owner(ob){ owner = ob; }
query_owner(){ return owner; }

set_total_damage(i)
{
  total_damage = i;
  if(total_damage > CLOUDKILL_MAX_DAMAGE) total_damage = CLOUDKILL_MAX_DAMAGE;
}
query_total_damage(){ return total_damage; }


/*
 * get_targets
 * called every heart_beat to determine who is in the room and how
 * they are affected by the spell.
 */
get_targets()
{
  object ob, obj;
  int target_count;
  int i;

  if(!targets)
	targets = ({});

  /*
   * validate our list of preferred targets
   */
  i = sizeof(targets);
  while(i--)
  {
	if(!targets[i] || !present(targets[i], environment()))
	{
		targets -= ({ targets[i] });
	}
  }

  /* count targets after verification */
  target_count = sizeof(targets);

  /*
   * who we are attacking is automatically put into our preferred targets list
   */
  ob = owner->query_attack();
  if(ob && member_array(ob, targets) == -1)
  {
	if(!present("cloudkill_obj", ob))
	{
		obj = clone_object(OBJ_DIR + "cloudkill_obj");
		move_object(obj, ob);
		obj->set_do_damage(1);
		obj->set_owner(owner);
		if(ob->is_player() && owner->query_attack() != ob)
		{
			tell_room(environment(),
			  capitalize(ob->query_name())+" tries to avoid the "+NF+".\n");
		}
		else
		{
			tell_room(environment(),
			  capitalize(ob->query_name())+" breathes the "+NF+" and gets "+MAG+"sick"+NORM+".\n");
		}
	}
	else
	{
		present("cloudkill_obj", ob)->set_do_damage(1);
	}
	/*
	 * if target list was already full then drop somehing out of it
	 */
	if(target_count >= CLOUDKILL_MAX_TARGETS)
	{
		if(present("cloudkill_obj", targets[target_count-1]))
			present("cloudkill_obj", targets[target_count-1])->set_do_damage(0);
		targets -= ({ targets[target_count-1] });
		target_count--;
	}
	targets += ({ ob });
	target_count++;
  }

  /*
   * walk through all the objects in the room
   * up to (5) NPCs that are not kids or pets are put into the target list
   * everything else is given an object that does no damage, but does stop them
   * from physical combat attacks. (except players)
   */
  ob = all_inventory(environment());
  i = sizeof(ob);
  while(i--)
  {
	if(!ob[i] || !objectp(ob[i]))
		continue;

	if(!living(ob[i]))
		continue;

	if(ob[i] == owner)
		continue;

	if(present("cloudkill_obj", ob[i]))
		continue;

	obj = clone_object(OBJ_DIR + "cloudkill_obj");
	move_object(obj, ob[i]);
	obj->set_owner(owner);

	if(ob[i]->is_player() && owner->query_attack() != ob[i])
	{
		tell_room(environment(),
		  capitalize(ob[i]->query_name())+" tries to avoid the "+NF+".\n");
	}
	else
	{
		tell_room(environment(),
		  capitalize(ob[i]->query_name())+" breathes the "+NF+" and gets "+MAG+"sick"+NORM+".\n");
	}

	if(ob[i]->is_npc() && !ob[i]->is_pet() && !ob[i]->is_kid() && !ob[i]->query_owner())
	{
		if(target_count < CLOUDKILL_MAX_TARGETS)
		{
			targets += ({ ob[i] });
			target_count++;
			obj->set_do_damage(1);
			if(ob[i] && objectp(ob[i]) && !ob[i]->query_attack())
			{
				ob[i]->attack_object(owner);
			}
		}
		else
			obj->set_do_damage(0);
	}
	else
	{
		/* we are a player, pet or kid ... dont do damage */
		obj->set_do_damage(0);
	}
  }
}


end_spell()
{
  object ob;
  int i;

  if(!environment())
  {
	destruct(this_object());
	return 1;
  }

  tell_room(environment(),
    "\n"+
    HIY+"~"+HIB+"*"+NORM+
    " The "+NF+" dissipate and the air "+HIW+"clears"+NORM+". "+
    HIB+"*"+HIY+"~\n\n"+NORM);

  ob = all_inventory(environment());
  i = sizeof(ob);
  while(i--)
  {
	if(present("cloudkill_obj", ob[i]))
		destruct(present("cloudkill_obj", ob[i]));
  }

  destruct(this_object());
  return 1;
}


heart_beat()
{
  object ob;
  int i;
  int i_dmg;
  int dmg;

  if(!owner || !environment())
  {
	end_spell();
	return 1;
  }

  /* halve the total damage if the caster has left or is not in combat */
  if(!present(owner, environment()) || !owner->query_attack())
  {
	total_damage = total_damage / 2;
  }

  /*
   * Get or update list of targets
   * this is the list of objects we are actually doing damage to
   */
  get_targets();

  if(!targets || !sizeof(targets))
  {
	end_spell();
	return 1;
  }

  /*
   * possible damage per target
   * (dependant on the number of damagable targets)
   */
  i_dmg = 100 / sizeof(targets);
  if(i_dmg > MAX_I_DAMAGE) i_dmg = MAX_I_DAMAGE;

  /*
   * Go through all objects in room and see who gets affected
   */
  ob = all_inventory(environment());
  i = sizeof(ob);
  while(i--)
  {
	if(present("cloudkill_obj", ob[i]))
	{
		/*
		 * it takes a round to get poisoned before we can take any damage
		 */
		if(!(present("cloudkill_obj", ob[i])->query_poisoned()))
		{
			present("cloudkill_obj", ob[i])->set_poisoned(1);
			continue;
		}
		else if(present("cloudkill_obj", ob[i])->query_do_damage())
		{
			if(total_damage >= i_dmg)
			{
				dmg = 1 + random(i_dmg);
				total_damage -= i_dmg;
			}
			else if(total_damage > 0)
			{
				dmg = 1 + random(total_damage);
				total_damage = 0;
			}
			else
			{
				dmg = 0;
				total_damage = 0;
			}
			if(dmg > 0)
			{
				if(owner->query_level() > WIZLEVEL)
					tell_object(owner, "cloudkill: "+ob[i]->query_name()+" damage: "+dmg+".\n");
				ob[i]->do_damage(({dmg}), ({"other|poison"}));
			}
		}
	}
  }

  /* Once the damage amount has dropped below the minimum then just end the spell */
  if(total_damage <= 0)
  {
	if(owner->query_level() > WIZLEVEL)
		tell_object(owner, "cloudkill: total_damage now 0, ending spell.\n");
	end_spell();
	return 1;
  }

  /* Don't exceed maximum number of heart_beats */
  hbs++;
  if(hbs >= CLOUDKILL_MAX_HBS)
  {
	if(owner->query_level() > WIZLEVEL)
		tell_object(owner, "cloudkill: max hbs reached, ending spell.\n");
	end_spell();
	return 1;
  }

  if(owner->query_level() > WIZLEVEL)
	tell_object(owner, GRN+"cloudkill"+NORM+": total_damage="+total_damage+"   hbs="+hbs+"\n");

  return 1;

}

