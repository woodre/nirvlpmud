#include "/players/pavlik/guild/mages/defs.h"
inherit "/players/pavlik/guild/mages/inherit/masters";
inherit "/players/pavlik/guild/mages/inherit/advance";
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Buepaya");
  set_alias("buepaya");
  set_short(HIM+"Buepaya "+NORM+MAG+"the Serene"+NORM);
  set_long(
	"Before you is a short wrinkled old woman.  She sits cross-legged\n"+
	"on the floor and slowly breathes the incense that fills the\n"+
	"air around you.  You can't help to be overcome be a calmness\n"+
	"and serenity when in her prescence.\n");
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

  if(!master_train_stat(stat, MAG+"Buepaya"+NORM, ({"wisdom","will power"})))
        return 1;

  x = stat_increase_amount(stat);

  write(
    MAG+"Buepaya"+NORM+" says: Sit with me, student.  Magic is only as powerful as the mind\n"+
    "that wields it.  Clear your thoughts and feel the consciousness of everything\n"+
    "that surrounds you.\n");
  say(MAG+"Buepaya"+NORM+" trains "+ME+" in the ways of "+HIC+stat+NORM+".\n", tp);

  write("Your "+HIC+stat+NORM+" increases "+HIM+x+"%"+NORM+"\n\n");
  guild->raise_guild_stat(stat, x);
  guild->add_training_sessions(-1);
  return 1;

}

