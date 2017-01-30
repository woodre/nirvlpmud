#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("mark");
  set_name("Wizard Mark");
  set_color_name(HIB+"Wizard Mark"+NORM);
  set_level(1);
  set_school("evocation");
  set_sp_cost(MARK_COST);
  set_cost_string(MARK_COST + " sp");
  set_descrip(
	"Use this spell to burn a message into the ground.  The " +
	"Wizard Mark can be read by anyone who sees it.\n"
  );
}


spell(str)
{
  object ob;

  if(!str)
  {
	notify_fail("Mark what message?\n");
	return 0;
  }

  if(!spell_cast())
	return 0;

  if(present("wizard_mark", env))
  {
	notify_fail("A Wizard Mark has already been left here.\n");
	return 0;
  }

  str = COLOR_PARSER->parse_pcodes(str);

  write("You cast a " + query_color_name() + " spell ...\n");
  say(ME+" casts a magic spell ...\n");

  /* NOTE: no spell_fail */

  tell_room(env,
   "An enchanted quill of "+HIB+"blue fire"+NORM+" blazes in the air before you.\n"+
   "The "+HIB+"fire quill"+NORM+" moves swifty and "+RED+"burns"+NORM+" a message into the ground.\n" +
   "The quill completes the writing and disappears in a "+HIW+"puff of smoke"+NORM+"!\n");

  write("\nYou write: "+str+"\n");

  ob = clone_object(OBJ_DIR + "wizard_mark");
  move_object(ob, environment(tp));
  ob->set_owner(tp->query_real_name());
  ob->set_message(str);
  tp->add_spell_point(-(query_sp_cost()));
  return 1;

}
