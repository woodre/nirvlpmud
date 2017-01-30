#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("gstr");
  set_name("Giant's Strength");
  set_color_name(HIB+"Giant's "+HIM+"Strength"+NORM);
  set_level(6);
  set_school("enchantment");
  set_stat("power");
  set_sp_cost(GSTR_COST);
  set_cost_string(GSTR_COST+" sp");
  set_descrip(
	"This spell increases the targets strength so that they are more " +
	"effective in combat.  This spell can be cast on other players.\n" +
	"\n" +
	"Giant's Strength does not effect the actual strength stat or related " +
	"abilities (ie: carrying capacity) at this time.\n"
  );
}


spell(str)
{
  object ob, obj;
  int failed;
  int amount, expire;

/*
  if(tp->query_real_name() != "pavlik" && tp->query_real_name() != "pavtest")
  {
	notify_fail("Sorry, this spell is still in alpha testing.\n");
	return 0;
  }
*/

  if(!str)
	obj = tp;
  else
	obj = present(str, env);

  if(!obj)
  {
	notify_fail("Cast the spell on who?\n");
	return 0;
  }

  if(!obj->is_player())
  {
	notify_fail("This spell can only be cast on players.\n");
	return 0;
  }

  if(present("giant_strength", obj))
  {
	if(obj == tp)
		notify_fail("You are already under the effects of this spell.\n");
	else
		notify_fail(IT+" is already under the effects of this spell.\n");
	return 0;
  }

  if(!spell_cast())
	return 0;

  write("You cast a " + query_color_name() + " spell ... \n");
  say(ME+" casts a " + query_color_name() + " spell ... \n");

  failed = spell_fail(level, school, stat);

  if(present("mage_casting_object", tp))
  {
	amount = GSTR_MAX_AMOUNT;
	expire = 120;
  }
  else
  {
	amount = GSTR_AMOUNT;
	if(amount > GSTR_MAX_AMOUNT) amount = GSTR_MAX_AMOUNT;
	expire = GSTR_EXPIRE;
  }

  if(failed)
  {
	amount = amount * -1;
	expire = (expire * 3) / 2;
  }

  if(obj == tp)
	if(tp->query_gender() == "female")
		say(ME+" casts a "+query_color_name()+" spell on herself.\n");
	else
		say(ME+" casts a "+query_color_name()+" spell on himself.\n");
  else
	say(ME+" casts a "+query_color_name()+" spell on "+IT+".\n");

  tell_object(obj,
   "You feel the "+HIM+"power"+NORM+" of "+HIC+"magic"+NORM+" course through your body.\n" +
   "You suddenly feel "+HIB+"*<"+NORM+" "+BLU+"STRONGER!"+NORM+" "+HIB+">*"+NORM+"\n");

  tell_room(env,
    IT+"'s body is surrounded by a "+HIC+"magical"+HIM+" aura"+NORM+".\n" +
    IT+" suddenly radiates great "+HIB+"*<"+NORM+" "+BLU+"Strength!"+NORM+" "+HIB+">*"+NORM+"\n",
    ({obj}));

  if(tp->query_level() > WIZLEVEL)
	write("[giant strength:    amount:"+amount+"   expire:"+expire+"\n");

  ob = clone_object(OBJ_DIR + "giant_strength");
  ob->set_owner(obj);
  ob->set_amount(amount);
  ob->set_expire(expire);
  move_object(ob, obj);

  if(!present("mage_casting_object", tp))
	tp->add_spell_point(-query_sp_cost());

  if(present("mageobj", obj))
	present("mageobj", obj)->add_spell_object("gstr", ob);

  return 1;
}

