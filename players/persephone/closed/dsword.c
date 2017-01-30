inherit "obj/weapon.c";
#include "/players/persephone/rooms.h"
reset(arg) {
    ::reset();
    if (arg) return;
    set_name("stormcleaver");
    set_alias("sword");
    set_short("The Legendary Stormcleaver");
    set_long("Stormcleaver is a sword unlike any other you have ever seen\n" +
             "It is reputed to on a special command leap out of your\n" +
             "hands and dance it however can only ever be used by its\n" +
             "true owner\n\n");
    set_class(20);
    set_weight(3);
    set_value(155000);
    set_hit_func(this_object());
}
id(str) { return str == "stormcleaver"; }
weapon_hit(attacker){
   if(call_other(this_player(), "query_attrib", "str") > random(25)) {
      write("You start to slice up your foe like a Sunday Roast.\n");
      write("The Blade of the knife slices deeply into your opponent.\n");
      attacker->hit_player(15);
      return 1;
   }
   return;
}
