/*  A weapon created by combining backbiter & mal's firesword 
    Nice wep vs. Good creatures(not players)
*/

#include "/players/maledicta/ansi.h"
inherit "players/maledicta/weapon/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;
set_name("sword");
set_alias("vengeance");
set_short(HIW+"Baal's "+RED+"Vengeance "+HIW+"- Double-Bladed Sword"+NORM);
set_long(
  "  The original, created and wielded long ago by Baal the\n"+
  "Dark Lord, was lost to time during the time of troubles.\n"+
  "This is a powerful replica that has been created in honor\n"+
  "of the might of Baal.  It is made from pure adamantium,\n"+
  "and carries a fine magical edge along both of its long\n"+
  "blades.  It hums with a sinister power.\n");
set_type("sword");  
set_class(16);
set_weight(3);
set_value(1000);
add_special_fun("/players/maledicta/weapon/powers/lawful_slayer.c");
add_special_fun("/players/maledicta/weapon/powers/speed.c");
set_no_break(1);
set_two_handed_wep(1);
set_hit_func(this_object());
}



