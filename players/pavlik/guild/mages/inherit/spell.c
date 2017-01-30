#include "/players/pavlik/guild/mages/defs.h"
inherit "/players/pavlik/guild/mages/inherit/tell_damage.c";

string verb;			/* command */
string name;			/* spell name */
string color_name;		/* colorized spell name */
int level;			/* spell level */
int rank;			/* spell rank (for commands */
string school;			/* school of magic */
string stat;			/* primary stat */
int sp_cost;			/* spell point cost */
string cost_string;		/* displayable spell cost */
int delay;			/* casting delay */
string delay_type;		/* what type of delay the spell has */
string type;			/* spell type */
string component_id;		/* spell component id */
string component_string;	/* displayable spell component */
int combat_spell;		/* flag for combat checks */
string descrip;			/* spell description */

void set_verb(string str){ verb = str; }
string query_verb(){ return verb; }

void set_name(string str){ name = str; }
string query_name(){ return name; }

void set_color_name(string str){ color_name = str; }
string query_color_name(){ return color_name; }

void set_level(int i){ level = i; }
int query_level(){ return level; }

void set_rank(int i){ rank = i; }
int query_rank(){ return rank; }

void set_school(string str){ school = str; }
string query_school(){ return school; }

void set_stat(string str){ stat = str; }
string query_stat(){ return stat; }

void set_sp_cost(int i){ sp_cost = i; }
int query_sp_cost(){ return sp_cost; }

void set_cost_string(string str){ cost_string = str; }
string query_cost_string(){ return cost_string; }

void set_delay(int i){ delay = i; }
int query_delay(){ return delay; }

void set_delay_type(string str){ delay_type = lower_case(str); }
query_delay_type(){ return delay_type; }

void set_type(string str){ type = str; }
string query_type(){ return type; }

void set_component_id(string str){ component_id = str; }
string query_component_id(){ return component_id; }

void set_component_string(string str) { component_string = str; }
string query_component_string(){ return component_string; }

void set_combat_spell(int i){ combat_spell = i; }
int query_combat_spell(){ return combat_spell; }

void set_descrip(string str){ descrip = str; }
string query_descrip(){ return descrip; }


/*
 * Check Various Legalities of Spell Casting
 */
spell_cast()
{
  if(tp->query_ghost())
  {
        notify_fail("You cannot cast spells while your dead!\n");
        return 0;
  }

  if(tp->query_sp() < MIN_SP && !present("mage_casting_object", tp))
  {
	notify_fail("You are too weak to cast this spell.\n");
        return 0;
  }

  if( (guild && guild->query_casting()) && (!present("mage_casting_object", tp)) )
  {
	notify_fail("You are already casting a spell.\n");
        return 0;
  }

  if(!check_timer())
  {
	return 0;
  }

  if(!check_component())
  {
	return 0;
  }

  if(combat_spell && !check_combat())
  {
	return 0;
  }

  /* OK to cast! */
  return 1;
}


/*
 * Check for required spell component
 */
check_component()
{
  object pouch;
  /* always pass if no component was specified */
  if(!component_id)
	return 1;

  /* components are required when using a casting object (ie wand) */
  if(present("mage_casting_object", tp))
	return 1;
	
	if(pouch = present("mage's component pouch", tp))
	{
        if(present(component_id, pouch) && !present(component_id, tp))
  	{
    	move_object(present(component_id, pouch), tp);
  	}
	}

  if(!present(component_id, tp) && !present(component_id, env))
  {
	notify_fail("You lack the necessary components for this spell.\n");
	if(tp->query_level() > WIZLEVEL)
	{
		write(CYN+"[Component check bypassed for Wizard ... ]\n"+NORM);
		return 1;
	}
	return 0;
  }

  /* required component is present */
  return 1;
}


/*
 * Check Delay Timers
 */
