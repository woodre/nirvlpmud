#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("userv");
  set_name("Unseen Servant");
  set_color_name(YEL+"Unseen Servant"+NORM);
  set_level(3);
  set_school("conjuration");
  set_sp_cost(USERV_COST);
  set_cost_string(USERV_COST + " sp");
  set_descrip(
	"Summon a magical servant to deliver an item for you. " +
	"The servant can deliver one item to another player or it will " +
	"take an item to the shop to be sold.\n" +
	"Use: userv <item> <player> or: userv <item> shop\n"
  );
}


spell(str)
{
  string what, where;
  object ob, obj;
  object servant;
  int failed;

  if(!str || sscanf(str, "%s %s", what, where) != 2)
  {
	notify_fail("Have your servant take what to where?\n");
	return 0;
  }

  if(!spell_cast())
	return 0;

  if(env->realm() == "NT")
  {
	notify_fail("You can't cast that spell here.\n");
	return 0;
  }

  ob = present(what, tp);
  if(where == "shop" || where == "sell")
	obj = tp;
  else
	obj = find_player(where);

  if(!ob)
  {
	notify_fail("You do not have a "+what+" for the servant to take.\n");
	return 0;
  }

  if(!obj)
  {
	notify_fail(capitalize(where)+" is nowhere to be found.\n");
	return 1;
  }

  if(obj->query_level() > WIZLEVEL && tp->query_level() < WIZLEVEL)
  {
	notify_fail("Your servant would not dare impose upon a Wizard!\n");
	return 0;
  }

  /* can we drop this item at all? */
  if(transfer(ob, env))
  {
	notify_fail("The servant cannot take "+what+".\n");
	return 0;
  }

  write("You cast an " + query_color_name() + " spell ...\n");

  if(spell_fail(level, school, stat))
  {
	failed = 1;
  }

  write(
   "A "+HIB+"cold wind"+NORM+" blows across the land sending "+HIY+"shivers"+NORM+" down your spine.\n" +
   "A "+HIBLK+"shadowy apparition"+NORM+" rises from the ground and "+CYN+"bows before you"+NORM+".\n" +
   "You whisper your commands to the "+YEL+"Unseen Servant"+NORM+", who takes the "+what+"\n" +
   "and "+HIBLK+"disappears"+NORM+" into the ground.\n");

  say(
   "A "+HIB+"cold wind"+NORM+" blows across the land sending "+HIY+"shivers"+NORM+" down your spine.\n" +
   "A "+HIBLK+"shadowy apparition"+NORM+" rises from the ground and "+CYN+"bows before "+ME+NORM+".\n" +
   ME+" gives something to the "+HIBLK+"Shade"+NORM+" - it nods solemnly and disappears.\n");

  servant = clone_object(OBJ_DIR + "unseen_servant");
  servant->set_owner(tp);
  servant->set_failed(failed);
  servant->set_cargo(ob);
  if(obj == tp) servant->set_destination(servant);
  else servant->set_destination(obj);
  move_object(ob, servant);

  tp->add_spell_point(-(query_sp_cost()));
  return 1;

}

