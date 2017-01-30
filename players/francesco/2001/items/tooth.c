#include "/players/francesco/univ/ansi.h"
inherit "obj/weapon";
int delay;
int actual_time;
int rotated;
string str;

reset(arg){
  ::reset(arg);
  if (arg) return;
   
set_name("tooth");
set_alias("mace");
set_alt_name("weapon");
set_short("A tooth");

set_long("The tooth is a war trophy gotten by the Moonwatcher when he\n"+
        "defeated Big Tooth.  About 3 feet long, it can be 'rotate'd\n"+
        "over the head, like a mace, to inflict more damage.\n");
set_type("mace");
  set_class(16);
  set_weight(2);
  set_value(300);
  set_hit_func(this_object());
}



weapon_hit(attacker){
int W;
int ret;
W = random(13);
  ret = 0;
  if(W>8){  ret = random(7); }
  if(W<1) { ret = random(4); }
  if(rotated){
    tell_object(environment(),"You smash down upon "+attacker->query_name()+" hard.\n");
    ret += 4;
    rotated = 0;
  }
  return ret;
}

init() {
  ::init();
  add_action("rotate","rotate");
  add_action("trade","trade");
}

query_wear() {
  int wear;
  wear = 4*misses/4 + 5*hits/18;
  return wear;
}

rotate(string str){
  object attacker;
  attacker=this_player()->query_attack();
  
  if(!str || str != "tooth"){
    notify_fail("What would you like to rotate?\n");
    return 0;
  }
  if(wielded == 0) { write("Wield the tooth, before rotating it!\n"); 
  return 1; }
  
  if(!attacker){
    notify_fail("You aren't fighting anyone.\n");
    return 0;
  }

  if(rotated){ write("You are already rotating the tooth.\n"); return 1; }
  rotated = 1;
  write("You begin spining the tooth high above your head preparing to strike.\n");
  return 1; 
}

trade(str){
  if(!str) {
  notify_fail("What do you want to trade?\n");
  return 0; }
    if(str=="tooth"){
       if(!present("narrator",environment(this_player()))){
         write("The "+(str)+" cannot be traded in this room.\n");
       return 1;}
      write("The narrator replies:  This is not exactly my business anymore\n"+
           "and therefore I can only give you 1100 coins for this "+(str)+".\n");
        call_other(this_player(),"add_money",1000);
      destruct(this_object());
    return 1;}
  notify_fail("That is not something you can trade here.\n");
  return 0;
}

