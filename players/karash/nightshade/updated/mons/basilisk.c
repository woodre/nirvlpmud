inherit "obj/monster";
#include <ansi.h>

#define TO this_object() 
#define ENV environment

/******************************************************************************
 * Program: basilisk.c
 * Path: /players/nightshade/mons/
 * Type: Mob
 * Updated: September 2014 by Karash
 *
 * Purpose: An upgrade to the original Nightshade mob named basilisk.  This upgrade
 *          increases mob stats and adds additional spells, including a gaze attack
 *          that will paralyze the attacker for a random number of rounds
 *			Special 1: Paralyze
 *			Special 2: Casts a spell EVERY round doing significant damage, plus higher
 *				than normal AC.
 * 
 * History:
 *          
 ******************************************************************************/
 
object gold;


reset(arg) 
{
::reset(arg);
if(arg) return;
set_name("basilisk");
set_short("Basilisk");
set_long("One of the most powerful creatures of the Underdark, the basilisk knows no\n\
fear. It can kill instantly with only a breath and turn to stone the\n\
hardiest of enemies. It scurries around on six legs and has a long, sharp\n\
horn jutting out of its snout.\n");
set_level(25);
set_hp(800+random(400));
set_wc(44);
set_ac(30);

/** 10% chance to immobilize player for avg of 2 rounds , so giving mob a bonus to **/
/** account for longer fight -> Avg 1000hp * 10% * 2 rounds = 200hp bonus          **/
set_hp_bonus(200);

set_heal(5,1);

set_dead_ob(this_object());

set_al(-2000);

/* set_multi_cast(1); */
  
add_spell("bite_attack",
  "The $G$basilisk$N$ $HM$snaps$N$ at you and it's $HW$sharp teeth$N$ rips into your $Y$flesh$N$.\n",
  "The $G$basilisk$N$ $HW$bites$N$ down on #TN# ripping into #TP# $Y$flesh$N$.\n",
  40,"20-40","physical",0);

add_spell("gore_attack",
  "The $G$basilisk$N$ $HR$GORES$N$ you with his $M$sharp horn$N$.\n",
  "The basilisk $HR$GORES$N$ #TN# with its $M$sharp horn$N$.\n",
  40,"40-60","physical",0);

add_spell("gaze_attack",
  "The $G$basilisk$N$ attacks you with a $HC$PETRIFYING GAZE$N$.\n",
  "The $G$basilisk$N$ attacks #TN# with a $HC$PETRIFYING GAZE$N$.\n",
  10,"30-50","other|earth",0,"paralyze");
  
}

/* Add attack to gut attacker with horn 
/* Add petrifying gaze spell to freeze attacker
/* Add bite attack
/* Increase AC due to tough skin
*/

paralyze()
{
   /* string ATT_NAME; */
   object para_obj;
   
  if(attacker_ob && present(attacker_ob)) 
  { 
    /* ATT_NAME = attacker_ob->query_name(); */
	
    /* PATH UPDATED */
    para_obj = "/players/nightshade/misc/paralyze_obj_new.c";

    if(!present("freeze_me", attacker_ob))
	{ 
      move_object(clone_object(para_obj), attacker_ob);
    }

  }

}

monster_died(){
  tell_room(environment(),
    "The basilisk seemed to be hording a large pile of "+HIY+"coins"+NORM+" in his den.\n");
  gold=clone_object("obj/money");
  gold->set_money(9500+random(3500));
  move_object(gold, environment());

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

  
  