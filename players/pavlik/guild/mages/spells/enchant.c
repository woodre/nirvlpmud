#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("enchant");
  set_name("Enchant Object");
  set_color_name(HIM+"Enchant "+NORM+HIB+"Object"+NORM);
  set_level(7);
  set_school("enchantment");
  set_stat("intelligence");
  set_sp_cost(ENCHANT_COST);
  set_cost_string(ENCHANT_COST+" sp");
  set_type("alteration");
  set_descrip(
	"Enchant a weapon or piece of armor with magic.\n"
  );
}


spell(str)
{
  string *dtypes;
  string obj_type;
  string t;
  object obj;
  int amount, hits;
  int x;

  if(!spell_cast())
	return 0;

  obj = present(str, tp);

  if(!obj)
  {
	notify_fail("You do not have a "+str+" to enchant.\n");
	return 0;
  }

  if(obj->weapon_class())
	obj_type = "weapon";
  else if(obj->armor_class())
	obj_type = "armor";
  else
  {
	notify_fail("This spell can only be cast on a weapon or piece of armor.\n");
	return 0;
  }

  if(tp->query_sp() < 100)
  {
	notify_fail("You are too tired to cast this spell.\n");
	return 0;
  }

  if(obj_type == "weapon" && obj->query_wielded())
  {
	notify_fail("You must unwield the weapon before enchanting it.\n");
	return 0;
  }

  if(obj_type == "armor" && obj->query_worn())
  {
	notify_fail("You must remove the armor before enchanting it.\n");
	return 0;
  }

  if(obj->query_enchantment("mage enchantment"))
  {
	notify_fail("This item has already been enchanted.\n");
	return 0;
  }

  write("You cast a " + query_color_name() + " spell ... \n");

  dtypes = ({
	"physical",		HIBLK,
	"magical",		HIM,
	"other|fire",		HIR,
	"other|ice",		HIB,
	"other|poison",		HIG,
	"other|electric",	HIY
  });

  x = random(sizeof(dtypes)-1);
  if(x%2) x--;

  /* amount of the enchantment bonus */
  amount = ENCHANT_AMOUNT;
  if(amount > ENCHANT_MAX_AMOUNT) amount = ENCHANT_MAX_AMOUNT;

  /* how many hits the enchantment will last */
  hits = guild->query_total_guild_stat("intelligence") * 100;

  if(sscanf(dtypes[x], "other|%s", t) != 1)
	t = dtypes[x];

  /*
   * spell fail turns enchantment into a curse (unbeknownst to player)
   */
  if(spell_fail(level, school, stat))
  {
	amount = amount * -1;
	hits = hits * 2;
  }
	
  if(obj_type == "weapon")
  {
	/*
	 * amount is added to the weapon damage
	 * name,short,long,amount,dtype,seconds,hits,func,ob
	 */
	obj->add_enchantment(
	  "mage enchantment",
	  HIC+"["+dtypes[x+1]+"*"+HIC+"]"+NORM,
	  "This weapon has been "+HIC+"enchanted"+NORM+" by a "+CYN+"Mage"+NORM+".\n"+NORM+
	  obj->query_short()+" now does extra "+dtypes[x+1]+t+NORM+" damage.\n",
	  amount,
	  dtypes[x],
	  0,
	  hits,
	  0,
	  0
	);
  }

  if(obj_type == "armor")
  {
	if(obj->query_type() != "armor" && (dtypes[x] == "physical" || dtypes[x] == "magical"))
	{
		amount = amount / 2;
		if(amount < 1) amount = 1;
	}

	/*
	 * amount is % resistance to the selected damage type
	 * name,short,long,amount,dtype,seconds,hits,fun,ob,res
	 */
	obj->add_enchantment(
	  "mage enchantment",
	  HIC+"["+dtypes[x+1]+"*"+HIC+"]"+NORM,
	  "This armor has been "+HIC+"enchanted"+NORM+" by a "+CYN+"Mage"+NORM+".\n"+NORM+
	  obj->query_short()+" now provides extra protection against "+dtypes[x+1]+t+NORM+" attacks.\n",
	  0,
	  dtypes[x],
	  0,
	  hits,
	  0,
	  0,
	  amount
	);
  }

  write(
   "You use your mastery of the "+HIC+"arcane"+NORM+" to "+HIM+"enchant"+NORM+" "+obj->query_short()+
   " with "+HIC+"magical"+NORM+" power.\n" +
   "Your body quivers as the "+MAG+"magic"+NORM+" flows through it and into the "+obj_type+".\n");
  say(ME+" casts a spell of "+HIC+"enchantment"+NORM+" on "+obj->query_short()+".\n");

  if(tp->query_level() >= WIZLEVEL)
  {
	write("Enchantment amount: "+amount+"\n");
	write("Damage Type: "+dtypes[x]+"\n");
  }

  tp->add_sp(-(query_sp_cost()));
  return 1;

}

