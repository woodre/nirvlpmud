#include "/players/jaraxle/define.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("Santa Clause");
set_alias("santa");
set_alt_name("saint nick");
set_race("human");
set_short("Santa Clause");
set_long(
  "It's jolly ole St. Nick! He might have a gift for you if you have been good!!! All you\nhave to do is "+HIW+"<"+HIG+"ask santa"+HIW+">"+NORM+" to see what he has!\n");
MOCO("/players/jaraxle/sack.c"),TO);
init_command("wield weapon");
set_level(100);
set_hp(300000000);
set_al(1500);
set_wc(0);
set_ac(100000000);
set_aggressive(0);

set_chat_chance(4);
load_chat("Santa bellows, 'HO! HO! HO!\n");
load_chat("Santa bellows, 'MERRY CHRISTMAS!!\n");
load_chat("Santa asks, 'Have you been naughty or nice?\n");

}

init() {

::init();

add_action("ask_him","ask");
}
ask_him(arg) {
if(arg == "santa") {
write("Santa gives you a present!!\n");
MOCO("/players/jaraxle/gift_box.c"),TP);
say(TPN+" receives a gift from Santa Clause!\n");
return 1; }
write("You need to "+HIW+"ask santa"+NORM+"\n");
}
