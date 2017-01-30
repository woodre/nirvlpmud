#include "/players/jaraxle/define.h"
inherit "obj/monster.c";
object gold;

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   call_out("arm_me", 1);
   set_name("weapon soldier");
   set_alias("soldier");
   set_alt_name("weaponmaster");
   set_race("human");
   set_short("Weapon Soldier");
   set_long(
      "An oozing, walking, hot blob of molten lava.\nIt's eyes sparkle deep red.\n");
   
   set_level(17);
   set_hp(350+random(36));
   set_al(0);
   set_wc(26);
   set_ac(12);
   set_light(1);
   set_aggressive(0);
   set_dead_ob(this_object());
   gold = clone_object("obj/money");
   gold->set_money(200 + random(300));
   move_object(gold,this_object());
   
}
monster_died() {
   tell_room(environment(this_object()), "The Knight crashes to the ground lifeless.\n");
   return 0; }

arm_me(){
   "/players/jaraxle/closed/weapon/wep_gen.c"->get_wep(find_living("weapon soldier"), 50000);
   command("wield weapon",this_object());
   move_object(clone_object("/players/jaraxle/shop/armor/fire/mask.c"),this_object());
   command("wear mask",this_object());
   return 1; }
