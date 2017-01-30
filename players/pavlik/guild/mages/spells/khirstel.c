#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("khirstel");
  set_name("Khirstel");
  set_color_name(HIY+"Khirstel"+NORM);
  set_level(3);
  set_school("conjuration");
  set_stat("intelligence");
  set_sp_cost(KHIRSTEL_COST);
  set_cost_string(KHIRSTEL_COST + " sp");
  set_descrip(
	"Cast this spell to conjure the magical Khirstel. " +
	"The Khirstel is a wonderful pack animal that will " +
	"carry your equipment.  Khirstels typically do not " +
	"fight, however they may join the combat at times.\n"
  );
}


spell()
{
  object obj;

  if(!spell_cast())
	return 0;

  if(tp->query_attack())
  {
	notify_fail("You cannot cast this spell while you are fightning.\n");
	return 0;
  }
	
  if(find_living(rlname+"'s khirstel"))
  {
	notify_fail("You already have a khirstel.\n");
	return 0;
  }

  write("You cast a " + query_color_name() + " spell ... \n");

  if(spell_fail(level, school, stat))
  {
	write(
	 "You "+HIR+"miscast"+NORM+" the spell!\n" +
	 "The conjuration spell goes awry and you accidently summon a "+HIR+"DEMON"+NORM+"!\n");
	say(
	 ME+" "+HIR+"miscasts"+NORM+" a summoning spell and a "+HIR+"DEMON"+NORM+" appears!\n");
	obj = clone_object(OBJ_DIR + "demon");
	move_object(obj, env);
	obj->do_demon(tp);
	tp->add_spell_point(-10);
	return 1;
  }

  write(
   "You summon a magical "+HIY+"Khirstel"+NORM+".\n" +
   "The furry little creature "+BLU+"materializes"+NORM+" at your feet.\n" +
   "The slobbering "+HIY+"Khirstel"+NORM+" nips playfully at your ankles.\n");

  say(
   ME+" casts a "+BLU+"summoning spell"+NORM+" and a furry creature appears!\n" +
   "The slobbering Khirstel nips playfully at your ankles.\n");

  obj = clone_object(OBJ_DIR + "khirstel");
  obj->set_owner(tp);
  move_object(obj, env);
  obj->do_khirstel();
  tp->add_spell_point(-(query_sp_cost()));
  return 1;

}

