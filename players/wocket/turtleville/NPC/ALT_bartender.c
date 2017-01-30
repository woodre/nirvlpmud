#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster.c";
object hero;

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
add_action("ask","ask");
add_action("saying","say");
#ifndef __LDMUD__
  add_action("saying"); add_xverb("'");
#else
  add_action("saying", "'", 3);
#endif
}

saying(str){
string one,two;
  if(sscanf(str,"%sgossip%s",one,two) == 2){
    hero = this_player();
    call_out("ask",2,"mikel");
  }
  return 0;
}

ask(str){
   if(str == "bartender" || str == "barkeep" || str == "mikel"){
    if(!hero) hero = this_player();
     if(present("euka_quest_rod",hero)){
       tell_object(hero,
        "Mikel says, \"Oh, So you talked to the Elder eh.  I'm sure he told\n"+
        "             you about the shield that reflects the wizards spells.\n"+
        "             Well if he didn't I'm sure it just slipped his mind.  Maybe\n"+ 
        "             it got lost out there somewhere.  Heh, who can keep track\n"+
        "             of all that stuff.\"\n");
       hero = 0;
     return 1;
     }
     else
     tell_object(hero,
        "Mikel says, \"Ya, so I hear something strange is happening over\n"+
        "             in the Euka forest.  They don't speak english in\n"+
        "             there, but I heard Yestler is living around there.\"\n");
     call_out("speaking",2);
     return 1;
   }
   notify_fail("Who would you like to ask?\n");
   return 0;
}
      
speaking(){
  tell_object(hero,
    "Mikel says, \"You might want to go hunt him down.  He probably could\n"+
    "             help you.  You'll want to ask him about the euka language.\"\n");
  hero = 0;
}

blah(str){
if( str == "maggie" || str == "maid" || str == "barmaid" ){
tell_room(environment(this_object()),"Mikel says, \"How dare you do that to my daughter.\"\n");
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
default: notify_fail("Mikel says, \" What would you like to buy?\"\n");
          return 0;
}

if(this_player()->query_intoxination() > this_player()->query_level()+3){
write("Mikel says, \" You are to drunk for me to serve you.\"\n");
return 1;
}
if(this_player()->query_money() < COST){
write("Mikel says, \" You don't seem to have enought money.\"\n");
return 1;
}
write("Mikel hands you a "+str+".\nYou drink it down greedily.\n");
this_player()->add_money(-COST);
this_player()->heal_self(HEAL);
call_other(this_player(),"drink_alcohol",INTOX);
say("Mikel hands "+this_player()->query_name()+" "+str+".\n",this_player());
return 1;
}
