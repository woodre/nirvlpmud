#include "/players/pavlik/guild/mages/defs.h"
#define GS HIB+"Giant's "+HIM+"Strength"+NORM

object owner;
int amount;
int expire;
int nonrandom_dmg;

reset(arg){
  if(arg) return;
  owner = 0;
  amount = 0;
  expire = 0;
  nonrandom_dmg = 0;
  set_heart_beat(1);
}

short(){ return; }
long(){ write("a mages giant_strength.\n"); return; }
id(str){ return str == "generic_wc_bonus" || str == "giant_strength" || str == "giants_strength"; }
get(){ return 0; }
drop(){ return 1; }

set_owner(ob){ owner = ob; }
query_owner(){ return owner; }

set_amount(i){ amount = i; }
query_amount(){ return amount; }

set_expire(i){ expire = i; }
query_expire(){ return expire; }

extra_look(){ "has "+HIB+"Giant's Strength!"+NORM; }


heart_beat()
{
  if(!environment() || !owner || environment() != owner)
  {
	if(owner && present("mageobj", owner))
		present("mageobj", owner)->remove_spell_object("gstr");
	destruct(this_object());
	return 0;
  }

  expire--;

  if(expire <= 0)
  {
	tell_object(owner,
	  SPELL_PROMPT+" The "+GS+" spell wears off.\n" +
	  SPELL_PROMPT+" The "+MAG+"magical "+HIW+"aura"+NORM+" surrounding your body disppears.\n");
	tell_room(environment(owner),
	  "The "+MAG+"magical "+HIW+"aura"+NORM+" surrounding "+OWN+"'s body disappears.\n" +
	  OWN+"'s muscles shrink as the "+GS+" spell wears off.\n",
	  ({owner}));
	if(owner && present("mageobj", owner))
		present("mageobj", owner)->remove_spell_object("gstr");
	destruct(this_object());
	return 0;
  }

}


gen_wc_bonus()
{
  int msg;

  if(!environment() || !owner || environment() != owner)
  {
	destruct(this_object());
	return 0;
  }

  msg = random(9);

  if(msg == 1)
  {
	tell_object(owner,
	  "You delight in the "+MAG+"extra "+HIW+"force"+NORM+" of your attacks provided by the "+GS+" spell!\n");
	tell_room(environment(owner),
	  "You marvel at the "+MAG+"extra "+HIW+"force"+NORM+" behind "+OWN+"'s attacks!\n",
	  ({owner}));
  }
  if(msg == 3)
  {
	tell_object(owner,
	  "Your muscles "+HIW+"BULGE"+NORM+" to "+HIB+"giant-like"+NORM+" proportions!\n");
	tell_room(environment(owner),
	  OWN+"'s muscles "+HIW+"BULGE"+NORM+"  to "+HIB+"giant-like"+NORM+" proportions!\n",
	  ({owner}));
  }
  if(msg == 5)
  {
	tell_object(owner,
	  "Your attacks connect with "+HIB+"super-human"+NORM+" force!\n");
	tell_room(environment(owner),
	  OWN+"'s attacks connect with "+HIB+"super-human"+NORM+" force!\n",
	  ({owner}));
  }
  if(msg == 7)
  {
	tell_object(owner,
	  "You "+HIW+"flex"+NORM+" your "+HIB+"GIANT"+NORM+" muscles!\n" +
	  "Your friends "+HIW+"gasp"+NORM+" in "+HIM+"wonder"+NORM+" and your enemies "+
	  HIW+"quiver"+NORM+" in "+HIY+"fear"+NORM+"!\n");
	tell_room(environment(owner),
	  OWN+" "+HIW+"flexes"+NORM+" "+owner->query_possessive()+" "+HIB+"GIANT"+NORM+" muscles!\n" +
	  owner->query_possessive()+" friends "+HIW+"gasp"+NORM+" in "+HIM+"wonder"+NORM+" and "+owner->query_possessive()+" enemies "+
	  HIW+"quiver"+NORM+" in "+HIY+"fear"+NORM+"!\n",
	  ({owner}));
  }

  nonrandom_dmg++;

  if(nonrandom_dmg == amount)
  {
	nonrandom_dmg = 0;
	return amount;
  }
  else
	return nonrandom_dmg + random((amount - nonrandom_dmg));

}

