#include "../defs.h"
inherit "obj/weapon";
int i;
reset(arg) {
   ::reset(arg);
   if(arg) return;
    set_name(HIK+"Double-Bladed BattleAxe"+NORM);
    set_short(HIK+"Double-Bladed BattleAxe"+NORM);
    set_alias("battleaxe");
     set_long(HIW+"A large double-bladed battleaxe.  This weapon is very well taken\n"+NORM+
    HIW+"care of.  It's blades are both set up in an arch with strange scriptures\n"+NORM+
    HIW+"on the surface otf them that are completely foreign to you.  There is a\n"+NORM+
     HIW+"large spike protruding from the top of the shaft that runs through\n"+NORM+
     HIW+"the entire length of the weapon and is rounded off at the bottom of\n"+NORM+
     HIW+"pommel where the grip is wrapped in a strange leather. This\n"+NORM+
     HIW+"weapon is incredibly dangerous.\n"+NORM);
    set_class(15);
    set_weight(3);
    set_value(250);

      set_hit_func(this_object());
}
weapon_hit(attacker) {
    i=random(15);
    if (i>13) {

     write("You swing the"+HIK+"BattleAxe"+NORM+" high into the air and...\n"+
      HIW+"           <%> <%> <%> <%> <%> <%> <%> <%> <%> <%> <%> <%>\n"+NORM+
    HIW+"            <%> <%> <%> <%>   C  L  E  A  V  E   <%> <%> <%> <%>\n"+NORM+
      HIW+"           <%> <%> <%> <%> <%> <%> <%> <%> <%> <%> <%> <%>\n"+NORM+
     attacker->query_name()+" into "+HIR+" tiny slabs.\n"+NORM);
    say(this_player()->query_name()+HIW+" murders "+NORM+ attacker->query_name()+" into "+HIR+" tiny slabs.\n"+NORM);

    return 4;
    }
   return 0;
}
