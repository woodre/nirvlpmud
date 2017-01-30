#include "/players/mythos/closed/guild/def.h"
inherit "players/mythos/closed/guild/spells/monster2";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("guardian_demon");
  set_race("demon");
  set_alias("guardian");
  set_short("GUARDIAN");
  set_long(HIB+"The GUARDIAN of the HALL.\n"+NORM);
  set_hp(1000);
  set_level(30);
  set_dead_ob(this_object());
  set_al(-1000);
  set_exx(0);
  set_wc(18);
  set_ac(10);
  set_heal(2,20);
  set_aggressive(0);
  set_a_chat_chance(15); 
  load_a_chat("The GUARDIAN lets out a ROAR!\n");
  call_out("cmd",10);
}

cmd() {
int wcn, acn, m;
object fool;
    this_object()->set_heal(2,20);
    if(!(this_object()->query_attack())) {
    this_object()->set_wc(18);
    this_object()->set_ac(10); }
	if(this_object()->query_attack()) {
	wcn = this_object()->query_wc();
	acn = this_object()->query_ac();
	this_object()->set_wc(wcn+1);
	this_object()->set_ac(acn+1);
	tell_room(environment(this_object()),"The GUARDIAN grows stronger!\n");
		fool=all_inventory(environment(this_object()));
	for(m=0;m<sizeof(fool);m++) {
		if(living(fool[m]) && fool[m]->query_ghost() !=1 && 
		!present(fear,fool[m]) &&
		  fool[m]->query_attack() && !(fool[m]->id("guardian_demon"))) {
			fool[m]->heal_self(1+random(5));
		}
		}
		}
	call_out("cmd",10); 
	return 1;}

monster_died() {
  object ob;
  int n;
  ob = users();
  for(n=0;n<sizeof(ob);n++) {
  if(present(fear,ob[n])) {
  tell_object(ob[n],HIR+"GUARDIAN has been killed by a "+
  (this_object()->query_attack())->query_guild_name()+"!\n"+NORM);
  } }
return 0;
}
