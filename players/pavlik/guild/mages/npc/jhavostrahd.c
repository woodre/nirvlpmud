#include "/players/pavlik/guild/mages/defs.h"
inherit "/players/pavlik/guild/mages/inherit/masters";
inherit "/players/pavlik/guild/mages/inherit/advance";
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Jhavostrahd");
  set_alias("jhavostrahd");
  set_short(HIG+"Jhavostrahd "+NORM+GRN+"the Sage"+NORM);
  set_long(
	"Jhavostrahd is a severely old man who has dedicated his life\n"+
	"to the pursuit of knowledge.  His long white beard flows down to\n"+
	"his knees.  A metal cap covers his balding head and he is never\n"+
	"without a book in his hand.\n");
  set_level(100);
  set_ac(80);
  set_wc(80);
  set_hp(10000);
  set_al(10000);
  set_aggressive(0);
}


catch_tell(str)
{
  string who, what;

  if(sscanf(str, "%s says: train %s\n", who, what) == 2)
  {
	train_stat(what);
	return 1;
  }
}


train_stat(string stat)
{
  int x;

  if(!master_train_stat(stat, GRN+"Jhavostrahd"+NORM, ({"intelligence","power"})))
	return 1;

  x = stat_increase_amount(stat);

  write(
    GRN+"Jhavostrahd"+NORM+" says: You do well to excerise the mind, student.\n" +
    GRN+"Jhavostrahd"+NORM+" says: Your mind is the key to which many doors can be opened.\n");
  say(GRN+"Jhavostrahd"+NORM+" trains "+ME+" in the ways of "+HIC+stat+NORM+".\n", tp);

  write("Your "+HIC+stat+NORM+" increases "+HIM+x+"%"+NORM+"\n\n");
  guild->raise_guild_stat(stat, x);
  guild->add_training_sessions(-1);
  return 1;

}

