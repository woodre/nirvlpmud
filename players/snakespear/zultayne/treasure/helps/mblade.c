#include <ansi.h>

inherit "obj/weapon";

reset(arg) {
   set_id("blade");
   set_name(HIW+"Blade of Mirrors"+NORM);
   set_class(19);
   set_weight(6);
   set_value(500);
   set_alt_name("mirrorblade");
   set_alias("sword");
   set_short(HIW+"Blade "+GRY+"of "+HIW+"Mirrors"+NORM);
   set_long("A bulky looking claymore with a thick, brass handle that wraps\n"+
            "around the user's hands for protection.  The long, heavy blade\n"+
            "relfects light like a mirror.  Light reflects off the sword\n"+
            "brightly.  The blade is free of scratches or cracks.\n"); 
   set_save_flag(1);
   set_hit_func(this_object());
   set_light(2);
}

query_wear() {
   return 1;
}

weapon_breaks() {
   return 1;
}


weapon_hit(attacker) {
   int hit;
   hit=random(100);
   if((attacker->id("demon") || attacker->id("spirit")) && !random(4)) {
      string bmess;
      bmess="\tThe "+name_of_weapon+HIY+" SHINES "+NORM+"brightly in the eyes of the demon!!!\n\n";
      tell_room(environment(this_player()),bmess+NORM);
      attacker->heal_self(-10);
      return 1;
   }
   if(hit < 10) {
      tell_object(attacker,"You see yourself in "+name_of_weapon+" and writhe in pain! .\n"+
                           "You spew"+HIG+" V O M I T "+NORM+", all over yourself!\n");
      say("The "+name_of_weapon+" frightens the hell out of "+attacker->query_name()+".\n"+
          attacker->query_name()+HIG+" V O M I T S "+NORM+" all over themself!!\n",attacker);
   return random(5)+5;
   }
   if(whack < 21) {
      tell_object(attacker,"You catch a glimpse of yourself in "+name_of_weapon+"\n");
      say(attacker->query_name()+"sees themself in the"+name_of_weapon+" only briefly.\n");
      return random(4)+4;
   }
   return 0;
}
