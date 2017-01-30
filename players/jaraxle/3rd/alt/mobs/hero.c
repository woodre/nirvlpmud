#include "/players/jaraxle/define.h"
inherit "obj/monster.c";

object gold;
int loc_now;

reset(arg)  {
  ::reset(arg);
  if(arg) return;
no_clean = 1;
set_name("thomas");
set_alt_name("hero");
set_race("human");
set_short(HIW+"Thomas, the "+HIY+"Hero"+NORM);
set_level(29);
set_hp(2000);
set_al(0);
set_wc(90);
set_wc_bonus(50);
set_ac(30);
set_aggressive(0);
set_heart_beat(1);
set_dead_ob(this_object());
set_heal(5,2);
set_chance(20);
set_spell_dam(50);
set_spell_mess1(
"Thomas thrusts his broadsword into a cresent moon swing!\n");
set_spell_mess2(
"Thomas slices you into pieces with an upward creasent moon strike!\n");
gold = clone_object("obj/money");
gold->set_money(23000 + random(4000));
move_object(gold,this_object());
loc_now = 0;
enable_commands();

}

long(){
write(
"  Thomas stands a towering six feet nine inches\n"+
"tall.  His body is rippled with strong muscles.\n"+
"His arms, enormous in girth carry the burden of\n"+
"wielding a HUGE broadsword.  Adorning his body\n"+
"is the famed Hero's Armor.\n"); 
return 1;
}


heart_beat(){
  ::heart_beat();
if(attacker_ob){
  if(random(100) < 60){
    if(attacker_ob && !attacker_ob->query_ghost()){
      already_fight=0;
      tell_object(attacker_ob,
      "Thomas grunts loudly. . .\n"+
      "Thomas "+RED+"stabs"+NORM+" you through!\n");
      tell_room(environment(),
      "Thomas "+RED+"stabs"+NORM+" his broadsword through "+attacker_ob->query_name()+"'s chest!!!\n", 
      ({attacker_ob}));
      attack();
      }
   }
  if(random(100) < 40){
    if(attacker_ob && !attacker_ob->query_ghost()){
      already_fight=0;
      tell_object(attacker_ob,
      "Thomas yells, 'Quick strike!'\n"+
      "Thomas "+HIR+"hacks"+NORM+" into your back!!!\n");
      tell_room(environment(),
      "Thomas "+HIR+"hacks"+NORM+" into "+attacker_ob->query_name()+"'s back!!!\n", 
      ({attacker_ob}));
      attack();
      }
   }
  }
}

monster_died(){
object misc_treas;

  tell_room(environment(),
  HIW+"  Thomas falls to the floor... his broadsword crashing to the ground.\n"+NORM);  
  move_object(clone_object("/players/jaraxle/3rd/alt/items/eagle_armor.c"), this_object());
  move_object(clone_object("/players/jaraxle/3rd/alt/items/hero_sword.c"), environment());
 
 return 1;
}
