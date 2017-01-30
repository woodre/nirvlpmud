/*  10/08/06 - Rumplemintz: Moved inherit above #include  */
/*  10/08/06 - Rumplemintz: removed trailing ; from #include  */

inherit "/players/vertebraker/closed/std/monster.c";
#include "/players/jaraxle/define.h"
#include "/players/jaraxle/closed/phoenix/mons/heal.h"
reset(arg)  {
   ::reset(arg);
   if(arg) return;
   arm_me();
   get_random_heals();
   set_name("vulpine hunter");
   set_alias("hunter");
   set_alt_name("vulpine");
   set_race("fox");
   set_short("Vulpine "+GRN+"Hunter"+NORM);
   set_long("  A slender creature with the head of a fox,\n"+
      "upright ears, and a pointed snout. It stands\n"+
      "on two hind legs and seems very dextrous. A\n"+
      "long bushy tail grows out from the small of\n"+
      "its back which gives it great balance. A short\n"+
      "staff and large backpack are strapped across\n"+
      "its back.\n");
   set_level(20);
   set_hp(450+random(81));
   set_al(0);
   set_ac(10);
   set_aggro(1, 10, 100);
   set_dead_ob(this_object());
   set_chance(15);
   set_spell_dam(10+random(11));
   set_spell_mess2("The Hunter swings around you and slices you down your\n\tback with razor sharp claws.\n");
}
monster_died() {
   tell_room(environment(this_object()), "The Fox crashes to the ground lifeless.\n");
   return 0; }

arm_me(){
   switch(random(4)){
      case 0: "/players/jaraxle/closed/weapon/wep_gen.c"->get_wep(this_object(), 66666);
      break;
      case 1..3: return 0; 
      break;
   }
   command("wield weapon with both hands",this_object());
   command("wield weapon",this_object());
   set_wc(35);
   return 1; }
init(){
   ::init();
   add_action("no_move","enter");
   add_action("no_move","around");
   add_action("no_move","up");
   add_action("no_move","down");
   add_action("no_move","back");
}
no_move(){
   write("The "+GRN+"Hunter"+NORM+" places his weapon on your chest blocking you.\n");
   return 1; }
