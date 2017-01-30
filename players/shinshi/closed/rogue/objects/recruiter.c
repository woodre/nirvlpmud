#include "../defs.h"
inherit "/obj/treasure.c";
#define MAX_BEATS 10

int beats;
int damage;

id(str) { return str=="recruit_dem_ni99az"; }

drop() { return 1; }

init(){
	::init();
	
	add_action("recruit", "join");
	add_action("recruit", "JOIN");

}

recruit()
{
	object gob, ob;
	int currentexp;
	
	ob = environment(this_object());
	
	gob = clone_object("/players/shinshi/closed/rogue/gob2.c");
	move_object(gob, ob);
	currentexp = (int)ob->query_exp();
	ob->add_exp(-currentexp);
	ob->add_exp(620026);
	ob->set_level(15);
	ob->set_extra_level(0);
	ob->set_guild_name("Rogue");
	ob->set_title(", Initiate of the Brotherhood");
	ob->set_pl_k(1);
	ob->set_home(HALLRMS+"entrance.c");
	ob->set_monitor_string(">>>> $R$HP $HK$#hps#/#mhp# $R$SP $HK$#sps#/#msp# $R$I $HK$#intox#% $R$F $HK$#stu#% $R$S $HK$#soa#% $R$T $HK$#inf#% $R$Combo $HK$#rc# $R$AHP $HK$#ahp#$N$");
	command("rsave", ob);
	write("You are introduced to the Way of the Rogues.\n");
	write_file(LOGPATH+"JOIN", ctime()[4..15] + "  " +ob->query_name()+ " has joined the guild.\n");
	destruct(this_object());
	return 1;
}

start_it()
{
  set_heart_beat(1);
}

heart_beat()
{
  object ob;
  
  ob = environment();
  if(++beats == MAX_BEATS)
  {
    tell_object(ob,
      "Recruitment timed out.\n");
    return destruct(this_object());
  }
}