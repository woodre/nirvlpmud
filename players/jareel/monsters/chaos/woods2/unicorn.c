inherit "/players/jaraxle/closed/monster.c";
#include "/players/jareel/define.h"

reset(arg){
   
  object gold,helmet,armor,sword;
    ::reset(arg);
    if(arg) return;
     
  set_name("unicorn");
  set_alias("beast");
  set_alt_name("horse");
  set_race("mythical");
  set_short(BOLD+"A mystical white Unicorn"+NORM);
  set_long(
    "The purity of this horned beast is undeniable.  Its white hide\n"+
    "radiates an aura of tranquility.  Its flowing white mane ruffles\n"+
    "in the wind.  A faint yellow light radiates from the single horn \n"+
    "on this beasts head.\n");
  set_al(1000);
  set_level(20);
  set_hp(500);
  set_wc(40);
  set_aggressive(0);
  add_money(random(7000));
  set_armor_params("other|evil",17,100,0);
  set_armor_params("other|physical",17,100,0);
  set_dead_ob(this_object());
  add_spell(
    "good","The unicorns nostrils flare "+RED+"red"+HIK+"!"+NORM+"\n"+HIY+"Yellow waves of energy flow from the unicorn into you!"+NORM+"\n",
           "The unicorns nostrils flare "+RED+"red"+HIK+"!"+NORM+"\n"+HIY+"Yellow waves of energy flow from the unicorn into #TN#!"+NORM+"\n",
           10,50,"other|good");
  add_spell(
    "ram","The unicorn lowers its head...\n"+HIY+"       Lunging forward the unicorn "+NORM+BOLD+"plunges"+HIY+" into you!"+NORM+"\n",
          "The unicorn lowers its head...\n"+HIY+"       Lunging forward the unicorn "+NORM+BOLD+"plunges"+HIY+" into #TN#!"+NORM+"\n",
            15,50,"other|physical");
}

