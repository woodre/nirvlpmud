inherit "/players/jaraxle/closed/monster.c";
#include "/players/jareel/define.h"

reset(arg){
   
  object gold,helmet,armor,sword;
    ::reset(arg);
    if(arg) return;
     
  set_name("skeleton");
  set_alias("skel");
  set_alt_name("bones");
  set_race("chaos");
  set_short(BOLD+"Skeleton"+NORM);
  set_long(
    "Chittering teeth, walking bones, no skin, red glowing eyes.\n"+
    "The creature is a enigma of logical reasoning.  A walking\n"+
    "creature bound together only by the very strands of magical\n"+
    "chaos.\n");
  set_al((-100-random(900)));
  set_level(20);
  set_hp(500);
  MOCO("/players/jareel/weapons/wep_shop_short_sword.c"),this_object());
    init_command("wield sword");
  set_wc(40);
  set_ac(17);
  set_aggressive(1);
  add_money(8000-random(7000));
  set_dead_ob(this_object());
  add_spell(
    "evil",""+HIK+"The skeletons eyes glow "+RED+"red"+HIK+"!"+NORM+"\n"+HIK+"A Dark waves of energy flow from the skeleton into you!"+NORM+"\n",
           ""+HIK+"The skeletons eyes glow "+RED+"red"+HIK+"!"+NORM+"\n"+HIK+"A Dark waves of energy flow from the skeleton into #TN#!"+NORM+"\n",
           10,50,"other|evil");
  add_spell(
    "slash",""+HIK+"The skeletons flips up into the air holding his short sword high over its head...\n"+HIK+"       The skeletons blade "+NORM+BOLD+"slashes"+HIK+" down into you!"+NORM+"\n",
    ""+HIK+"The skeletons flips up into the air holding his short sword high over its head...\n"+HIK+"       The skeletons blade "+NORM+BOLD+"slashes"+HIK+" down into #TN#!"+NORM+"\n",
    15,50,"other|physical");

  add_spell(
    "plunge",""+HIK+"The skeleton lunges forward stabbong its sword...\n"+HIK+"       The skeletons blade "+NORM+BOLD+"plunges"+HIK+" into you!"+NORM+"\n",
             ""+HIK+"The skeleton lunges forward stabbong its sword...\n"+HIK+"       The skeletons blade "+NORM+BOLD+"plunges"+HIK+" into #TN#!"+NORM+"\n",
    15,50,"other|physical");
}

heart_beat(){
  object ob;
  object att;
  object next;
    if(!environment()) return;
    if(ob = present("skeleton", environment())) { if(ob->query_attack()) attack_object(ob->query_attack()); } ;
  ::heart_beat();
}

query_mhp() { return query_hp(); }
