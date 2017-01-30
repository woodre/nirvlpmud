/* Unique to itself atm */

#include "/players/jareel/define.h"
inherit "/obj/armor.c";

object ob;
#define USER environment(this_object())
#define ATT USER->query_attack()


reset(arg) {
   ::reset(arg);
   set_short(HIK+"Demon Tentacles "+NORM+"["+HIY+"Sun Forged"+NORM+"]"+NORM);
   set_ac(1);
   set_light(1);
   set_value(40000);
   set_weight(1);
   set_type("misc");
   set_name("tentacles");
   set_long(
      "Demon Tentacles are forged in the sun fires of Yelm. An ancient practice\n"+
      "that turns chaotic flesh into a protective shell.\n");
}


do_special(owner)
{
   if(!ATT) return;
   if(random(105) < USER->query_attrib("mag")) {
      if(ATT->is_npc()) 
         ATT->heal_self(-(5+random(4)));
      else ATT->add_hit_point(-(5+random(4)));
      tell_room(environment(USER),
         CAP(ATT->query_name())+" is squeezed by "+USER->query_name()+"'s flowing Demonic Tentacles.\n");      
      return 0;}
   return 0;}
