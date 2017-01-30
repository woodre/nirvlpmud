#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";
reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("vulpine berzerker");
   set_alias("berzerker");
   set_alt_name("vulpine");
   set_race("fox");
   set_short("Vulpine Berzerker");
   set_long("  A slender creature with the head of a fox,\n"+
      "upright ears, and a pointed snout. It stands\n"+
      "on two hind legs and seems very dextrous. A\n"+
      "long bushy tail grows out from the small of\n"+
      "its back which gives it great balance. From\n"+
      "the mouth large teeth grow outside of the\n"+
      "snout and foam salivates around the lips.\n");
   set_level(10);
   set_hp(40);
   set_al(0);
   set_ac(4);
   set_wc(4);
   set_aggro(1, 10, 100);
   set_dead_ob(this_object());
   set_chance(50);
   set_spell_dam(5+random(6));
   set_spell_mess1("\tThe Berzerker rages about, slashing its weapon franticly!\n");
   set_spell_mess2("\tThe Berzerker rages slashing its weapon through you!\n");
}
monster_died() {
   tell_room(environment(this_object()), "The Fox crashes to the ground lifeless.\n");
   return 0; }

