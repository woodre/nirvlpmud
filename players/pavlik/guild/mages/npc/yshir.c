#include "/players/pavlik/guild/mages/defs.h"
inherit "/players/pavlik/guild/mages/inherit/masters";
inherit "/players/pavlik/guild/mages/inherit/advance";
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Yshir");
  set_alias("yshir");
  set_short(HIB+"Yshir "+NORM+BLU+"the Enchantress"+NORM);
  set_long(
	"A translucent beauty of blue and gold, Yshir the Enchantress\n"+
	"smiles upon you in your dream-like state.  Her long golden hair\n"+
	"flows over her shoulders and down her back. Her long blue and\n"+
	"gold gown sweeps quietly across the floor as she moves.\n"+
	"  Yshir holds a "+HIW+"silver harp"+NORM+" and a "+RED+"rose quartz"+NORM+" in her hands.\n");
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
  if(str == "silver harp" || str == "at silver harp")
  {
	write("Yshir gives you a silver harp so you can examine it.\n");
	write("The intricate patterns of silver and gold create a writing...\n\n");
	master_display_spell_list(({"conjuration"}));
	write("\nYou return the harp to Yshir.\n");
	say(ME+" examines Yshir's "+HIW+"silver harp"+NORM+".\n", tp);
	return 1;
  }
  if(str == "rose quartz" || str == "at rose quartz")
  {
	write("Yshir gives you a rose quartz so you can examine it.\n");
	write("The delicate veins of rosy quarts create a writing...\n\n");
	master_display_spell_list(({"enchantment"}));
	write("\nYou return the quartz to Yshir.\n");
	say(ME+" examines Yshir's "+RED+"rose quartz"+NORM+".\n", tp);
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

  if(!master_train_stat(stat, BLU+"Yshir"+NORM, ({"conjuration","enchantment"})))
	return 1;

  x = stat_increase_amount(stat);

  write(
    "You listen attentively as "+BLU+"Yshir"+NORM+" instructs you in the ways of magic.  The subtle\n" +
    MAG+"nuances"+NORM+" of magic seep into your mind as you practice again and again.\n");
  say(BLU+"Yshir"+NORM+" trains "+ME+" in the ways of "+HIC+stat+NORM+".\n", tp);

  write("Your "+HIC+stat+NORM+" increases "+HIM+x+"%"+NORM+"\n\n");
  guild->raise_guild_stat(stat, x);
  guild->add_training_sessions(-1);
  return 1;

}


teach_spell(what)
{
  int x;

  x = master_teach_spell(what, BLU+"Yshir"+NORM, ({"conjuration","enchantment"}));
  if(!x)
	return 1;

  write(
    HIB+"Yshir's "+NORM+HIY+"melodious"+NORM+" fills your head as she carefully explains the ways of magic.\n");
  write("You scribe the "+HIC+"new spell"+NORM+" into your "+CYN+"spellbook"+NORM+".\n\n");
  say(HIB+"Yshir"+NORM+" teaches "+ME+" a "+HIC+"new spell"+NORM+".\n", tp);

  guild->add_new_spell_chances(-x);
  guild->add_spell(what);

  write_file(TRAINLOG, "["+ctime()[4..15]+"] "+capitalize(tp->query_real_name())+" (lvl:"+tp->query_level()+
    ") (rank:"+tp->query_guild_rank()+") learned spell '"+what+"'\n");

  return 1;

}

