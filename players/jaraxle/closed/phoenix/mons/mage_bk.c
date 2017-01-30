#include "/players/jaraxle/define.h"
#include "/players/jaraxle/closed/phoenix/mons/heal.h"
inherit "/players/vertebraker/closed/std/monster.c";
reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   get_random_heals();
   set_name("vulpine mage");
   set_alias("mage");
   set_alt_name("vulpine");
   set_race("fox");
   set_short("Vulpine "+MAG+"Mage"+NORM);
   set_long(
      "  A slender creature with the head of a fox,\n"+
      "upright ears, and a pointed snout. It stands\n"+
      "on two hind legs and seems very dextrous. A\n"+
      "long bushy tail swaggers through the split of\n"+
      "its long robe which gives it great balance.\n");
   set_level(18);
   set_hp(400+random(51));
   set_al(0);
   set_wc(26);
   set_ac(15);
   set_aggressive(0);
   set_chance(20);
   set_spell_dam(30+random(16));
   
   set_spell_mess1(
      "\n\nThe Mage summons a storm of "+BLK+BOLD+"ash"+NORM+" and "+RED+"brimstone"+NORM+" over the room!\n");
   set_spell_mess2(
    "\n\nThe Mage summons a storm of "+BLK+BOLD+"ash"+NORM+" and "+RED+"brimstone"+NORM+" over the room!\n"+
HIR+"\tThe ashen storm burns your body!\n"+NORM);
   set_dead_ob(this_object());
   
}
monster_died() {
   tell_room(environment(this_object()), "The Fox crashes to the ground lifeless.\n");
   return 0; }
