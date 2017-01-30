#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("wizeye");
  set_name("Wizard's Eye");
  set_color_name(HIG+"Wizard's Eye"+NORM);
  set_level(2);
  set_school("conjuration");
  set_sp_cost(WIZEYE_COST);
  set_cost_string(WIZEYE_COST + " sp");
  set_descrip(
	"Create a magical eye that can survey surrounding areas. " +
	"Use 'wizeye' to inspect your immediate area or 'wizeye <dir>' " +
	"to search one direction.  This spell may not work in some\n" +
	"areas.\n"
  );
}


spell(str)
{
  object ob;
  int i, c;
  string exits, name, dir;

  if(!spell_cast())
	return 0;

  if(!env->query_dest_dir())
  {
	notify_fail("This spell will not work here.\n");
	return 0;
  }

  write("You cast a " + query_color_name() + " spell ...\n");
  say(ME+" casts a spell.\n");

  /* NOTE: no spell_fail */

  tell_room(env,
   "A "+HIM+"floating eyeball"+NORM+" appears out of mid air!\n"+
   "The magical "+HIY+"Wizard's "+HIM+"Eye"+NORM+" bobs up and down as it looks around.\n");

  if(str && !dirtest(tp, str))
  {
	tell_room(env, "The floating eye bumps into a wall and disappears.\n");
	write("There is no exit '"+str+"'.\n");
	return 1;
  }
  else if(str)
  {
	write("You point "+str+" and the magic eye zooms away!\n");
	say(ME+" points "+str+" and the magic eye zooms away!\n");
  }

  ob = clone_object(OBJ_DIR + "wizard_eye");

  if(str)
  {
	move_object(ob, env);
	ob->exit_report(str);
  }
  else
  {
	exits = env->query_dest_dir();
	for(i=0; i<sizeof(exits); i+=2)
	{
		name = exits[i];
		dir = exits[i+1];
		if(c == 0)
			tell_room(env, "The "+HIY+"Wizard's "+HIM+"Eye"+NORM+" zooms "+dir+".\n");
		else
			tell_room(env, "The "+HIY+"Wizard's "+HIM+"Eye"+NORM+" returns and zooms "+dir+".\n");
		move_object(ob, name);
		ob->do_report(dir);
		c++;
	}
  }

  tp->add_spell_point(-(query_sp_cost()));
  return 1;
}


dirtest(ob, str)
{
  int x;
  string exits;
  exits = environment(ob)->query_dest_dir();
  for(x=1; x<sizeof(exits); x+=2)
  {
	if(exits[x] == str) return 1;
  }
  return 0;
}


