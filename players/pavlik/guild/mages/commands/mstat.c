#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/command";

reset(arg) {
  if(arg) return;
  set_verb("mstat");
  set_name("Mage Stat ");
  set_color_name(HIC+"Mage Stat"+NORM);
  set_rank(100);
  set_descrip(
	"The command will display a Mage's guild stats.\n"+
	"\n" +
	"This command is available only to wizards.\n"
  );
}


cmd(str)
{
  object ob, obj;
  string *dragon_str;
  int *dragon_stats;

  if(tp->query_level() < WIZLEVEL && tp->query_guild_rank() <= MAXGUILDRANK)
	return 0;

  if(!str)
  {
	notify_fail("Usage: mstat <name>\n");
	return 0;
  }

  if(!(obj = find_player(str)))
  {
	notify_fail("Could not find '"+str+"'.\n");
	return 0;
  }

  if(!(ob = present("mageobj", obj)))
  {
	notify_fail(capitalize(str)+" does not have a mage guild object.\n");
	return 0;
  }

  write("\n");
  write(obj->short()+"\n");
  write("Level          : "+obj->query_level()+"\n");
  write("Extra Level    : "+obj->query_extra_level()+"\n");
  write("Guild Rank     : "+obj->query_guild_rank()+"\n");
  write("Guild Exp      : "+obj->query_guild_exp()+"\n");
  write("Gdiv           : "+ob->query_divd()+"%\n");
  write("\n");
  write("Intelligence   : "+ob->query_guild_stat("intelligence")+"\t("+ob->query_guild_bonus("intelligence")+")\n");
  write("Power          : "+ob->query_guild_stat("power")+"\t("+ob->query_guild_bonus("power")+")\n");
  write("Wisdom         : "+ob->query_guild_stat("wisdom")+"\t("+ob->query_guild_bonus("wisdom")+")\n");
  write("Will Power     : "+ob->query_guild_stat("will power")+"\t("+ob->query_guild_bonus("will power")+")\n");
  write("\n");
  write("Conjuration    : "+ob->query_guild_stat("conjuration")+"\t("+ob->query_guild_bonus("conjuration")+")\n");
  write("Enchantment    : "+ob->query_guild_stat("enchantment")+"\t("+ob->query_guild_bonus("enchantment")+")\n");
  write("Evocation      : "+ob->query_guild_stat("evocation")+"\t("+ob->query_guild_bonus("evocation")+")\n");
  write("Necromancy     : "+ob->query_guild_stat("necromancy")+"\t("+ob->query_guild_bonus("necromancy")+")\n");
  write("\n");
  write("Spell Chances  : "+ob->query_new_spell_chances()+"\n");
  write("Training       : "+ob->query_training_sessions()+"\n");
  write("\n");

/*
  obj->set_dragon_descrip(
        lower_case(name)+"#"+dragon_short+"#"+follow_msg+"#"+dragon_long);
  obj->set_dragon_stats(
        dragon_level+"#"+dragon_exp+"#"+dragon_attack+"#"+dragon_defense+"#"+dragon_stamina+"#"+dragon_magic);
*/

  dragon_str = explode(ob->query_dragon_descrip(), "#");
  dragon_stats = explode(ob->query_dragon_stats(), "#");

  write("Dragon Name    : "+dragon_str[0]+"\n");
  write("Dragon Level   : "+dragon_stats[0]+"\n");
  write("Dragon Exp     : "+dragon_stats[1]+"\n");
  write("Dragon Attack  : "+dragon_stats[2]+"\n");
  write("Dragon Defense : "+dragon_stats[3]+"\n");
  write("Dragon Stamina : "+dragon_stats[4]+"\n");
  write("Dragon Magic   : "+dragon_stats[5]+"\n");
  write("\n");

  return 1;
}

