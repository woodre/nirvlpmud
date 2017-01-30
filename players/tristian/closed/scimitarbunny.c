#include "/players/tristian/lib/ansi.h"
inherit"obj/weapon";
#define CO call_other


reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("A sledge hammer of Bunny Slaying");
    set_alias("hammer");
    set_short("A silver sledge hammer of "+HIB+"Bunny Slaying"+NORM);
    set_long("This sledge hammer is rather weak, unless used against it's\n"+
      "archnemesis, a cute, cuddly, defenseless bunny.\n");
    set_value(1);
    set_weight(1);
    set_class(5);
    set_hit_func(this_object());
}

weapon_hit(attacker) {
      if(check_race(attacker)){
       if(!attacker) return 1;
	   tell_room(environment(this_player()),HIY+"The sledgehammer glows as it smashes the bunnies brains into MUSH!\n"+NORM+
	   HIR+"BRAINS SPLATTER EVERYWHERE, SOME OF THEM LAND ON YOUR SHOES AND .... WHAT IS THAT ON YOUR CHEEK!!??!?!\n"+NORM);
       attacker->heal_self(-(100+random(10)));
     return 1;
   }
}

check_race(object ob) {
  if(CO(ob,"id","bunny")) return 1;
  else return 0;
}