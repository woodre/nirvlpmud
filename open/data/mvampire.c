inherit "/obj/monster.c";
#include <ansi.h>
#define tpn this_player()->query_name()
#include "/sys/lib.h"

reset(arg) {
string adj;
   ::reset(arg);
   if(arg) return;
   adj=({"grotesque","deformed","squat","mutated","bloody","black","green",
      "rippling","irate","snivelling","decayed","screaming","horrible","putrid",
      "smelly","rotting","horned","huge","barbed","infuriated","maniacal",
      "pestulent","angry","insane","wailing","psychotic","deranged","cackling"});
	
  set_name("vampire");
  set_alias("vamp");
  set_race("demon");
set_short("A "+HIR+""+adj[random(sizeof(adj))]+""+NORM+" Vampire ("+HIG+"Glowing"+NORM+")");
  set_long(
    " A long black cape covers most of this figures body. Long fangs protrude \n"+
    " from its mouth, blood covers most of its body. Red eyes glare and pierce \n"+
    " the soul.\n");
  set_level(21);
  set_hp(550+random(350));
  set_al(-800);
  set_heal(15,7);
  add_money(2000+random(1500));
  set_ac(random(8)+19);
  set_wc(random(15)+30);
  set_wc_bonus(20);
  set_aggressive(0);
set_multi_cast(5);
 
 add_spell("claw_swipe",
  ""+HIK+"#MN#'s"+NORM+" claws flays you with "+HIY+"burt"+HIB+" of speed"+NORM+".\n",
  ""+HIK+"#MN#"+NORM+" tears into #TN#'s "+HIY+"flesh"+NORM+" with his jagged claws.\n",
                     15,40,"other|physical");

add_spell("bat_flock","#MN# raises his hand and a massive"+RED+" bat"+NORM+" tears at you.\n",
                     "#MN# summons a stream of"+HIR+" bats"+NORM+" who tear apart #TN#.\n",
                     15,25,"other|evil");
					 
add_spell("super_speed","#MN# charges at you with "+HIY+"super speed"+NORM+".\n",
                     "#MN# charges at #TN# with "+HIY+"super speed"+NORM+".\n",
                     20,35,"other|laser");

add_spell("super_throw","#MN# throws you into a wall with "+HIY+" super strength"+NORM+".\n",
                     "#MN# throws #TN# into a wall with "+HIY+" super strength"+NORM+".\n",
                     20,20,"other|fire");
        set_a_chat_chance(2);
   set_chat_chance(2);
        load_chat("Vampire whispers: Only death is here for you.\n");
        load_a_chat("Vampire snarls: You shall pay with your life.\n");
}