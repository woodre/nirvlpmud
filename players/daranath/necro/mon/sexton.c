#include "../defs.h"
inherit "/obj/monster";
#define NAME "Lumier"
#define FILE (int)i+3
#define AMOUNT (int)i+4
#define WEIGHT (int)i+1
#define PRICE (int)i+2
mixed *wares;
string *movements;
reset(arg) {
   ::reset(arg);
   if(arg) return;
     set_name(NAME);
     set_alias("sexton");
     set_short(MAG+"A robed sexton"+OFF);
     set_alt_name(lower_case(NAME));
     set_race("human");
     set_gender("male");
     set_long("An old curled man hunched over.  He is covered in dark purple\n"+
              "robes with gold tassled ropes hanging down.  A small cane supports\n"+
              "his weight as he stumbles around.  He looks like he has things to\n"+
              "sell to a weary traveler.  Perhaps you should have him 'list' his\n"+
              "wares so that you may 'buy' something.\n");
     set_level(10);
     set_ac(10);
     set_wc(14);
     set_hp(450);
     set_al(-300);
     set_aggressive(0);
     set_a_chat_chance(25);
     set_chat_chance(10);
     load_chat(NAME+" says, \"Can I help you?\"\n");
     load_chat(NAME+" says, \"Ouch, my poor old back.\"\n");
     load_chat(NAME+" says, \"I have been the caretaker here for twenty years.\"\n");
     load_chat(NAME+" smiles.\n");
     load_chat(NAME+" bows.\n");
     load_chat(NAME+" grins.\n");
     load_chat(NAME+" says, \"Buy something from an old man?\"\n");
     load_chat(NAME+" says, \"I have a lot of life still in me!\"\n");
     load_a_chat("The elemental thirsts for the taste of the living.\n");
     load_a_chat("The elemental howls in anger and fury.\n");
     wares = ({ 
        "shovel",2,300,OBJ+"/misc/shovel.c",7,
        "salt",1,1000,OBJ+"/misc/salt.c",10, 
    });
     set_heart_beat(1);
}

init(){
  add_action("list","list");
  add_action("buy","buy");
}

list(){
int i,a;
  command("say May I have a list of your wares?",tp);
  tell_room(environment(this_object()),NAME+" says, \"Hello,  I have these things to offer you: \"\n");
  tell_room(environment(this_object()),"\n  "+pad("ITEM",20)+pad("PRICE",10)+"AMOUNT\n");
  for(i=0,a=sizeof(wares);i<a;i = i+5){
    tell_room(environment(this_object()),"  "+pad(wares[i],20)+pad(wares[i+2],10)+wares[i+4]+"\n");
  }
  call_out("list2",1);
  return 1;
}

list2(){
  tell_room(environment(this_object()),NAME+" says, \"Any of that interest you?\"\n");
}

buy(str){
int i;
  command("say I would like to buy a "+str,tp);
  if(!str){
    notify_fail(NAME+" says, \"What would you like to buy?\"\n");
    return 0;
  }
  i = member_array(str,wares);
  if(i == -1){
    notify_fail(NAME+" says, \"I have nothing like that to sell you.\"\n");
    return 0;
  }
  if(wares[AMOUNT] < 1){
    tell_room(environment(this_object()),NAME+" says, \"I am completely out of that.\"\n");
    return 1;
  }
  if(wares[PRICE] > tp->query_money()){
    tell_room(environment(this_object()),NAME+" says, \"You do not have the money to pay for that.\"\n");
    return 1;
  }
  if(!tp->add_weight(wares[WEIGHT])){
    tell_room(environment(this_object()),NAME+" says, \"You can't carry it.  I better keep it.\"\n");
    return 1;
  }
  tp->add_money(-wares[PRICE]);
  wares[AMOUNT] = wares[AMOUNT] - 1;
  move_object(clone_object(wares[FILE]),tp);
  tell_room(environment(this_object()),NAME+" says, \"Here you are.  Enjoy, and thank you for your business.\"\n");
  tell_object(tp,NAME+" hands you a "+wares[i]+".\n");
  say(NAME+" hands "+tpn+" a "+wares[i]+".\n",tp);
  tp->recalc_carry();
  return 1;
}

heart_beat(){
  ::heart_beat();
  if(!random(10))
   wander();
}

wander(){
  if(!random(2)){
    command("north",this_object());
    return;
  }
  command("south",this_object());
}    
