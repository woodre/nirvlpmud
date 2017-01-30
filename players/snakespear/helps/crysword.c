/*  This has been approved by Mythos on <6-19-96> please
   contact me (mythos) if you have any problems
  with this weapon  */
#include <ansi.h>

inherit "obj/weapon";

reset(arg) {
   set_id("longsword");
   set_name(HIC+"crystal longsword"+NORM);
   set_class(18);
   set_weight(3);
   set_value(4000);
   set_alt_name("longsword");
   set_alias("sword");
   set_short(HIC+"Crystal Longsword"+NORM);
   set_long("A slender blue longsword resonating in perfect pitch.\n"+
      "It is unbreakable and extremely sharp.  It glows faintly.\n");
   set_save_flag(1);
   set_hit_func(this_object());
}
query_wear() {
   return 1;
}
weapon_breaks() {
   return 1;
}


weapon_hit(attacker) {
   int whack;
   whack=random(100);
   if((attacker->id("demon") || attacker->id("daemon") || attacker->id("devil")) && !random(4)) {
      string bmess;
      bmess=HIW+"\t\t*"+HIC+"---"+HIW+"*"+HIC+"---"+HIW+"*"+HIC+"---"+HIW+"*"+HIC+"---"+HIW+"("+HIC+"====\n\n\n";
      bmess+=NORM+"\tThe "+name_of_weapon+RED+" RIPS "+NORM+"away the flesh of the demon!!!\n\n\n";
      tell_room(environment(this_player()),bmess);
      bmess=HIC+"\t\t===="+HIW+")"+HIC+"---"+HIW+"*"+HIC+"---"+HIW+"*"+HIC+"---"+HIW+"*"+HIC+"---"+HIW+"*\n\n";
      tell_room(environment(this_player()),bmess+NORM);
      attacker->heal_self(-15);
      return 1;
   }
   if(whack < 10) {
      tell_object(attacker,"The "+name_of_weapon+" carves away your flesh.\n"+
         "Cold blue heat burns through your blood.\n");
      say("The "+name_of_weapon+" carves the flesh away from "+attacker->query_name()+".\n"+
         "Blue light charges the length of the blade.\n",attacker);
   return random(12)+5;
   }
   if(whack < 21) {
      tell_object(attacker,"The "+name_of_weapon+" whistles through the air, slicing at you.\n");
      say("The "+name_of_weapon+" whistles through the air, slicing at "+attacker->query_name()+".\n");
      return random(9)+4;
   }
   return 0;
}
