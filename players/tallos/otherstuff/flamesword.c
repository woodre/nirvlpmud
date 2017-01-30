/* 10/10/05 Earwax: Changed the long desc.  It sucked. */

/* Sword for /players/bastion/monster/demon6 */
#include "/open/ansi.h"

inherit "obj/weapon";

reset(arg) {
     ::reset(arg);
     set_name("sword");
     set_alt_name("longsword");
     set_short(HIR+"A flaming longsword"+NORM);
/*
     set_long("It is a black blade, sharp as chaos' darkness, and bathed\n"+
              "in flame at command.\n");
*/
     set_long("The flame-wrapped blade is as black as midnight \nand as sharp as the darkness of chaos.\n");
     set_class(20);
     set_weight(4);
     set_value(10000); 
     set_hit_func(this_object()); }


weapon_hit(attacker) {
     object what;
     if(random(100) > 90) {
          write("You sword grows red hot in your hands.\n");
          this_player()->add_hit_point(2);
          this_player()->add_spell_point(2);
          return 3; }
     if(random(100) < 20) {
          what=this_player()->query_attack();
          write("You massacre " + what->query_name() +
               " to small fragments.\n");
          say(this_player()->query_name() + " massacres " +
              what->query_name() + " to small fragments.\n");
          return 6; }
}

