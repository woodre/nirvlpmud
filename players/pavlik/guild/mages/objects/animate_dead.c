#include "/players/pavlik/guild/mages/defs.h"
inherit "/obj/monster";

object owner;
int ttl;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Skeleton");
  set_alias("skelton");
  set_race("animated corpse");
  set_alt_name("bones");
  set_short("A Pile of Bones *animated*");
  set_long("An old pile of bones that has been brought back to 'life'.\n");
  set_ep(0);
  set_alias("skeleton");
  set_can_kill(1);
  set_heart_beat(1);
  set_ac(0);
  set_wc(0);
  set_hp(180);
  owner = 0;
  ttl = 0;
  enable_commands();
  set_dead_ob(this_object());
  set_message_hit(({
	HIK+"ANNIHILATED"+NORM, " with powers of "+HIK+"UnDeath"+NORM,
	HIK+"destroyed"+NORM, " relentlessly",
	HIK+"savagely tortured"+NORM, " with a quick flurry of blows",
	HIK+"grasped"+NORM, ", draining "+HIM+"life-force"+NORM,
	HIK+"beat"+NORM, " hard",
	"knocked", " off-balance",
	"tapped", " lightly",
  }));
  if(!present("party object", this_object()))
	move_object(clone_object(OBJ_DIR + "fake_party"), this_object());
}

int id(string str)
{
  return (::id(str)||str=="pile"||str=="animated_corpse");
}

set_owner(ob){ owner = ob; }
query_owner(){ return owner; }

set_ttl(i){ ttl = i; }
query_ttl(){ return ttl; }

/*
 * experience awarded to this object is passed on
 * to the spell caster
 */
add_exp(i)
{
  if(i > 0 && owner)
	owner->add_exp(i);
}

heart_beat()
{
  object ob;

  ::heart_beat();

  ttl--;

  if(!owner || !ttl)
  {
	gone();
	return 1;
  }

  if(!environment() || !environment(owner))
	return 1;

  if(!present(owner, environment()))
  {
	tell_room(environment(), query_name()+" shuffles away.\n");
	move_object(this_object(), environment(owner));
	tell_room(environment(), query_name()+" shuffles in.\n");
  }

  if(query_attack() && present(query_attack(), environment()))
	return 1;

  if(ob = owner->query_attack())
  {
	if(ob->is_npc() || environment()->query_arena() || ob->query_pl_k() > 1)
	{
		ob->set_can_kill(1);
		attack_object(ob);
	}
  }

}

gone()
{
  if(environment())
	tell_room(environment(this_object()),
	  this_object()->short()+" suddenly stops moving.\n"+
	  "The skeleton "+CYN+"falls"+NORM+" to the ground and "+RED+"shatters into tiny pieces"+NORM+".\n");
  destruct(this_object());
  return 1;
}

monster_died()
{
  if(environment())
	tell_room(environment(this_object()),
	  this_object()->short()+" "+HIR+"shatters"+NORM+" into tiny pieces.\n");
  destruct(present("corpse", environment(this_object())));
  return 0;
}
 
