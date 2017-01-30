inherit "/obj/monster.c";
#include <ansi.h>
#define tpn this_player()->query_name()
#include "/sys/lib.h"

reset(arg) {
string adj;
   ::reset(arg);
   if(arg) return;
   adj=({"grotesque","deformed","squat","mutated","bloody","writhing","black","green",
      "rippling","irate","snivelling","decayed","screaming","horrible","putrid",
      "smelly","yellow","rotting","horned","huge","barbed","infuriated","maniacal",
      "pestulent","scaled","angry","insane","wailing","psychotic","deranged","cackling"});
	
  set_name("vampire");
  set_alias("vamp");
  set_race("demon");
set_short("A "+adj[random(sizeof(adj))]+" Vampire");
  set_long(
    " A long black cape covers most of this figures body. Long fangs protrude \n"+
    " from its mouth, blood covers most of its body. Red eyes glare and pierce \n"+
    " the soul.\n");
  set_level(19);
  set_hp(450+random(300));
  set_al(-800);
  set_heal(4,2);
  add_money(2000+random(2000));
  set_ac(random(15)+20);
  set_wc(random(15)+20);
  set_aggressive(0);
set_chance(25);
    add_spell("claw_swipe",
	 "The vampire's claws "+RED+"tear"+NORM+" into your "+HIY+"flesh"+NORM+".\n",
     "The vampire's claws "+RED+"tear"+NORM+" into #TN#'s "+HIY+"flesh"+NORM+".\n",
       35,30,"physical");
        
	add_spell("blood_feed",
     HIK+"#MN#"+NORM+" feeds on your "+HIR+"B L O O D"+NORM+"\n",
     HIK+"#MN#"+NORM+" feeds on #TN#'s "+HIR+"B L O O D"+NORM+"\n",
     35,35,"physical");	
		
        set_a_chat_chance(5);
   set_chat_chance(2);
        load_chat("Vampire whispers: Only death is here for you.\n");
        load_a_chat("Vampire snarls: You shall pay with your life.\n");
}