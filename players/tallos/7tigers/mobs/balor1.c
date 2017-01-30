inherit "/obj/monster.c";
#include "/obj/ansi.h"
/* changed to use standard ansi - mizan */
#define tpn this_player()->query_name()

object sword;
reset(arg) {
  ::reset(arg);
  if(arg) return;


  set_name("balor");
  set_race("demon");
  set_short(BOLD+HIM+"A Balor"+NORM);
  set_long(
    "  A dark aura of power surrounds this towering humanoid with huge bat\n"+
    "wings. Lurid flames dance over its skin. In one of its massive clawed\n"+
    "hands, this creature bears a sword that looks sharp enough to slash a\n"+
    "man in two.\n");
  
  add_money(4000);
  sword = clone_object("/players/tallos/7tigers/objects/unholylongsword.c");
  move_object(sword, this_object());
  command("wield sword", this_object());
  set_level(21);
  set_hp(700+random(800));
  set_al(-1000);
  set_ac(29);
  set_wc(34+random(12));
  set_aggressive(0);
  set_armor_params("other|evil",0,30,0);
  set_armor_params("other|fire",0,20,0);
  set_armor_params("other|electric",0,20,0);
  set_armor_params("other|good",0,-10,0);
  set_multi_cast(0);
  add_spell("Dark Bolt",
  "#MN# Throws out his hands and casts a:\n"+
  " \n"+
  ""+RED+"DDDDD  AAAAAA RRRRR  KK  KK  BBBBB  OOOOOO LL   TTTTTT\n"+
  "DD  DD AA  AA RR  RR KK KK   BB  BB OO  OO LL     TT\n"+
  "DD  DD AAAAAA RRRRRR KKKK    BBBBB  OO  OO LL     TT\n"+
  "DD  DD AA  AA RR RR  KKKKK   BB  BB OO  OO LL     TT\n"+
  "DDDDD  AA  AA RR  RR KK  KK  BBBBB  OOOOOO LLLLLL TT"+NORM+"\n"+
  " \n",
  "#MN# Throws out his hands and casts a:\n"+
  " \n"+
  "            "+RED+" D A R K   B O L T"+NORM+"\n"+
  " \n",
    40,30,"other|dark");
  add_spell("implosion",
  "#MN# points and says, \"DIE MORTAL!\"\n"+
  " \n"+
  "Your body is sucked inwards as energy "+HIR+"I"+HIY+" M"+HIR+" P"+HIY+" L"+HIR+" O"+HIY+" D"+HIR+" E"+HIY+" S"+NORM+" inside YOU!\n"+
  " \n",
  "#MN# points at you and says, \"DIE!\"\n"+
  " \n"+
  ""+tpn+" casts an "+HIR+"I"+HIY+" M"+HIR+" P"+HIY+" L"+HIR+" O"+HIY+" T"+HIR+" I"+HIY+" O "+HIR+"N"+NORM+"\n"+
  " \n",
    20,({50,50}),({"other|fire","other|evil"}));  

}
