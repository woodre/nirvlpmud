#include "/players/jaraxle/ansi.h"

inherit "/obj/monster";



int heals; 

object fool;



reset(arg) {

   ::reset(arg);

   if (arg) return;

   move_object(clone_object("/players/jaraxle/ares/weapons/daggers.c"), this_object());

   set_short(BOLD+"Direthorne"+NORM);

   set_long(

"  This is a thin man with brown hair and dark eyes. He wears a\n"+

"set of lightweight leather armor and a short shoulder cape. His\n"+

"belt holds a small pouch and a pair of stiletto daggers. You\n"+

"can tell by his confidence and ease that he is a very dangerous\n"+

"man. You should not attack him if you value your life.\n");

   set_name("direthorne");

   set_alias("DireThorne the Assassin");

   set_race("human");

   set_level(24);

   set_wc(42);

   set_wc_bonus(20);

   set_hp_bonus(210);

   set_ac(22);

   set_hp(900);

   set_al(-1000);

   set_heart_beat(1);

   add_money(3000 + random(1000));   

   heals = random(3) + 3;

   set_chance(30);

   set_spell_dam(60 + random(40));

   set_spell_mess1(BOLD+"Direthorne"+NORM+" lashes out with a dagger...\n\n"+

                   HIR+"         -- ----- ---- SLICE ---- ----- --"+NORM+"\n\n"+

                   "                       You are slit open!\n");

   set_spell_mess2("Direthorne slices into his opponent!\n");

   }



heart_beat(){

  ::heart_beat();

  if(attacker_ob) fool = attacker_ob;

  

  if(fool)

  if(present(fool, environment()) && !attacker_ob){

   tell_room(environment(), query_name()+" leaps to the attack!\n");

   attacker_ob = fool;

   }

  

  if(hit_point < 500 && heals){

    tell_room(environment(), 

    query_name()+" grabs a vial from his pouch and drinks it. He is healed!\n");

    hit_point += 50;

    heals -= 1;  

    }

  if(!attacker_ob && random(100) < 5){

    tell_room(environment(), query_name()+" sips an ale while quietly watching the room.\n");

    }  





  if(attacker_ob && random(100) < 10){

    attacker_ob->hit_player(random(50) + 20);

    tell_room(environment(), 

    query_name()+" dashes forward and strikes with his right dagger!\n");

    tell_object(attacker_ob, 

    "You feel a burning pain as Direthorne's dagger slices into you skin...\n"+

    "                   "+GRN+"* P  O  I  S  O  N *"+NORM+"\n"+

    "       You shriek as the agony spreads through your veins!\n");

    }

  if(attacker_ob && random(100) < 10){

    attacker_ob->hit_player(random(50) + 20);

    tell_room(environment(), 

    query_name()+" dashes forward and strikes with his left dagger!\n");

    tell_object(attacker_ob, 

    "You begin to feel weak as the left dagger penetrates your skin...\n"+

    "            "+BOLD+"~ W R A "+NORM+HIW+"I T H   S T R"+NORM+BOLD+" I K E ~"+NORM+"\n"+

    "        Undead energy absorbs your life force!\n");

    hit_point += random(30) + 15;

    }

  }



