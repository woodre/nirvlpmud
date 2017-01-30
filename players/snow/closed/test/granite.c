/*
 * Granite, the first monster in the test.
 */

inherit "/obj/monster";
#include "/players/snow/closed/color.h"

object testvic;

reset(arg) {
   ::reset(arg);
   if (!arg) {
 
     set_name("granite");
    set_short(BOLD+"Granite"+OFF);
     set_race("first");
     set_alias("gran");
     set_long(
"\tYou look upon Granite, the first in your test of might.\n"+
"This creature stands 4 meters in height, is 2 meters in width,\n"+
"and seems to be made of solid granite. \n");
     set_level(25);
     set_ac(40);
     set_wc(40);
     set_hp(3000);
     set_heal(1,1);
     set_al(0);
     set_aggressive(1);
     set_dead_ob(this_object());
set_chance(40);
  set_spell_mess1(
"\tGranite pounds his foe with fists of stone!");
  set_spell_mess2(
"\tGranite pounds you with fists of stone!");
/* added +26R - Jaraxle [9/6/03] */
set_spell_dam(30+random(26));
   }
}


heart_beat() {
  ::heart_beat();
  find_victim();

/* Multiple hit addition to keep players from idle killing
   this NPC - this is a Fucking combat test. They
   should pay attention not smoke a joint while killing
   these guys - Jaraxle [9/6/03] */

  if(random(100) < 30){
    if(attacker_ob && !attacker_ob->query_ghost()){
      already_fight=0;
      tell_object(attacker_ob,
"Granite swings his arms back up and "+BOLD+"crashes"+OFF+" his fists\n\tup into your chin!\n");
      tell_room(environment(),
"Granite swings his arms back up and "+BOLD+"crashes"+OFF+" his fists\n\tup into "+attacker_ob->query_name()+"'s chin!\n",
      ({attacker_ob}));
      attack();
      }
   }
/* End of multiple hit */
  check_self(); }
monster_died() {
  object flame;
  flame = clone_object("/players/snow/closed/test/flame.c");
  tell_room(environment(this_object()),
    "\tGranite collapses into a heap of rubble!\n\n"+
    "\tYou have passed the first test of might!\n\n");
  tell_room(environment(this_object()),
    "Flame rises up before you!\n");
  move_object(flame,this_object());
  flame->attack_object(testvic);
  flame->set_testvic(testvic);
    extra_xp(attacker_ob);
    logMyDeath();
  return 0;
}

#include "defenses.h"
#include "logme.h"
