#include "/players/pavlik/guild/mages/defs.h"
inherit "/players/pavlik/guild/mages/inherit/masters";
inherit "/players/pavlik/guild/mages/inherit/advance";
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Dycedakis");
  set_alias("dycedakis");
  set_short(RED+"Dycedakis "+NORM+HIBLK+"the Black"+NORM);
  set_long(
	"It is impossible to determine anything about Dycedakis because he\n"+
	"is completely obscured by spells of illusion and misdirection.  The\n"+
	"only constant feature is the sinister gaze of his dark eyes.\n"+
	"  Dycedakis holds a "+HIW+"human skull"+NORM+" and a "+RED+"handkerchief"+NORM+" in his hands.\n");
  set_level(100);
  set_ac(80);
  set_wc(80);
  set_hp(10000);
  set_al(10000);
  set_aggressive(0);
}

init(){
  ::init();
  add_action("examine_object","exa");
  add_action("examine_object","examine");
  add_action("examine_object","see");
  add_action("examine_object","look");
  add_action("examine_object","l");
}


examine_object(str)
{
  if(str == "human skull" || str == "at human skull")
  {
	write("Dycedakis gives you a human skull so you can examine it.\n");
	write("The spider-web of cracks in the bone create a writing...\n\n");
	master_display_spell_list(({"necromancy"}));
	write("\nYou return the skull to Dycedakis.\n");
	say(ME+" examines Dycedakis' "+HIW+"human skull"+NORM+".\n", tp);
	return 1;
  }
  if(str == "handkerchief" || str == "at handkerchief")
  {
	write("Dycedakis gives you a handkerchief so you can examine it.\n");
	write("The delicate folds in the fabric create a writing...\n\n");
	master_display_spell_list(({"illusion"}));
	write("\nYou return the handerchief to Dycedakis.\n");
	say(ME+" examines Dycedakis' "+RED+"handkerchief"+NORM+".\n", tp);
	return 1;
  }
}


catch_tell(str)
{
  string who, what;

  if(sscanf(str, "%s says: train %s\n", who, what) == 2)
  {
	train_stat(what);
	return 1;
  }
  else if(sscanf(str, "%s says: teach %s\n", who, what) == 2)
  {
	teach_spell(what);
	return 1;
  }

}


train_stat(string stat)
{
  int x;

  if(!master_train_stat(stat, RED+"Dycedakis"+NORM, ({"illusion","necromancy"})))
	return 1;

  x = stat_increase_amount(stat);

  write(
    RED+"Dycedakis"+NORM+" says: Only fools would deny themselves the "+HIBLK+"darker powers"+NORM+" of magic\n"+
    "Even the "+HIW+"purest soul"+NORM+" casts a "+HIBLK+"shadow"+NORM+".  You must show "+CYN+"no fear"+NORM+
    " to these elements of magic!\n");
  say(RED+"Dycedakis"+NORM+" trains "+ME+" in the ways of "+HIC+stat+NORM+".\n", tp);

  write("Your "+HIC+stat+NORM+" increases "+HIM+x+"%"+NORM+"\n\n");
  guild->raise_guild_stat(stat, x);
  guild->add_training_sessions(-1);
  return 1;

}


teach_spell(what)
{
  int x;

  x = master_teach_spell(what, RED+"Dycedakis"+NORM, ({"illusion","necromancy"}));
  if(!x)
        return 1;

  write(
    RED+"Dycedakis "+NORM+HIBLK+"scowls"+NORM+" at you with his dark eyes.\n" +
    "The "+HIBLK+"Dark "+NORM+RED+"Master"+NORM+" drills you relentlessly until you learn.\n");
  write("You scribe the "+HIC+"new spell"+NORM+" into your "+CYN+"spellbook"+NORM+".\n\n");
  say(RED+"Dycedaki"+NORM+" teaches "+ME+" a "+HIC+"new spell"+NORM+".\n", tp);

  guild->add_new_spell_chances(-x);
  guild->add_spell(what);

  write_file(TRAINLOG, "["+ctime()[4..15]+"] "+capitalize(tp->query_real_name())+" (lvl:"+tp->query_level()+
    ") (rank:"+tp->query_guild_rank()+") learned spell '"+what+"'\n");

  return 1;

}

