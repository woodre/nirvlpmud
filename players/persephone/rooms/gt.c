inherit "obj/weapon.c";
#include "/players/persephone/rooms.h"
reset(arg) {
    ::reset();
    if (arg) return;
    set_name("gavel");
    set_alias("hammer");
    set_short("An Auctioneer's Gavel");
    set_long("A gavel made out of wood with some arcane writing on it.\n");
    set_class(14);
    set_save_flag(0);
    set_weight(1);
    set_value(1200);
    set_hit_func(this_object());
}
weapon_hit(attacker){
    if(attacker->query_name() == "vvladimir") {
      say (CAPTPLNM + " brings the Gavel down fiercely on Vvladimir's head\n");
      write("You pound Vvladimir with the gavel stunning him for a moment\n");
      attacker->hit_player(random(60));
      return 1;
   }
   return;
}