check_timer()
{
  /*
   * no timer delay if a casting object (ie wand) is being used
   */
  if(present("mage_casting_object", tp))
  {
	if(tp->query_level() > WIZLEVEL) write("[casting object present, skipping timer check.\n");
	return 1;
  }

  /*
   * check various spell casting timers
   */

  /* check timer on all spells */
  if(guild->query_next_casting("all") > time())
  {
	notify_fail("You cannot cast "+HIC+"ANY"+NORM+" spells again yet.\n");
	if(tp->query_level() > WIZLEVEL)
	{
		write(CYN+"[Timer check bypassed for Wizard ... ]\n"+NORM);
		return 1;
	}
	return 0;
  }

  /* check to see if there is a timer for this specific spell */
  if(guild->query_next_casting(lower_case(verb)) > time())
  {
	notify_fail("You cannot cast the "+HIB+name+NORM+" spell again yet.\n");
	if(tp->query_level() > WIZLEVEL)
	{
		write(CYN+"[Timer check bypassed for Wizard ... ]\n"+NORM);
		return 1;
	}
	return 0;
  }

  /* if the spell has no type then we're ok now */
  if(!type)
	return 1;

  /* otheriwise check casting timer for this spell type */
  if(guild->query_next_casting(lower_case(type)) > time())
  {
	notify_fail("You cannot cast another "+HIY+type+NORM+" spell again yet.\n");
	if(tp->query_level() > WIZLEVEL)
	{
		write(CYN+"[Timer check bypassed for Wizard ... ]\n"+NORM);
		return 1;
	}
	return 0;
  }

  /* all timers are clear */
  return 1;
}


/*
 * Check Combat Legalities
 */
check_combat()
{
  object target;

  if(!combat_spell)
	return 1;

  target = tp->query_attack();

  if(!target)
  { 
	notify_fail("You must be fighting before you may cast this spell.\n");
	return 0;
  }

  /* added by mizan, but the hard work of locating where things broke was by Fakir */
  /* checks that monster is in same room */
  if(target &&
     environment(target) &&
     environment(tp) &&
     environment(tp) == environment(target))
   {
     /* write("DEBUG: Environment check good. Target in same room.\n"); */
     return 1;
   }
    else
   {
     /* write("DEBUG: Environment check FAILED. Target not in same room.\n"); */
     write("You are a bit out of range to do this.\n");
     return 0;
   }
  /* end changes */

  if(environment(tp)->query_arena() || target->query_pl_k() > 1)
  {
        return 1;
  }

/*
 if(!target->query_npc())
  {
	notify_fail("You cannot cast this spell on another player.\n");
	return 0;
  }
*/

  /* Combat checks passed */
  return 1;
}


/*
 * Casting Success/Failure
 */
spell_fail(int level, string s, string a)
{
  int mage_stat;
  int mage_attrib;
  int fail_chance;
  int total;

  /*
   * if we are using a casting object (ie wand) then no spell fail is possible
   */
  if(present("mage_casting_object", tp))
	return 0;

  if(!s)
	mage_stat = 100;
  else
	mage_stat = guild->query_total_guild_stat(s);

  if(!a)
	mage_attrib = 100;
  else
	mage_attrib = guild->query_total_guild_stat(a);

  /* fail chance is 50 * spell level (range: 50-350) */
  fail_chance = level * 50;

  /* total = mage_attrib + (2 * mage_stat) (range: 2-300) */
  total = mage_attrib + (2 * mage_stat);

  /* give us a break if we are newbies */
  if(tp->query_guild_rank() <= 5) total += 20;

  fail_chance = random(fail_chance);

  if(tp->query_level() > 20)
  {
	write("Fail Chance: "+fail_chance+" [vs] Total: "+total+
	  "  ("+a+":"+mage_attrib+" + "+s+"*2: "+mage_stat*2+")\n");
  }

  if(fail_chance > total)
	return 1;  /* failed! */
  else
	return 0;  /* success! */

}


/*
 * Make limits for 'alteration' spells are not exceeded
 */
get_alteration_num(obj)
{
  object ob;
  int num;
  ob = first_inventory(obj);
  while(ob)
  {
	if(ob->id("mage_alteration"))
		num += ob->query_alteration_num();
	ob = next_inventory(ob);
  }
  return num;
}

