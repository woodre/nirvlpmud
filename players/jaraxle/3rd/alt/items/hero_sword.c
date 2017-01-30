/* 03/06/06 Earwax: lowered value from 50k to 10k */

#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/closed/weapon/weapon2.c";
reset(arg) {
   ::reset(arg);
   if (arg) return;
   set_name("broadsword of heroes");
   set_alias("broadsword");
   set_type("sword"); 
   set_short(BLK+BOLD+"BroadSword of "+HIY+"Heroes"+NORM);
   set_long("  This is the famed BroadSword of Heroes which was\n"+
      "bestowed upon Thomas, the Hero from the village of\n"+
      "Nirvana when he outcasted the Phantoms.  The BroadSword\n"+
      "glows with a yellow haze of mysterious power.  This Broad-\n"+
      "Sword has been known to slay dragons, zombies, and\n"+
      "demons of the like with ease.\n");
   set_class(18);
   set_weight(2);
   set_value(10000);
   set_two_handed_wep(1);
   add_special_fun("/players/jaraxle/closed/weapon/powers/speed.c");
   add_special_fun("/players/jaraxle/closed/weapon/powers/lawful_slayer.c");
   add_special_fun("/players/jaraxle/closed/weapon/powers/dragon_slayer.c");
   add_special_fun("/players/jaraxle/closed/weapon/powers/demon_slayer.c");
   add_special_fun("/players/jaraxle/closed/weapon/powers/undead_slayer.c");
   set_hit_func(this_object());
}

