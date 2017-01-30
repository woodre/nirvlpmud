#include "/players/jaraxle/define.h"
#include "/players/jaraxle/closed/phoenix/mons/heal.h"
inherit "/players/vertebraker/closed/std/monster.c";
reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   arm_me();
   get_random_heals();
   set_name("vulpine knight");
   set_alias("knight");
   set_race("fox");
   set_short("Vulpine Knight");
   set_long("  A slender creature with the head of a fox,\n"+
      "upright ears, and a pointed snout. It stands\n"+
      "on two hind legs and seems very dextrous. A\n"+
      "long bushy tail grows out from the small of\n"+
      "its back which gives it great balance.\n");
   set_level(20);
   set_hp(500+random(101));
   set_al(0);
   set_ac(20);
   set_wimpy(20, 65, 0, "The Knight flees around the tower!\n");
   set_dead_ob(this_object());
   set_chance(20);
   set_spell_dam(10+random(26));
   set_spell_mess2("\tThe Knight puches its fist into your stomach!\n");
   
}
monster_died() {
   tell_room(environment(this_object()), "The Knight crashes to the ground lifeless.\n");
   return 0; }

arm_me(){
   "/players/jaraxle/closed/weapon/wep_gen.c"->get_wep(this_object(), 999999);
   command("wield weapon with both hands",this_object());
   command("wield weapon",this_object());
   return 1; }

