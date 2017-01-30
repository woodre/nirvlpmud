#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("sac");
  set_name("Sacrifice");
  set_color_name(GRN+"Sacrifice"+NORM);
  set_level(1);
  set_school("necromancy");
  set_stat("will power");
  set_component_id(SAC_COMPONENT_ID);
  set_component_string("corpse");
  set_sp_cost(SAC_COST);
  set_cost_string("none");
  set_descrip(
	"Call upon the powers of necromancy to extract the magical essence "+
	"from a corpse.\n"
  );
}


spell()
{
  object obj;
  int heal, msg;

  if(!spell_cast())
	return 0;

  obj = present(component_id, tp);
  if(!obj) obj = present(component_id, env);
  if(!obj) return 0;    /* this shouldn't happen */

  write("You cast a " + query_color_name() + " spell ... \n");

  if(spell_fail(level, school, stat))
  {
	write("You "+HIR+"miscast"+NORM+" the spell and the corpse crumbles to dust.\n");
	say(ME+" "+HIR+"miscasts"+NORM+" a spell and a corpse crumbles to dust.\n");
	destruct(obj);
	return 1;
  }

  heal = obj->heal_value() * SAC_HEAL;
  msg = random(3);

  if(msg == 0)
  {
    write(
     "You dab your fingers in "+RED+"blood"+NORM+" and trace an "+CYN+"arcane symbol"+NORM+" on the ground.\n" +
     "The empty husk "+CYN+"crumbles to dust"+NORM+".\n" +
     "You feel "+HIM+"revitalized"+NORM+"!\n");
    say(
     ME+" sacrifices the "+obj->short()+".\n"+
     "The empty husk "+HIBLK+"crumbles to dust"+NORM+".\n");
  }
  else if(msg == 1)
  {
    write(
     "The corpse "+HIR+"bursts into flames"+NORM+" and the "+HIBLK+"ashes"+NORM+" blow away with the wind.\n" +
     "You feel "+HIM+"infused"+NORM+" with power!\n");
    say(
     ME+" casts a spell of "+HIBLK+"necromancy"+NORM+" on the "+obj->short()+".\n"+
     "The corpse "+HIR+"bursts into flames"+NORM+" and the ashes blow away with the wind.\n");
  }
  else
  {
    write(
     "The corpse's flesh "+GRN+"rots away"+NORM+" until only a "+HIW+"skeleton"+NORM+" remains.\n"+
     "You smile "+HIR+"demonically"+NORM+" as renewed "+HIM+"magic"+NORM+" runs through your veins.\n");
    say(
     ME+" casts a "+HIBLK+"necromancy"+NORM+" spell over the "+obj->short()+".\n" +
     "The corpse's flesh "+GRN+"rots away"+NORM+" until only a "+HIW+"skeleton"+NORM+" remains.\n"+
     ME+" smiles "+HIR+"demonically"+NORM+".\n");
  }

  tp->add_spell_point(heal);
  destruct(obj);
  return 1;

}
