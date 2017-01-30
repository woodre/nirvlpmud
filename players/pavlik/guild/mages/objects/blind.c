#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"

/* the target's full, unaffected weapon class */
int full_wc;

/* track spell casters */
mapping caster;
mapping expiration;

reset(arg) {
  if(arg) return;
  caster = ([]);
  expiration = ([]);
}

short(){ return; }
long(){ write("a mages blind_obj.\n"); return; }
id(str){ return str == "blind_obj" || str == "generic_wc_bonus"; }
get(){ return 0; }
drop(){ return 1; }

/*
 * this limits how many blinds or other 'alterations' can be
 * cast on the target
 */
get_alteration_num(){ return sizeof(caster); }

query_caster(name) {
  if(!caster || !sizeof(caster)) return 0;
  return caster[name];
}

query_expiration(name) {
  if(!expiration || !sizeof(expiration)) return 0;
  return expiration[name];
}

query_full_wc(){ return full_wc; }
query_min_wc(){ return (5 * full_wc) / 8; }

/*
 * total up the casters wc reductions
 */
int gen_wc_bonus()
{
  string *names;
  int i, wc;

  if(!caster || !sizeof(caster))
	return 0;

  names = m_indices(caster);
  i = sizeof(names);
  while(i--)
  {
	wc += caster[names[i]];
  }
  return (-wc);
}


/*
 * initiate the spell
 */
do_spell()
{
  if(!caster || !sizeof(caster))
	full_wc = en->query_wc();

  caster[tp->query_real_name()] = reduce_weapon_class();
  expiration[tp->query_real_name()] = get_expiration();

  while(remove_call_out("exe_spell") != -1);
  call_out("exe_spell", 4);

  return 1;
}


/*
 * call_out to execute the effects
 */
exe_spell()
{
  string *names;
  object ob;
  int i;
  int r;

  if(!en || !living(en))
  {
	names = m_indices(caster);
	i = sizeof(names);
	while(i--)
	{
		ob = find_player(names[i]);
		if(ob && present("mageobj", ob))
			present("mageobj", ob)->remove_spell_object("blind");
	}
	destruct(this_object());
	return 1;
  }

  names = m_indices(expiration);
  i = sizeof(names);
  while(i--)
  {
	if(!query_caster(names[i]))
	{
		expiration = m_delete(expiration, names[i]);
		continue;
	}

	expiration[names[i]]--;

	if(expiration[names[i]] <= 0)
	{
		tell_room(environment(en),
		  MPROMPT+capitalize(names[i])+"'s blindness spell wears off.\n"+NORM);
		expiration = m_delete(expiration, names[i]);
		caster = m_delete(caster, names[i]);
		ob = find_player(names[i]);
		if(ob && present("mageobj", ob))
			present("mageobj", ob)->remove_spell_object("blind");
	}

	if(!sizeof(caster))
	{
		tell_room(environment(en),
		  MPROMPT+capitalize(en->query_name())+" can see again.\n"+NORM);
		destruct(this_object());
		return 1;
	}
  }

  r = random(6);

  if(r == 0)
	tell_room(environment(en),
	  capitalize(en->query_name())+" "+CYN+"stumbles about blindly"+NORM+".\n");
  else if(r == 2)
	tell_room(environment(en),
	  capitalize(en->query_name())+" "+YEL+"blindly crashes about"+NORM+".\n");
  else if(r == 4)
	tell_room(environment(en),
	  capitalize(en->query_name())+" hits "+GRN+"nothing but air"+NORM+" as "+
	  en->query_pronoun()+" "+GRN+"swings blindly"+NORM+" about"+NORM+".\n");

  while(remove_call_out("exe_spell") != -1);
  call_out("exe_spell", 4);
  return 1;
}


/*
 * this function picks the number that the targets weapon class
 * will be reduced by.
 */
reduce_weapon_class()
{
  int amount;
  amount = BLIND_WC_REDUCTION;
  if(amount > BLIND_MAX_REDUCTION) amount = BLIND_MAX_REDUCTION;
  if(amount < 1) amount = 1;
  if(tp->query_level() > WIZLEVEL)
	tell_object(this_player(), "WC reduction is: "+amount+"\n");
  return amount;
}

/*
 * this function will determine how long the spell lasts
 */
get_expiration()
{
  int amount;
  amount = random(guild->query_total_guild_stat("power") / 7) + 2;
  if(amount > 10) amount = 10;
  if(amount < 3) amount = 3;
  if(tp->query_level() > WIZLEVEL)
	tell_object(tp, "Blind expiration is: "+amount+"\n");
  return amount;
}

