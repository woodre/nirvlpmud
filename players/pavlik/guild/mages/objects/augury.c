#include "/players/pavlik/guild/mages/defs.h"

/*
 * Augury shadow object
 * Purpose: to intercept function calls that would normally add hit points
 *	and change them to add spell points instead.
 *
 * 04/18/2006: Added code for *alpha* testing an "invulnrability" spell.
 *
 */

string spell_name;
object owner;
object obj;

set_spell_name(str){ spell_name = str; }
query_spell_name(){ return spell_name; }

do_spell(ob)
{
  owner = ob;
  obj = shadow(ob, 1);
}


end_spell()
{
  destruct(this_object());
  return 1;
}


short()
{
  if(spell_name == "invuln")
	return call_other(owner, "short", 0) + " " +
	  HIW+"("+HIY+"*"+HIB+"INVULNRABLE"+HIY+"*"+HIW+")"+NORM;
  else
	return call_other(owner, "short", 0);
}

  
add_hit_point(x)
{
  if(spell_name == "invuln")
	call_other(owner, "add_hit_point", x);
  else
  {
	if(x > 0)
		call_other(owner, "add_spell_point", x);
	else
		call_other(owner, "add_hit_point", x);
  }
}


heal_self(x)
{
  if(spell_name == "invuln")
	call_other(owner, "heal_self", x);
  else
  {
	if(x > 0)
		call_other(owner, "add_spell_point", (x*2));
	else
		call_other(owner, "heal_self", x);
  }
}


add_hp(x)
{
  add_hit_point(x);
}


/*
 * modified do_damage and hit_player calls
 * usable in ALPHA-TESTING ONLY (pavlik and pavtest)
 */

/* No need for this to happen as this spell never went live. - Ill 2015.07.23
do_damage(int *damage, string *method)
{
  int i;

  if(spell_name != "invuln")
  {
	return call_other(owner, "do_damage", damage, method);
  }

  if(!damage)
	return 0;

  i = sizeof(damage);
  while(i--)
  {
	if(method && method[i])
	{
		/*
		 * provide 90% protection against physical attacks
		 * note: the method (damage type) is changed to "other|pavlik" so that
		 *       the players armor does not affect the 10% of damage still done
		if(method[i] == "physical")
		{
			int s;
			s = damage[i] * 9 / 10;
			call_other(owner, "add_spell_point", -s);
			tell_object(owner,
			  "[invuln: damage amount:"+damage[i]+"   shielded:"+s+"  taken:"+damage[i]/10+"]\n");

			damage[i] = damage[i] / 10;
			if(damage[i] < 1) damage[i] = 1;
			method[i] == "other|pavlik";
		}
	}
  }

  return call_other(owner, "do_damage", damage, method);
}
*/

