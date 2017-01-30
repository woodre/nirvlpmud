#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("soar");
  set_name("Soar");
  set_color_name(HIY+"Soar"+NORM);
  set_level(4);
  set_school("conjuration");
  set_stat("wisdom");
  set_component_id("light feather");
  set_component_string("Light Feather");
  set_sp_cost(150);
  set_cost_string("150 sp + Light Feather");
  set_type("special");
  set_descrip(
	"Fly high in the air above your current surroundings.\n"
  );
}


spell()
{
  object ob, obj;
  int images;
  int base, decr;
  int i;

  if(env->is_soar())
  {
    write("You are already "+HIY+"Soaring"+NORM+"!\n");
    return 1;
  }

  if(!spell_cast())
	return 0;


  write("You cast a " + query_color_name() + " spell ... \n");

  if(spell_fail(level, school, stat))
  {
	write("You "+HIR+"miscast"+NORM+" the spell!\n");
	say(ME+" "+HIR+"miscasts"+NORM+" a spell.\n");
	if(present(component_id, tp))
	{
		if(!random(6))
		{
			destruct(present(component_id, tp));
			write("The light feather disappears!\n");
		}
		else
		{
			write("You feel exhausted by the effort.\n");
			tp->add_spell_point(-25);
		}
	}
	return 1;
  }

  if(present(component_id, tp)) {
     destruct(present(component_id, tp));
  }
  write("\n"+
HIW+"Magical wings"+NORM+" sprout from your shoulders, and you leap . . .\n\
\tYou "+HIY+"Soar"+NORM+" up into the air!\n\n");
  say(tp->query_name()+" leaps up into the air and "+HIW+"magical wings"+NORM+"\n\
sprout from "+possessive(tp)+" shoulders!\n"+
capitalize(subjective(tp))+" flies high up into the air!\n\n");
  
  {
    ob = clone_object(OBJ_DIR+"soar_obj");
    ob->set_player(tp);
    move_object(ob, environment(tp));
    move_object(tp, ob);
  }

  if(!present("mage_casting_object", tp))
	tp->add_spell_point(-query_sp_cost());

  return 1;

}

