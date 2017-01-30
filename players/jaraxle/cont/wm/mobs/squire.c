#include "/players/jaraxle/define.h"
inherit "obj/monster.c";
object gold;
reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   call_out("arm_me", 1);
   set_name("weapon squire");
   set_alias("squire");
   set_alt_name("weaponmaster");
   set_race("human");
   set_short("Weapon Squire");
   set_long(
      "  A young man with pale skin.  His scrawny body\n"+
      "barely able to wield and wear his own equipment.\n");
   
   set_level(10);
   set_hp(130+random(36));
   set_al(0);
   set_wc(14);
   set_ac(8);
   set_aggressive(0);
   set_dead_ob(this_object());
   gold = clone_object("obj/money");
   gold->set_money(200 + random(300));
   move_object(gold,this_object());
   
}
monster_died() {
   tell_room(environment(this_object()), "The Squire crashes to the ground lifeless.\n");
   return 0; }

arm_me(){
   "/players/jaraxle/closed/weapon/wep_gen.c"->get_wep(find_living("weapon squire"), 10000);
   command("wield weapon",this_object());
   return 1; }
