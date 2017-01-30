#include "/players/pavlik/guild/mages/defs.h"
inherit "/players/pavlik/guild/mages/inherit/masters";
inherit "/players/pavlik/guild/mages/inherit/advance";
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Ansari");
  set_alias("ansari");
  set_short(HIY+"Ansari "+NORM+YEL+"the Evoker"+NORM);
  set_long(
	"Ansari stands nearly seven feet tall.  His long narrow limbs might\n"+
	"appear awkward on another body but they simple heighten the\n"+
	"subtle elegance of Ansari's nature.  His dark hands move gracefully\n"+
	"through the air as he speaks.  He is clothed in a simple robe of\n"+
	"green cloth and a golden earring twinkles from his left ear-lobe.\n"+
	"   Ansari holds an "+YEL+"autumn leaf"+NORM+" in his hand.\n");
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
  if(str == "autumn leaf" || str == "at autumn leaf")
  {
	write("Ansari gives you an autumn leaf so you can examine it.\n");
	write("The delicate veins of the leaf create a writing...\n\n");
	master_display_spell_list(({"evocation"}));
	write("\nYou return the leaf to Ansari.\n");
	say(ME+" examines Ansari's "+YEL+"autumn leaf"+NORM+".\n", tp);
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

  if(!master_train_stat(stat, YEL+"Ansari"+NORM, ({"evocation"})))
	return 1;

  x = stat_increase_amount(stat);

  write(
    YEL+"Ansari"+NORM+" says: You must be able to sense the magic that every object in our world\n" +
    "possess.  Then you will be able to unite the energies and create great things.\n");
  say(YEL+"Ansari"+NORM+" trains "+ME+" in the ways of "+HIC+stat+NORM+".\n", tp);

  write("Your "+HIC+stat+NORM+" increases "+HIM+x+"%"+NORM+"\n\n");
  guild->raise_guild_stat(stat, x);
  guild->add_training_sessions(-1);
  return 1;

}


teach_spell(what)
{
  int x;

  x = master_teach_spell(what, YEL+"Ansari"+NORM, ({"evocation"}));
  if(!x)
	return 1;

  write(
    HIY+"Ansari"+NORM+" cups an "+YEL+"autumn leaf"+NORM+" in his hands and blows it into the air.  As the leaf\n" +
    "swirls about on invisible currents the "+HIM+"Master Evoker"+NORM+" teaches you the ways of magic.\n");
  write("You scribe the "+HIC+"new spell"+NORM+" into your "+CYN+"spellbook"+NORM+".\n\n");
  say(HIY+"Ansari"+NORM+" teaches "+ME+" a "+HIC+"new spell"+NORM+".\n", tp);

  guild->add_new_spell_chances(-x);
  guild->add_spell(what);

  write_file(TRAINLOG, "["+ctime()[4..15]+"] "+capitalize(tp->query_real_name())+" (lvl:"+tp->query_level()+
    ") (rank:"+tp->query_guild_rank()+") learned spell '"+what+"'\n");

  return 1;

}

