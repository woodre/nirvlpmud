#include "../defs.h"
inherit "obj/weapon";
int i;
reset(arg) {
   ::reset(arg);
   if(arg) return;
    set_name("Quarterstaff");
    set_short("Quarterstaff");
    set_alias("staff");
    set_long(HIW+"A long narrow quarterstaff.  It is made from oak and is incredibly\n"+NORM+
    HIW+"strong.  The staff is completely solid and could deliver someone quite\n"+NORM+
     HIW+"a blow if used by the right hands. It's suprisingly light-weight.\n"+NORM);
    set_class(14);
    set_weight(2);
    set_value(145);

      set_hit_func(this_object());
}
weapon_hit(attacker) {
    i=random(10);
    if (i>9) {

    say(this_player()->query_name()+HIW+" s w e e p s "+NORM+ attacker->query_name()+" off their feet.\n");
    write("You "+HIW+" s w e e p "+NORM+ attacker->query_name()+" off their feet.\n");

    return 3;
    }
   return 0;
}
