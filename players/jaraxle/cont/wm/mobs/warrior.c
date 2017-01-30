#include "/players/jaraxle/define.h"
inherit "obj/monster.c";
object gold;

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   call_out("arm_me", 1);
   set_name("weapon warrior");
   set_alias("warrior");
   set_alt_name("weaponmaster");
   set_race("human");
   set_short("Weapon Warrior");
   set_long(
      "  A young man with pale skin.  His build is slightly\n"+
      "tone under his equipment.\n");
   
   set_level(14);
   set_hp(220+random(36));
   set_al(0);
   set_wc(18);
   set_ac(11);
   set_aggressive(0);
   set_dead_ob(this_object());
   gold = clone_object("obj/money");
   gold->set_money(500 + random(400));
   move_object(gold,this_object());
   
}
monster_died() {
   tell_room(environment(this_object()), "The Knight crashes to the ground lifeless.\n");
   return 0; }

arm_me(){
   "/players/jaraxle/closed/weapon/wep_gen.c"->get_wep(find_living("weapon warrior"), 20000);
   command("wield weapon",this_object());
 switch(random(5)){
case 1:
   move_object(clone_object("/players/jaraxle/cont/wm/armor/mask.c"), this_object());
   command("wear mask",this_object());
break;
case 2:
   move_object(clone_object("/players/jaraxle/cont/wm/armor/f_mask.c"), this_object());
   command("wear mask",this_object());
break;
case 3:
   move_object(clone_object("/players/jaraxle/cont/wm/armor/ring.c"), this_object());
   command("wear ring",this_object());
 
break;
case 4:
   move_object(clone_object("/players/jaraxle/cont/wm/armor/f_ring.c"), this_object());
   command("wear ring",this_object());
   
break;
case 0:
   move_object(clone_object("/players/jaraxle/cont/wm/armor/f_shield.c"), this_object());
   command("wear shield",this_object());
break;
}
   return 1; }
