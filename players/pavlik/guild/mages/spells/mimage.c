#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("mimage");
  set_name("Mirror Image");
  set_color_name(HIY+"Mirror "+NORM+HIM+"Image"+NORM);
  set_level(7);
  set_school("illusion");
  set_stat("will power");
  set_component_id(MIMAGE_COMPONENT_ID);
  set_component_string("Platinum Mirror");
  set_sp_cost(MIMAGE_COST);
  set_cost_string(MIMAGE_COST+" sp + "+MIMAGE_IMAGE_COST+" sp per image + Platinum Mirror");
  set_type("protection");
  set_combat_spell(2);
  set_descrip(
	"Create illusions of yourself to fool your enemy in combat.  " +
	"This spell will create mirror images of yourself that your " +
	"enemy will attack instead of attacking you.\n" +
	"You can 'dispell image' to release your mirror images.\n\n" +
	"Note: the required spell component is not destroyed in the " +
	"proper casting of this spell.\n"
  );
}


spell()
{
  object ob, obj;
  int images;
  int base, decr;
  int i;

  if(present("mirror image", env))
  {
	notify_fail("There is already a mirror image present!\n");
	return 0;
  }

  if(!spell_cast())
	return 0;

  obj = tp->query_attack();

  write("You cast a " + query_color_name() + " spell ... \n");

  if(spell_fail(level, school, stat))
  {
	write("You "+HIR+"miscast"+NORM+" the spell!\n");
	say(ME+" "+HIR+"miscasts"+NORM+" a spell.\n");
	if(present(component_id, tp))
	{
		if(!random(2))
		{
			destruct(present(component_id, tp));
			write("The platinum mirrow ripples and then disintegrates!\n");
			write("You feel exhausted by the effort.\n");
			tp->add_spell_point(-(2 * (MIMAGE_IMAGE_COST * MIMAGE_MAX_IMAGES)));
		}
	}
	return 1;
  }

  write(
    "You hold a small "+HIY+"platinum"+NORM+" mirror in the air, it's "+HIW+"shiny surface"+NORM+" gathers rays of light.\n" +
    "The pool of light "+HIM+"swirls"+NORM+" and "+HIG+"spins"+NORM+" on the mirrors surface.\n" +
    "The radiant mirror begins to "+HIM+"pulse"+NORM+", as if it had a "+HIW+"life"+NORM+" of it's own ... \n");

  say(
    ME+" holds a small platinum mirror in the air.\n"+
    "The tiny mirror reflects a "+HIW+"brilliant "+NORM+HIY+"beam"+NORM+HIW+" of light"+NORM+" in your eyes.\n" +
    ME+" casts a "+HIC+"spell"+NORM+" over the reflected light and someone "+HIM+"steps out"+NORM+" of the enchanted mirror!\n");

  if(present("mage_casting_object", tp))
	images = MIMAGE_MAX_IMAGES;
  else
  {
	images = 1 + random(guild->query_total_guild_stat("illusion")/25);
	if(images > MIMAGE_MAX_IMAGES) images = MIMAGE_MAX_IMAGES;
  }

  /*
   * this is how fast the illusion success rate will decrease per round
   */
  if(present("mage_casting_object", tp))
  {
	base = 100;
	decr = 7;
  }
  else
  {
	decr = 30 - random(guild->query_total_guild_stat("will power") / 5);
	if(decr < 7) decr = 7;
	base = guild->query_total_guild_stat("illusion") / 2;
	base += random(guild->query_total_guild_stat("illusion") / 2);
        
  }

  for(i=1; i<=images; i++)
  {
	write("A "+HIC+"Mirror Image"+NORM+" steps out of the mirror.\n");
	say("A "+HIC+"Mirror Image"+NORM+" of "+ME+" steps out of the mirror.\n");
	ob = clone_object(OBJ_DIR + "mirror_image");
	move_object(clone_object(OBJ_DIR + "no_combat"), ob);
	ob->set_name(HIC+"~"+NORM+ME);
	ob->set_owner(tp);
	ob->set_target(obj);
	ob->set_mirror_num(i);
	ob->set_chance(base);		/* base chance of failure */
	ob->set_decrease(decr);		/* rate of decrease per round */
	move_object(ob, env);
	if(i == 1)
		ob->begin_mirror(obj);
	if(!present("mage_casting_object", tp))
		tp->add_spell_point(-(MIMAGE_IMAGE_COST*2));
  }

  if(!present("mage_casting_object", tp))
	  tp->add_spell_point(-query_sp_cost());
	guild->add_spell_object("mimage", ob);

  return 1;

}
