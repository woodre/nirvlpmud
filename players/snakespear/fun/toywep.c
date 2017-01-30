#include <ansi.h>

inherit "obj/weapon";

reset(arg) {
   set_id("axe");
   set_name(HIB+"Djinn "+HIY+"Battle Axe"+NORM);
   set_class(18);
   set_weight(6);
   set_value(2000);
   set_alt_name("axe");
   set_alias("battle axe");
   set_short(HIB+"Djinn "+HIY+"Battle Axe"+NORM);
   set_long("A large battle axe with a "+HIB+"j"+HIY+"e"+HIG+"w"+HIW+"e"+HIR+"l"+HIM+"e"+HIC+"d"+NORM+" hilt.  It looks heavy and\n"+
            "and is unbreakable and extremely sharp.  It glows faintly.\n");
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
      bmess=HIB+"The Axe "+BLINK+"EVICIRATES "+NORM+HIY+attacker->query_name()+HIB+" with a mighty swing!\n";
      tell_room(environment(this_player()),bmess+NORM);
      attacker->heal_self(-15);
      return 1;
   }
   if(whack < 49) {
      tell_object(attacker,"The "+name_of_weapon+" thrashes your intestines!\n"+
         HIB+"Cold flames "+NORM+"surround you.\n");
      say("The "+name_of_weapon+" thrashes "+attacker->query_name()+".\n"+
         HIB+"Blue energy "+NORM+"sparks from the axe.\n",attacker);
   return random(3)+5;
   }
   if(whack > 50) {
      tell_object(attacker,"The "+name_of_weapon+" nearly decapitates you!\n");
      say("The "+name_of_weapon+" nearly decapitates "+HIY+attacker->query_name()+"!\n"+NORM);
      return random(2)+4;
   }
   return 0;
}
