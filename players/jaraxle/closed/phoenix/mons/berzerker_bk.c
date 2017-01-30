#include "/players/jaraxle/define.h"
#include "/players/jaraxle/closed/phoenix/mons/heal.h"
inherit "/players/vertebraker/closed/std/monster.c";
reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   arm_me();
   get_random_heals();
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
   set_level(20);
   set_hp(450+random(101));
   set_al(0);
   set_ac(10);
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

arm_me(){
   switch(random(4)){
      case 0: "/players/jaraxle/closed/weapon/wep_gen.c"->get_wep(this_object(), 66666);
      break;
      case 1..3: return 0; 
      break;
   }
   command("wield weapon with both hands",this_object());
   command("wield weapon",this_object());
   set_wc(30);
   return 1; }
init(){
   ::init();
   add_action("enter","enter");
}
enter(str){
   if(!str) return (notify_fail("You may enter the door.\n"), 0);
   if(str == "door" || str == "wooden door"){
      write("The Fox angrilly pushes you back.\n");
      return 1; }
   notify_fail("Enter what?\n"); return 0; }
