#include "/players/mythos/closed/guild/def.h"
inherit "players/mythos/closed/guild/spells/monster2";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_alias("messenger");
  set_hp(10000);
  set_level(30);
  set_al(-1000);
  set_exx(0);
  set_wc(0);
  set_ac(1000);
  set_heal(2,20);
  set_aggressive(0);
  call_out("cmd",10);
}

cmd() {
	object fool;
	int m;
  if(!environment(this_object())) return 1;
		fool=all_inventory(environment(this_object()));
	for(m=0;m<sizeof(fool);m++) {
		if(living(fool[m]) && fool[m]->query_ghost() !=1 && 
		!present(fear,fool[m]) &&
		  fool[m]->query_attack() && !(fool[m]->id("guardian_demon"))) {
			if(0 == random(3)) {
			tell_object(fool[m],HIG+"You see a bright flash...\n"+
			"There is pain in your arm...\n"+NORM);
			command("drop "+fool[m]->query_weapon(),fool[m]); }
		}
		}
	call_out("cmd",10); 
	return 1;}
