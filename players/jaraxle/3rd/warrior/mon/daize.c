#include "/players/jaraxle/define.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("Daize");
set_alias("daize");
set_alt_name("shopkeeper");
set_race("human");
set_short("Daize");
set_long(
  "Daize is an elderly gentleman.  His clothing is old, torn and dirty.\n"+
  "He leans heavilly on a cane made of barkwood, his fragile body shakes\n"+
  "with every movement.  Although old and deteriorating, Daize is well known\n"+
  "around Third Earth for his sneaky fighting style, and devious ways.\n");

set_level(17);
set_hp(400);
set_al(0);
set_wc(24);
set_ac(20);
set_aggressive(0);

set_chat_chance(4);
  load_chat("Daize eyes you carefully.\n");
  load_chat("Daize rummaged through his clothes.\n");
  load_chat("Daize begins to shiver, leaning onto his cane.\n");

gold = clone_object("obj/money");
gold->set_money(200+random(200));
move_object(gold,this_object());
}

init() {

::init();

add_action("buy_it","buy");
add_action("ask_me","ask");
}
ask_me(arg){
if(arg == "daize about stuff" || arg == "about stuff" || arg == "about daize's stuff"){
write("Daize grins at you.\nDaize says: I have FaKie HeALs for sale my friend.\n");
 write("Daize continues: You can buy fakie# (# = 1,2 or 3).\nDaize remarks: If you want, I have a list for sale too.\n");
return 1; }
write("Ask what?\n");
return 1; }
buy_it(arg) {
if(TP->query_money() < 1800){
write("Daize says: You do not have enough coins for this stuff.\n");
return 1; }
if(!TP->add_weight(1)){ write("Daize tells you: You cant carry this!\n"); return 1; }
if(arg == "fakie1") {
TP->add_money(-1800);
write("Daize sneaks a Fakie HeAL .1. into your inventory.\n");
MOCO("/players/jaraxle/3rd/warrior/heals/fakie1.c"),TP);
say(TPN+" buys something from Daize.\n");
return 1; }
if(arg == "fakie2"){
TP->add_money(-1800);
write("Daize sneaks a Fakie HeAL .2. into your inventory.\n");
MOCO("/players/jaraxle/3rd/warrior/heals/fakie2.c"),TP);
say(TPN+" buys something from Daize.\n");
return 1; }
if(arg == "fakie3"){
TP->add_money(-1800);
 write("Daize sneaks a Fakie HeAL .3. into your inventory.\n");
 MOCO("/players/jaraxle/3rd/warrior/heals/fakie3.c"),TP);
say(TPN+" buys something from Daize.\n");
return 1; }
if(arg == "list"){
TP->add_money(-50);
write("Daize hands you a list, with a smile.\n");
  MOCO("/players/jaraxle/3rd/warrior/heals/fakie_list.c"),TP);
say(TPN+" buys something from Daize.\n");
return 1; }
write("Daize says: I'm not selling that.\n");
return 1; }
