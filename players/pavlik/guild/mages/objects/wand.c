#include "/players/pavlik/guild/mages/defs.h"

/*
 * - This object allows *any* player to cast Mage guild spells.
 *   When an object like this is present nearly all spell checks
 *   are by-passwd and guild stats are assumed to be maximized to
 *   offer the strongest possible spell effect.
 * - This item should *not* be easily attainable by any player
 *   since it can be quite powerful.
 *
 *   *** Not every guild spell is compatible with this object!
 */

string spell;		/* which spell this object can cast */
string spell_name;	/* descriptive name retrieved from the spell object file */
int charges;		/* how many times this object can be used */
int casting;		/* flag set when casting a spell from this object */

reset(arg) {
  if(arg) return;
  spell = "stoneskin";
  charges = 3;
  if(spell)
	spell_name = call_other(SPELL_DIR+spell+".c", "query_color_name", 0);
}

set_spell(str)
{
  spell = str;
  spell_name = call_other(SPELL_DIR+spell+".c", "query_color_name", 0);
}
query_spell(){ return spell; }

set_charges(i){ charges = i; }
query_charges(){ return charges; }
add_charges(i)
{
  charges += i;
  if(charges < 0) charges = 0;
}

short()
{
  if(!spell || !spell_name)
	return "A "+HIBLK+"burnt-out"+NORM+" wand";

  if(!charges)
	return "A "+HIBLK+"burnt-out"+NORM+" wand";
  else
	return "A Wand of "+spell_name+" "+
	  HIBLK+"("+NORM+MAG+charges+NORM+HIBLK+")"+NORM;
}

long()
{
  string name;

  if(!spell || !spell_name)
  {
	write("A "+HIBLK+"burnt-out"+NORM+" wand.\n");
	return;
  }

  if(!charges)
	write(
	  "A "+HIBLK+"burnt-out"+NORM+" wand.  Whatever "+MAG+"magic"+NORM+" this wand had contained\n" +
	  "has long since been "+CYN+"consumed"+NORM+".  The wand is just a useless twig of wood now.\n");
  else
	write(
	  short() + "\n" +
	  "This magic wand can be used to cast the "+spell_name+" spell.\n" +
	  "To use this magic item you should '"+HIC+"wwave wand"+NORM+"'.\n" +
	  "The wand has "+HIBLK+"("+NORM+MAG+charges+NORM+HIBLK+")"+NORM+" charges remaining.\n");
  return;
}

id(str)
{
  if(!spell || !spell_name)
	return str == "wand";
  else if(casting)
	return str == "mage_casting_object";
  else
	return str == "wand" || str == "magic wand" || str == spell+" wand" ||
	  str == "wand of "+spell || str == "wand of "+spell_name;
}

query_value()
{
  return charges * 1000;
}

get(){ return 1; }
drop(){ return 0; }

init()
{
  if(spell && spell_name && charges)
  {
	add_action("use_wand", "wave");
	add_action("use_wand", "wwave");
  }
}

use_wand(str)
{
  if(charges && str && spell && spell_name &&
    (str == "wand" || str == spell+" wand"))
  {
	casting = 1;

	if(call_other(SPELL_DIR+spell+".c", "spell", 0))
	{
		add_charges(-1);
		casting = 0;
		return 1;
	}
	else
	{
		casting = 0;
		return 0;
	}
  }
  else if(charges && str && spell && spell_name &&
    (sscanf(str, spell+" wand %s", str)==1 || sscanf(str, "wand %s", str)==1))
  {
	casting = 1;

	if(call_other(SPELL_DIR+spell+".c", "spell", str))
	{
		add_charges(-1);
		casting = 0;
		return 1;
	}
	else
	{
		casting = 0;
		return 0;
	}
  }
}

