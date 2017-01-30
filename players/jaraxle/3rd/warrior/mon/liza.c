#include "/players/jaraxle/define.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("Liza");
set_alias("liza");
set_alt_name("maiden");
set_race("human");
set_short("Liza");
set_long(
   "Liza is a human female of medium height.  Her stature in the Village is prominent\n"+
   "because she is the only craftswoman of the arrows everyone uses. She\n"+
   "might be able to sell you some from her "+HIW+"list"+NORM+".\n");

set_level(3);
set_hp(300);
set_al(0);
set_wc(10);
set_ac(20);
set_aggressive(0);

set_chat_chance(4);
load_chat("Liza tightens the vines on some of her quivers.\n");

gold = clone_object("obj/money");
gold->set_money(100+random(100));
move_object(gold,this_object());
}

init() {

::init();

add_action("buy_it","buy");
add_action("list","list");
}

buy_it(arg) {
if(TP->query_money() < 200){
write("Liza says: You do not have enough for that, I'm sorry.\n");
return 1; }
if(!TP->add_weight(1)){ write("Liza tells you: You cant carry this!\n"); return 1; }
if(arg == "elemental") {
TP->add_money(-200);
write("You buy a quiver of arrows.\n");
MOCO("/players/jaraxle/3rd/warrior/weaps/E_quiver.c"),TP);
say(TPN+" buys a quiver of arrows.\n");
return 1; }
if(arg == "normal"){
TP->add_money(-200);
write("You buy a quiver of arrows.\n");
MOCO("/players/jaraxle/3rd/warrior/weaps/quiver.c"),TP);
say(TPN+" buys a quiver of arrows.\n");
return 1; }
if(arg == "power"){
TP->add_money(-200);
write("You buy a quiver of arrows.\n");
MOCO("/players/jaraxle/3rd/warrior/weaps/P_quiver.c"),TP);
say(TPN+" buys a quiver of arrows.\n");
return 1; }
if(arg == "speed"){
TP->add_money(-200);
write("You buy a quiver of arrows.\n");
MOCO("/players/jaraxle/3rd/warrior/weaps/S_quiver.c"),TP);
say(TPN+" buys a quiver of arrows.\n");
return 1; }
if(arg == "magic"){
TP->add_money(-200);
write("You buy a quiver of arrows.\n");
MOCO("/players/jaraxle/3rd/warrior/weaps/M_quiver.c"),TP);
say(TPN+" buys a quiver of arrows.\n");
return 1; }
write("Liza says: I do not have that.\n"); return 1; }
list(){
write("Liza tells you: I have several quivers for sale. You can "+HIW+"buy"+NORM+"\n"+
      "any of the following for "+HIY+"200"+NORM+" coins.\n\n"+
      "  [ "+HIW+"elemental"+NORM+" ] [ "+HIW+"magic"+NORM+" ] [ "+HIW+"speed"+NORM+" ] [ "+HIW+"power"+NORM+" ] [ normal ]\n\n"+
      "(Each one has benefits and drawbacks, see which suit you best.)\n");
return 1; }
