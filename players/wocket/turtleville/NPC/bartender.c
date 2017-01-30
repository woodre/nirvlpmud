#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster.c";

reset(arg){
    ::reset(arg);
  if(arg) return;
set_short(MAG+"Mikel"+NORM+", the Bartender");
set_name("mikel");
set_alias("bartender");
set_long("This bartender looks friendly and cheery.  His soft eyes and long hair make\n"+
"him easily approachable.  His smile gives off a warm glow and his pot belly\n"+
"tells you he's hearty with the drink.  He keeps a close eye upon his daughter.\n");
set_level(17);
set_hp(425);
set_wc(30);
set_ac(17);
add_money(800+random(200));
set_chat_chance(3);
load_chat("Mikel smiles.\n");
load_chat("Mikel chuckles.\n");
load_chat("Mikel says: What can I get for you laddie?\n");
}

init(){
  ::init();
add_action("blah","kiss");
add_action("blah","french");
add_action("blah","jeans");
add_action("blah","kiss2");
add_action("blah","sex");
add_action("blah","xkiss");
add_action("buy","buy");
add_action("buy","order");
}

blah(str){
if( str == "maggie" || str == "maid" || str == "barmaid" ){
tell_room(environment(this_object()),"Mikel says: How dare you do that to my daughter.\n");
this_object()->attack_object(this_player());
}
return 0;
}

buy(string str){
int COST,INTOX,HEAL;
switch(str){
case "ale": COST = 10; INTOX = 4; HEAL = 1; break;
case "blood": COST = 300; INTOX = 14; HEAL = 30; break;
case "shot": COST = 500; INTOX = 14; HEAL = 50; break;
default: notify_fail("Mikel says: What would you like to buy?\n");
          return 0;
}

if(this_player()->query_intoxination() > this_player()->query_level()+3){
write("Mikel says: You are to drunk for me to serve you.\n");
return 1;
}
if(this_player()->query_money() < COST){
write("Mikel says: You don't seem to have enought money.\n");
return 1;
}
write("Mikel hands you a "+str+".\nYou drink it down greedily.\n");
this_player()->add_money(-COST);
this_player()->heal_self(HEAL);
call_other(this_player(),"drink_alcohol",INTOX);
say("Mikel hands "+this_player()->query_name()+" "+str+".\n",this_player());
return 1;
}
