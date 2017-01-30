inherit "/obj/monster";
#include "/players/zeus/closed/all.h"

reset(arg) {
	::reset(arg);
   if (!arg) {

  set_name("bandit guard");
  set_alt_name("bandit");
  set_alias("guard");
  set_short("A bandit guard");
  set_long(
"This is a very powerful bandit guard.  He is here to make sure that only\n"+
"newbies enter this area.  If you attack him, you get the feeling that you\n"+
"will die.  He is wearing a brownish vest and torn pants.  A dark glint\n"+
"can be seen in his eyes.  ");
  set_race("human");
  set_level(20);
  set_ac(20);
  set_wc(75);
  set_hp(1100);
  set_heal(20,1);
  set_gender("male");
  set_chance(40);
  set_spell_dam(50+random(300));
  set_spell_mess1("The guard rips into you!\n");
  set_spell_mess2("The guard rips into you!\n");
  set_chat_chance(4);
  load_chat("The bandit says:  Why are you here?\n");
  load_chat("The bandit says:  Attack me and you shall die.\n");
  load_chat("The bandit says:  Only level 6 and under may pass.\n");
  load_chat("The bandit grins at you.\n");
  set_dead_ob(TO);
}  }

heart_beat(){
    ::heart_beat();
   if(!environment()) return ;
   if(!AO) return ;
   if(!AO->query_ghost()){
	  already_fight = 0; ::attack();
   }
   if(AO == TO){
	  TO->stop_fight();
	  MO(TO, "/players/zeus/newbie/swamp/s13.c");
	  return ;
   }
}

