inherit "/obj/monster";
#include <ansi.h>

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name("fire beetle");
     set_alt_name("beetle");
     set_short("Fire Beetle");
     set_race( "insect");
     set_gender("creature");
     set_long("The fire beetle has a pair of glowing spots along its\n"+
              "eyes and one near the back of its abdomen. The spots are\n"+
              "glowing a firey red, keeping the area lit and warm.\n");
     set_level(9);
     set_ac(7);
     set_wc(11 + random(4));
     set_hp(125 + random(30));
     set_al(-200);
     set_aggressive(0);
     set_chat_chance(15);
     set_a_chat_chance(25);
     load_chat("The fire beetle "+HIR+"glows"+NORM+" softly.\n");
     load_a_chat("The fire beetle snaps at you with its mandibles.\n");
     load_a_chat("The fire beetle charges at you.\n");

   }
}

monster_died() {
object ob;
ob = clone_object("/players/daranath/items/fire_spot.c");
  move_object(ob,this_environment());
return 0;
}
