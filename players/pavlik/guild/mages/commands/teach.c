#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/command";

reset(arg) {
  if(arg) return;
  set_verb("teach");
  set_name("Teach");
  set_color_name(HIC+"Teach"+NORM);
  set_rank(10);
  set_descrip(
	"When a Mage is ready to advance to the rank of Master " +
	"he or she must be taught be a higher ranking guild member. " +
	"Use the teach command to help other guild members advance.\n"
  );
}


cmd(str)
{
  object obj;
  string name;
  int lvl, what, x;
  int trains;

  if(tp->query_guild_rank() < 9 && !is_gc())
  {
	notify_fail("You are not experienced enough to train anyone.\n");
	return 0;
  }

  if(!str)
  {
	notify_fail("Usage: train <player>\n");
	return 0;
  }

  obj = find_player(str);

  if(!obj || !present(obj, env))
  {
	notify_fail(capitalize(str)+" is not here.\n");
	return 0;
  }

  if(!present("mageobj", obj))
  {
	notify_fail(capitalize(str)+" does not have a spellbook.\n");
	return 0;
  }

  lvl = obj->query_guild_rank();

  if(lvl == 9 || lvl == 19 || lvl == 29 || lvl == 39 ||
    lvl == 49 || lvl == 59 || lvl == 70)
  {

	if(tp->query_guild_rank() < (lvl+1) && !is_gc())
	{
		notify_fail("You are not expierencied enough to train this Mage.\n");
		return 0;
	}

	if(lvl == 9) what = "Earth";
	else if(lvl == 19) what = "Air";
	else if(lvl == 29) what = "Fire";
	else if(lvl == 39) what = "Dragons";
	else if(lvl == 49) what = "Storms";
	else if(lvl == 59) what = "Stars";
	else if(lvl == 70) what = "Time";

	trains = random(tp->query_guild_rank()/16) + 1;

	write("\n"+
	 "You take it upon yourself to train "+IT+" in the ways of magic.\n"+
	 IT+" will become a Master of "+what+" with your guidance.\n"+
	 "You discipline "+IT+"'s mind and soul in the ways of magic.\n");
	 write(IT+" earns "+trains+" training sessions.\n\n");

	tell_object(obj, "\n"+
	 ME+" has granted you the knowledge to become a Master of "+what+"\n"+
	 "Under "+ME+"'s watchful eye your mind and soul are discplined in\n"+
	 "the ways of magic.  You advance to the status of "+HIM+"Master\n"+NORM);
	tell_object(obj, "You earn "+trains+" training sessions.\n\n");

	say(ME+" trains "+IT+" in the ways of magic.\n");
	("/players/pavlik/guild/mages/inherit/channel")->tell_members(HIC+"[~"+ME+"~]: "+
	 IT+" has become A Master of "+what+".\n"+NORM);

	obj->add_guild_rank(1);
	present("mageobj", obj)->add_training_sessions(trains);

	write_file("/players/pavlik/guild/mages/log/advance",
	 ME+" trained "+IT+" as a Master of "+what+"\t["+ctime()+"]\n");

	return 1;
  }
  else
  {
	notify_fail(IT+" does need to be trained.\n");
	return 1;
  }
}
