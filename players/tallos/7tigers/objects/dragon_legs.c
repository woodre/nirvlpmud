inherit "obj/armor";
#include "/players/jaraxle/define.h"
reset(arg){
   if(arg) return;
   ::reset();
   set_name("gold dragon leggings");
   set_alias("leggings");
   set_short(""+NORM+""+YEL+"Gold Dragon Leggings"+NORM+"");
   set_long("   A fine bunch of "+YEL+"gold dragon scales"+NORM+" forged\n"+
            "into a set of "+YEL+"leggings"+NORM+". They seem to vibrate\n"+
            "with great power. Many say that they provide\n"+
            "great "+HIG+"luck"+NORM+""+NORM+" to those who wear them.\n");
   set_ac(2);
   set_type("pants");
   set_weight(1);
   set_value(20000);
}

do_special(owner) {
   if(!owner || !owner->query_attack()) return 1;
   if(!owner->is_player()) return 1;
   if(random(owner->query_attrib("luc")) > random(70)) {
      tell_object(owner, HIY+"The luck of the dragons come through for you!\n"+NORM);
      owner->add_hit_point(random(5));
      return 1; 
      }
  }