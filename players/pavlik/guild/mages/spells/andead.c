#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("andead");
  set_name("Animate Dead");
  set_color_name(CYN+"Animate "+NORM+GRN+"Dead"+NORM);
  set_level(7);
  set_school("necromancy");
  set_stat("power");
  set_component_id("corpse");
  set_component_string("corpse");
  set_sp_cost(ANDEAD_COST);
  set_cost_string(ANDEAD_COST+" sp + corpse");
  set_descrip(
	"Use the powers of necromancy to animate a corpse.  The animated " +
	"corpse will attack your current enemy and fight until your " +
	"opponent has been slain or the spell wears off.\n"
  );
}


spell()
{
  object corpse;
  object ob;
  string corpse_name;
  int corpse_wc;
  int ttl;

  /*
   * must be evil to use this spell!
   */
  if(tp->query_alignment() >= 500 && !present("mage_casting_object", tp))
  {
	notify_fail("You feel too "+HIW+"nice"+NORM+" to use this spell right now.\n");
	return 0;
  }

  if(present("animated_corpse", env) && present("animated_corpse", env)->query_owner() == tp)
  {
	notify_fail("You already have an animation.\n");
	return 0;
  }

  if(!spell_cast())
	return 0;

  corpse = present(query_component_id(), tp);
  if(!corpse) corpse = present(query_component_id(), env);

  /* component is required, even if we have casting_object */
  if(!corpse)
  {
	notify_fail("You need a corpse for this spell.\n");
	return 0;
  }

  write("You cast a " + query_color_name() + " spell ... \n");

  if(spell_fail(level, school, stat))
  {
	write(
	  "You "+HIR+"miscast"+NORM+" the spell!\n" +
	  "Something horrible forces itself into being via your errant casting ... \n" +
	  "A "+HIW+"Bone"+HIR+"Demon"+NORM+" appears and attacks you!\n");
	say(
	  ME+" "+HIR+"miscasts"+NORM+" a spell and a "+HIW+"Bone"+HIR+"Demon"+NORM+" appears!\n" +
	  "The demon attacks "+ME+"!\n");
	ob = clone_object(OBJ_DIR + "demon");
	move_object(ob, env);
	ob->do_demon(tp);
	destruct(corpse);
	return 1;
  }

  write("You cast an "+HIBLK+"evil "+NORM+CYN+"enchantment"+NORM+" over a pile of "+HIW+"old bones"+NORM+".\n");
  say(ME+" casts an "+HIBLK+"evil "+NORM+CYN+"enchantment"+NORM+" over a pile of "+HIW+"old bones"+NORM+".\n");
  tell_room(env,
    "The "+HIW+"bones"+NORM+" begin to "+HIM+"rattle"+NORM+" and "+HIY+"tremble"+NORM+" ... \n" +
    "The pile of old bones stir and a "+GRN+"Skeleton"+NORM+" rises from the debris!\n");

  /* set up our weapon class based on corpses level */
  corpse_wc = (corpse->heal_value() * 3) / 2;
  if(corpse_wc < 10) corpse_wc = 10 + random(5);

  /* determine how long the object lasts (in heart_beats) */
  if(present("mage_casting_object", tp))
	ttl = 30;
  else
  {
	ttl = (guild->query_total_guild_stat("power") + guild->query_total_guild_stat("necromancy")) / 3;
  }

  corpse_name = corpse->query_name();
  if(!corpse_name)
	corpse_name = "something";

  ob = clone_object(OBJ_DIR + "animate_dead");
  ob->set_short("corpse of "+HIBLK+capitalize(corpse_name)+NORM+
	" "+RED+"("+GRN+"animated"+RED+")"+NORM);
  ob->set_name(GRN+"corpse"+NORM+" of "+HIBLK+capitalize(corpse_name)+NORM);
  ob->set_alias("corpse of "+corpse_name);
  ob->set_ttl(ttl);
  ob->set_owner(tp);
  ob->set_weapon_params("other|evil", corpse_wc, 0);
  move_object(ob, env);

  if(!present("mage_casting_object", tp))
	tp->add_spell_point(-query_sp_cost());
  destruct(corpse);
  return 1;

}
