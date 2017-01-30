#include "/players/pavlik/guild/mages/defs.h"

#define TARGET capitalize(target->query_name())
#define LS HIW+"Life"+NORM+HIBLK+"Steal"+NORM

#define CONDUIT_MAX		10	/* (30 seconds) */
#define POST_CONDUIT_MAX	3	/* (9  seconds) */
#define SPELL_COST		12

object owner;
object target;
int conduit;
int post_conduit;
int count;

reset(arg){
  if(arg) return;
  owner = 0;
  target = 0;
  conduit = 1;
  post_conduit = 0;
  count = 0;
  set_heart_beat(1);
  call_out("gone", 120);	/* safeguard */
}

short()
{ 
  if(conduit > 0) return HIW+"An arcing conduit of energy"+NORM;
  else return;
}

long()
{
  if(conduit > 0) write("An crackling conduit of energy arcs between "+ME+" and "+TARGET+"!\n");
  return;
}

id(str)
{
  if(!owner) return str == "conduit" || str == "life_steal";
  else return str == "conduit" || str == "life_steal" || str == OWN+"'s conduit";
}

get(){ return 0; }
drop(){ return 1; }

query_owner(){ return owner; }
set_owner(ob){ owner = ob; }

query_target(){ return target; }
set_target(ob){ target = ob; }

query_conduit(){ return conduit; }

init()
{
#ifndef __LDMUD__
  add_action("do_nothing"); add_xverb("");
#else
  add_action("do_nothing", "", 3);
#endif
}

/*
 * Spellcaster is "immobilized" briefly when the spell finishes
 * (note: wizards get the write msg but fall through to allow commands)
 */
do_nothing(str)
{
  if(post_conduit)
  {
	write(HIW+"Your entire body is numb - "+NORM+HIY+"You can't do anything!\n"+NORM);
	say(ME+" twitches slightly.\n");
	if(tp && tp->query_level() < WIZLEVEL)
	{
		return 1;
	}
  }
}


heart_beat()
{
  int amount;
  int msg;
  int chance;
  int num;

  if(!owner || !environment(owner))
  {
	destruct(this_object());
	return 1;
  }

  /* keep this object at the "top" of the owners inventory */
  move_object(this_object(), owner);

  if(conduit && (!target || !present(target, environment(owner))) )
  {
	tell_object(owner, SPELL_PROMPT+" Your "+LS+" spell comes to an end.\n");
	end_conduit();
	return 1;
  }

  if(conduit && (!owner->query_attack() || owner->query_attack() != target) )
  {
	tell_object(owner, SPELL_PROMPT+" Your "+LS+" spell comes to an end.\n");
	end_conduit();
	return 1;
  }

  /* this is never supposed to happen */
  if(!present("mageobj", owner))
  {
	end_conduit();
	return 1;
  }

  /*
   * post-effects
   */
  if(post_conduit)
  {
	if(post_conduit > POST_CONDUIT_MAX)
	{
		recover();
		return 1;
	}
	post_conduit++;
	return 1;
  }

  /* end the spell if we run out of spell points */
  if(conduit && owner->query_sp() < -10)
  {
	tell_object(owner,
	  SPELL_PROMPT+" You have become "+HIM+"too tired"+NORM+" to maintain the "+LS+" spell."+NORM+"\n");
	end_conduit();
	return 1;
  }

  /* end the spell after max repetitions */
  if(count > CONDUIT_MAX)
  {
	if(owner->query_level() > WIZLEVEL)
		tell_object(owner, "Lifesteal: maxiumum repititions reached.\n");
	end_conduit();
	return 1;
  }

  msg = random(4);
  if(msg == 0)
	tell_room(environment(owner),
	"The arcing conduit between "+OWN+" and "+TARGET+" "+HIY+"crackles loudly"+NORM+".\n");
  else if(msg == 1)
	tell_room(environment(owner),
	"A "+HIW+"blazing conduit of energy"+NORM+" showers you with "+HIY+"sparks"+NORM+".\n");
  else if(msg == 2)
	tell_room(environment(owner),
	"Jagged "+HIY+"bolts of magical energy"+NORM+" flash between "+OWN+" and "+TARGET+".\n");
  else
	tell_room(environment(owner),
	"A "+HIW+"conduit of energy"+NORM+" "+MAG+"sizzles"+NORM+" between "+OWN+" and "+TARGET+".\n");

  /*
   * Chance is based on the target's level.
   * Figure the average monster these players are going after is between 17-19
   * so num will be around 136-152.
   */
  chance = target->query_level() * 8;
  if(chance > 168) chance = 168;
  num = random(chance);

  /*
   * if the random chance is in top 3-4% then amazing things can happen,
   * none of which are good for the spell caster...
   */
  if(num >= (chance - chance/27))
  {
	tell_room(environment(owner),
	  "\n"+
	  "The "+HIY+"magical conduit"+NORM+" "+HIR+"RUPTURES"+NORM+" and "+OWN+" is struck by a powerful backlash of energy!\n"+
	  "A deafening "+HIR+"concussion blast"+NORM+" pounds through your skull and shakes the ground beneath your feet!\n"+
	  "\n");
	owner->heal_self(-random(100));
	target->heal_self(random(100));
	end_conduit(1);
	return 1;
  }

  /* if fail check then target sucks owners hit points */
  if(num > present("mageobj", owner)->query_total_guild_stat("necromancy"))
  {
	tell_object(owner,
	  TARGET+" "+HIR+"reverses"+NORM+" the flow of the "+LS+" spell!\n" +
	  TARGET+" "+HIG+"steals"+NORM+" your life force through the conduit!\n");
	tell_room(environment(owner),
	  TARGET+" "+HIR+"reverses"+NORM+" the flow and "+HIR+"sucks"+NORM+" away "+OWN+"'s life!\n",
	  ({owner}));

	amount = 33 - random(present("mageobj", owner)->query_total_guild_stat("necromancy")/3);
	if(amount > 33) amount = 33;
	if(amount < 5) amount = 5;
	owner->add_hit_point(-amount);
	target->add_hit_point(amount);

	if(owner->query_level() > WIZLEVEL)
		tell_object(owner, HIR+"[Lifesteal: "+amount+"]\n"+NORM);
  }
  /* else the owner sucks hit points of target */
  else
  {
	tell_object(owner,
	  SPELL_PROMPT+" You "+HIG+"steal"+NORM+" "+TARGET+"'s "+HIW+"life force"+NORM+" through the conduit!\n");
	tell_room(environment(owner),
	  OWN+" "+HIG+"steals"+NORM+" "+TARGET+"'s "+HIW+"life force"+NORM+" through the conduit!\n",
	  ({owner}));

	amount = random(present("mageobj", owner)->query_total_guild_stat("necromancy") / 3);
	if(amount > 24) amount = 24;
	if(amount < 5) amount = 5;
	owner->set_spell_dam(amount);
	owner->set_spell_dtype("other|mental");
	owner->add_hit_point((amount * 2) / 3);

	if(owner->query_level() >= WIZLEVEL)
		tell_object(owner, HIR+"[Lifesteal: dmg: "+amount+"   heal: "+(amount*2/3)+"]\n"+NORM);
  }

  owner->add_spell_point(-SPELL_COST);
  count++;
  return 1;

}


