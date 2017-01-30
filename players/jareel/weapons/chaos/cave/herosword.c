inherit "obj/weapon";

#include "/players/jareel/define.h"

object ob;
int limit = 4;  

  reset(arg) {
    ::reset(arg);
    if(arg) return;

    set_id("sword");
    set_alias("longsword");
    set_short("Truth Seeker");
    set_long(
       "Truth Seeker is rolled Valerian steel forged from the fire of dragons breath\n"+
       "and edged into this finely crafted instrument of death.  This is a blade has\n"+
       "been called the sword of 1000 cuts as it fillets the skin of its foes.\n");
    set_weight(2);
    set_class(10);
    set_value(2000);
    set_type("sword");

    message_hit = ({ 
      HIK+"slashed"+NORM," across the arm",
      HIK+"gashed"+NORM," on the hand",
      HIK+"cut"+NORM," in the knee",           
      HIK+"impaled"+NORM," in the stomach",
      HIK+"stabbed"+NORM," in the body",
      HIK+"slashed"+NORM," in the knee",
      HIK+"gashed"+NORM," in the leg"
      });
     set_hit_func(this_object());
}

     init() {
       ::init();
}


weapon_hit(attacker) {

  if (TPRN == "hero" || (this_player() != environment(this_object())))
    return;
  if (random(100) < 30 && limit--)
  {
    limit = 4;
    return 3;
  }
}
