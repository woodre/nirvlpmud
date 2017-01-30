#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster.c";

reset(arg){
::reset(arg);
    if(arg) return;
set_name("maggie");
set_alt_name("maid");
set_alias("barmaid");
set_short(HIR+"Maggie"+NORM+", the Barmaid");
set_long("Maggie is a very well developed girl.  She looks to be 17 years old and\n"+
         "is dressed in a long flowing black skirt and a tight corset, which\n"+
          "shows off more cleavage then should be for a girl of such age.  Her hair\n"+
          "is raven black, soft and semi-long, reaching down to her shoulder blades.\n"+
        "She is very pretty, enough even to kiss.\n");
set_level(12);
set_hp(180);
set_wc(16);
set_ac(9);
add_money(600);
set_chat_chance(10);
load_chat("Maggie smiles at you.\n");
load_chat("Maggie winks at you.\n");
load_chat("Maggie flirts with you.\n");
}

init(){
  add_action("buy","buy");
  add_action("buy","order");
}

buy(string str){
  if(str == "soup"){
if(this_player()->query_stuffed()+14 > this_player()->query_level()*8){
notify_fail("Maggie says: You look a little full.\n");
return 0;
}
if(this_player()->query_money() < 250){
notify_fail("Maggie says: You don't have enought money to buy some soup.\n");
return 0;
}
write("Maggie hands you some soup.\nYou pay her 250 coins and slurp the soup down.\n");
this_player()->add_money(-250);
this_player()->heal_self(25);
call_other(this_player(),"eat_food",14);
say("Maggie hands "+this_player()->query_name()+" some soup.\n",this_player());
return 1;
}
  if(str == "water"){
if(this_player()->query_soaked()+14 > this_player()->query_level()*8){
notify_fail("Maggie says: You don't look thirsty.\n");
return 0;
}
if(this_player()->query_money() < 100){
notify_fail("Maggie says: You don't have enought money to buy some water.\n");
return 0;
}
write("Maggie hands you a glass of water.\nYou pay her 100 coins and gulp it down.\n");
this_player()->add_money(-100);
this_player()->heal_self(10);
call_other(this_player(),"drink_soft",14);
say("Maggie hands "+this_player()->query_name()+" a glass of water.\n",this_player());
return 1;
}
notify_fail("Maggie says: What did you want to buy?\n");
return 0;
}
