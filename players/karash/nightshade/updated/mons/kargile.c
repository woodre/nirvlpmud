inherit "obj/monster";
#include <ansi.h>

#define TO this_object() 
#define ENV environment

/******************************************************************************
 * Program: kargile.c
 * Path: /players/nightshade/mons/
 * Type: Mob
 * Updated: October 2014 by Karash
 *
 * Purpose: An upgrade to the original Nightshade mob named Wulfgar.  This upgrade
 *          increases mob stats and adds additional spells.
 *
 *          Wulfgar can hit hard with his hammer attack, he can swipe the room and
 *          hit all attackers, and he will throw his hammer at a random attacker 
 *          to do heavy damage and stun that attacker for a few rounds, not 
 *          allowing that attacker to attack or perform any actions while stunned.
 *
 *			Special 1: Stun ability.
 *			Special 2: High damage spells 80% of the time, including one spell that 
 *				hits ALL attackers.
 *
 * History:
 *          
 ******************************************************************************/
 
object gold, weap;
 

reset(arg){
  ::reset(arg);
  if(arg) return;
  
  set_name("wulfgar");
  SetMultipleIds( ({ "wulfgar", "Wulfgar", "kargile" }) );
  set_short("Wulfgar");
  set_long("A brute of a man with a massive war hammer hanging gingerly over his\n\
shoulder. Best be careful with this one.\n");
  
  set_level(25);
  set_hp(1200+random(300));
  set_al(-1000);
  set_wc(45);
  set_ac(30);
  
  /** adding weapon WC as bonus **/
  set_wc_bonus(16);
  /** arbitrary bonus for damage avoided due to stunning players **/
  set_ac_bonus(5);
  
  set_heal(5,1);

  set_chat_chance(15);
  load_chat("Wulfgar laughs at your impotence.\n");

  /** Move spell functions to add_spell **
   ****************************************************************************************    
   ** set_chance(35);
   ** set_spell_dam(15);
   ** set_spell_mess1("Wulfgar nails his opponent on the head with his mighty hammer!");
   ** set_spell_mess2("You see Wulfgar's hammer arc over and pound you on the head!");
   ****************************************************************************************/
  
  add_spell("hammer_down",
  "You see Wulfgar's $HK$HAMM$HY$ER$N$ arc over and $M$pound you on the head$N$!\n",
  "Wulfgar $M$nails #TN# on the head$N$ with his mighty $HK$HAMM$HY$ER$N$!\n",
  40,"100-130","physical",0);
  
  add_spell("circle_arc",
  "Wulfgar extends his $HK$HAMM$HY$ER$N$ and spins a wide arc $HR$bludgeoning$N$ $M$all around him$N$!\n",
  "Wulfgar extends his $HK$HAMM$HY$ER$N$ and spins a wide arc $HR$bludgeoning$N$ $M$all around him$N$!\n",
  20,"80-120","physical",3);  
  
   add_spell("throw_hammer",
  "\n\Wulfgar $HM$SWINGS$N$ his $HK$HAMM$HY$ER$N$ violently in a circle over his head and $HM$THROWS IT$N$\n\
at you!  The heavy force $C$knocks you back on your knees$N$... $HM$STUNNING you$N$!\n\
$Y$The magical hammer then returns to Wulfgar's hand.$N$\n\n",
  "\n\Wulfgar $HM$SWINGS$N$ his $HK$HAMM$HY$ER$N$ violently in a circle over his head and $HM$THROWS IT$N$\n\
at #TN#!  The heavy force $C$knocks #TO# on #TP# knees$N$... $HM$STUNNING #TO#$N$!\n\
$Y$The magical hammer then returns to Wulfgar's hand.$N$\n\n",
  20,"100-130","physical",6,"hammer_stun"); 
  
  
  
  /* PATH UPDATED */
  weap=clone_object("/players/nightshade/weap/hammer");
  move_object(weap, this_object());
  
  gold=clone_object("obj/money");
  gold->set_money(1000+random(1000));
  move_object(gold, this_object());

  
}


hammer_stun(object target, object room, int damage)
{
   object stun_obj;
   
  if(target && present(target)) 
  { 
	
    /* PATH UPDATED */
    stun_obj = "/players/nightshade/misc/stun_obj_new.c";

    if(!present("stun_me", target))
	{ 
      move_object(clone_object(stun_obj), target);
    }
  }
}


move_player(){
  tell_room(ENV(TO),
  TO->query_name()+" tries to move but is compelled to stay...\n");}

move_object(){
  tell_room(ENV(TO),
  TO->query_name()+" tries to move but is compelled to stay...\n");}

run_away(){
  tell_room(ENV(TO),
  TO->query_name()+" tries to run but is compelled to stay...\n");}

movement(){
  tell_room(ENV(TO),
  TO->query_name()+" tries to move but is compelled to stay...\n");}

  