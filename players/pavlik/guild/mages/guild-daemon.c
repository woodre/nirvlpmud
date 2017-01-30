#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/string.h"
#include "/players/pavlik/guild/mages/spells2/guild_channel"
inherit "players/pavlik/guild/mages/inherit/advance";

int spell_level;
string school;
string name;
int num;

reset(arg)
{
  move_object(this_object(), "players/pavlik/guild/mages/rooms/master_room");
}

id(str){
  return str == "mage-master" || str == "mage_master";
}

drop(){ return 1; }
get(){ return 1; }
short(){ return "The Mage-Master"; }
long(){
  write("The Mage-Master.\n");
  return;
}

/* GOB VERSION */
query_gob_version(){ return GOB_VERSION; }

/* AUTOSAVE */
mage_autosave()
{
  object ob, obj;
  int i;
  ob = users();
  for(i=0; i<sizeof(ob); i++)
  {
	if(ob[i] && environment(ob[i]))
	{
		if(obj = present("mageobj2", ob[i]))
		{
			obj->calculate_exp();
			if(!in_editor(ob[i]))
				tell_object(ob[i], "Autosaving Mage Soul ... ok.\n");
			obj->mage_autosave();
		}
	}
  }
  call_out("mage_autosave", 600);
  return 1;
}


/*
 * Calculate % Pts of Guild Stat Increase
 */
stat_increase_amount(str) {
  int stat, amount;

  if(str == "wis") stat = guild->query_wisdom();
  if(str == "wil") stat = guild->query_will_power();

  amount = 0;

  /* if stat is really low then start amount at 3 */
  if(stat < 18) amount += 3;

  amount += 1 + random(stat)/6 + random(3);
  if(amount < 1) amount = 1;
  if(amount > 7) amount = 7 + random(3);
  
  return amount;
}

/*
 * MAX DONATION
 * If a Mage goes over 50,000 donation points the point total is reduced
 * and the player is rewarded with a sum of coins.
 */
max_donation() {
  object m;
  int i;
  i = 3000 + random(4000);
  if(!tp) return;
  write("You recieve "+i+" "+HIM+"guild exp"+NORM+" for your devotion to the guild.\n");
  write("Resetting Donation Points ... ok.\n");
  guild->add_donation(-(guild->query_donation()/2));
  tp->add_guild_exp(i);
  return 1;
}


/* EOF */
