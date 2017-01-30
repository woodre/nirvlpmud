/*  NPC summoned by the mage, can not be peaced.  */

inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
object nmy;

reset(arg) {
   ::reset(arg);
   if (!arg) {

  set_name("ice horror");
  set_alias("horror");
  set_short(HIB+"An ice horror"+NORM);
  set_race("creature");
  set_gender("creature");
  set_long(
"This is an evil ice horror.  It is a very simple creature, created by\n"+
"magic to aid its master in combat.  It is a very large and tough\n"+
"creature, about 7 feet tall with a massive body and limbs.  Its eyes\n"+
"are glowing a dark redish color.  It looks very angry to be here.\n");
  set_wc(55);
  set_wc_bonus(3);
  set_ac(14);
  set_level(20);
  set_hp(200);
  set_aggressive(1);
  set_al(-200);
  set_chat_chance(4);
  set_a_chat_chance(1);
  load_chat("The ice monger glares at you.\n");
  load_chat("The ice monger stands still.\n");
  load_chat("The ice monger doesn't move.\n");
  load_chat("The ice monger drips water onto the ground.\n");
  load_a_chat("The ice monger hits you with a crushing blow!\n");
   }
}


attack_special(){
  TR(environment(TO),
    "The ice horror pounds "+AO->QN+" with its massive fists...\n"+
    AO->QN+" staggers backwards from the powerful blows...\n", 
    ({AO}));
  tell_object(AO,
    "The ice horror pounds you with its massive fists...\n"+
    "You stagger backwards from the powerful blows...\n");
  AO->hit_player(30+random(11));
  return 1;
}



heart_beat(){
  ::heart_beat();
  if(!environment()) 
    return ;
  if(AO)
  {
    nmy = AO;
    if(!random(10)){   attack_special();  return ;  }
    return ;
  }
  if(!AO && nmy)
  {
    if(present(nmy, environment()))
    {
      if(nmy->query_ghost()) return;
      TR(environment(), 
        "The ice horror roars in anger at "+nmy->QN+"!\n\n");
      TO->attack_object(nmy);
      return ;
    }
  }
}
