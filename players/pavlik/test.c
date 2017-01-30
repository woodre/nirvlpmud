inherit "/obj/monster.c";
#include "/obj/ansi.h"

int hits;
int total_raw;
int total_dmg;
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("testmonster");
  set_short("A test monster");
  set_race("monster");
  set_alias("test");
  set_long("A test monster\n");
  set_level(20);
  set_ac(0);
  set_wc(0);
  set_hp(1000);
  set_heal(0,100);
  set_al(0);
  set_aggressive(0);
/*
  set_wander(1);
  set_wander_interval(10);
  set_wander_realm("players/pavlik");
  set_armor_params("other|fire", 0, 50, 0);
*/
  hits = 0;
  total_raw = 0;
  total_dmg = 0;
}


stop_fight()
{
  if(environment())
	tell_room(environment(), CYN+"[zeroing counters]\n"+NORM);
  hits = 0;
  total_raw = 0;
  total_dmg = 0;
  ::stop_fight();
}


do_damage(int *damage, string *method)
{
  int i;
  int raw;
  int dmg;

  hits++;

  if(!damage)
	return 0;

  i = sizeof(damage);
  while(i--)
  {
	raw += damage[i];
	total_raw += raw;
  }

  dmg = ::do_damage(damage, method);
  total_dmg += dmg;

  if(this_player() && environment(this_player()))
	tell_room(environment(this_player()),
	  HIC+"[RAW: "+HIW+raw+HIC+"    DMG: "+HIW+dmg+HIC+"]\n"+NORM+
	  CYN+"[hits: "+hits+"   tot/avg raw: "+total_raw+"/"+(total_raw/hits)+"   "+
	  "tot/avg dmg: "+total_dmg+"/"+(total_dmg/hits)+"]\n"+NORM);
  else if(this_object() && environment(this_object()))
	tell_room(environment(this_object()),
	  HIC+"[RAW: "+HIW+raw+HIC+"    DMG: "+HIW+dmg+HIC+"]\n"+NORM+
	  CYN+"[hits: "+hits+"   tot/avg raw: "+total_raw+"/"+(total_raw/hits)+"   "+
	  "tot/avg dmg: "+total_dmg+"/"+(total_dmg/hits)+"]"+NORM+" (this_object)\n");

  return dmg;
}