end_conduit(silent)
{
  if(!owner)
  {
	destruct(this_object());
	return 1;
  }

  if(!silent)
  {
	tell_object(owner,
	  "The crackling "+HIW+"conduit of energy"+NORM+" "+HIC+"disappears"+NORM+" in a "+
	  HIY+"brilliant flash"+NORM+"!\n");
	tell_room(environment(owner),
	  "The crackling "+HIW+"conduit of energy"+NORM+" "+HIC+"disappears"+NORM+" in a "+
	  HIY+"brilliant flash"+NORM+"!\n",
	  ({owner}));
  }
  tell_object(owner,
    "\n" +
    SPELL_PROMPT+" You "+HIG+"slump"+NORM+" to the ground, "+HIR+"exhausted"+NORM+" by the effort.\n"+
    "\n");
  tell_room(environment(owner),
    OWN+" "+HIG+"slumps"+NORM+" to the ground, "+HIR+"exhuasted"+NORM+" by the effort.\n",
    ({owner}));
  conduit = 0;
  post_conduit = 1;
  return 1;
}


recover()
{
  object ob;

  if(owner)
  {
	tell_object(owner,
	  "\n"+
	  HIW+"The numbness leaves your body and you are "+NORM+MAG+"able to move"+NORM+HIW+" once again.\n"+NORM+
	  "\n");
  }

  if(ob = present("mageobj", owner))
  {
	ob->remove_spell_object("lifesteal");
	ob->set_casting(0);
  }

  conduit = 0;
  post_conduit = 0;
  destruct(this_object());
  return 1;
}


/*
 * This function assures us that the object will not get stuck and
 * leave the player forever helpless.  It is a bit redundant but
 * its a good safeguard to have in place.
 */
gone()
{
  object ob;

  if(owner)
	tell_object(owner, "\n"+HIW+"You recover from the Life Steal spell.\n\n"+NORM);

  if(ob = present("mageobj", owner))
  {
	ob->remove_spell_object("lifesteal");
	ob->set_casting(0);
  }

  conduit = 0;
  post_conduit = 0;
  destruct(this_object());
  return 1;
}

