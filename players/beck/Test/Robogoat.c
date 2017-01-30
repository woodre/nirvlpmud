inherit "/players/beck/updates/monster.c";
#include "/players/beck/Defs.h"
#include "/players/beck/Rangers/RangerDefs.h"

reset(arg)
{
   object gold;
   ::reset(arg);
   if(arg) return;
   set_name("Robogoat");
   set_alias("robogoat");
   set_race("RangerMonster");
   set_short("Robogoat");
   set_long(""+
      "Robogoat is part robot and part goat.\n"+
      "He was designed by Lord Zed to rob Tommy of his powers.\n");
   set_level(20);
   set_hp(500);
   set_wc(30+random(5));
   set_ac(17);
   set_chance(15);
   set_spell_dam(10);
   set_al(-800);
   set_aggressive(0);
   gold=clone_object("obj/money");
   gold->set_money(random(4000) + 500);
   move_object(gold, this_object());
   set_dead_ob(TO);
   MASTER->AddChannel("Power Ranger",TO);
}
custom_clean(){
   MASTER->RemoveChannel("Power Ranger",TO);
   return 0;
}
monster_died(){
   MASTER->RemoveChannel("Power Ranger",TO);
   return 0;
}
