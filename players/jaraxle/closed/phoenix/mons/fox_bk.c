#include "/players/jaraxle/define.h"
#include "/players/jaraxle/closed/phoenix/mons/heal.h"
inherit "/players/vertebraker/closed/std/monster.c";
reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   arm_me();
   get_random_heals();
   set_name("vulpine warrior");
   set_alias("warrior");
   set_alt_name("vulpine");
   set_race("fox");
   set_short("Vulpine Warrior");
   set_long(
      "  A slender creature with the head of a fox,\n"+
      "upright ears, and a pointed snout. It stands\n"+
      "on two hind legs and seems very dextrous. A\n"+
      "long bushy tail grows out from the small of\n"+
      "its back which gives it great balance.\n");
   set_level(20);
   set_hp(480+random(36));
   set_al(0);
   set_ac(15);
   set_aggressive(0);
   set_chance(12);
   set_spell_dam(20+random(26));
   
   set_spell_mess2(
      "\nThe Warrior lunges in and "+HIR+"chomps"+NORM+" its jaws over your neck.\n");
   set_dead_ob(this_object());
   
}
monster_died() {
   tell_room(environment(this_object()), "The Fox crashes to the ground lifeless.\n");
   return 0; }

arm_me(){
   switch(random(5)){
      case 0:
      "/players/jaraxle/closed/weapon/wep_gen.c"->get_wep(this_object(), 70000);
      break;
      case 1..4: return 0;
      break;
   }
   command("wield weapon with both hands",this_object());
   command("wield weapon",this_object());
   set_wc(30);
   return 1; }
