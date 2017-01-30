/******************************************************************************
 *  
 *  File:           human.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:			Started 1/3/01.
 *  
 *  Notes:			
 *  
 *  Change History: 1/4/01
 *  
 *  
 *****************************************************************************/

#include "/players/mythos/amon/hb_ag.h"
#include "/players/vital/spaceport/spaceport.h"

inherit "/obj/monster";

object item, weapon, helmet, boots, misc;
string *name_desc, *alias_desc;
int name_num, alias_num;
int rnd;

reset(arg){
   if(arg) return;
   name_desc = ({"bob","john","xang","leruv","berbu","erkcen","vellun","pugap","ploril","aknububa","zeflel","engco","tlepo","bnawan","faib","korypal","andabado","antlol","duplin","roger","typra","trairdu","sluror","winnon","myrkyr","kirk","lisa","mona","jesse","andripal","mol","smarks","nogg","onfyl","whipple","lutzporg","sharn"});
   alias_desc = ({"guy","traveler","adventurer","regular","passenger","worker","engineer","executive","porter","clerk","attendant"});
    switch(random(6)) {
      case 0: helmet=CO(SPARMOR+"hat.c"); MO(helmet,TO);
      case 1: item=CO(SPOBJ+"suitcase.c"); MO(item,TO);
        break;
      case 2: item=CO(SPOBJ+"chit.c"); MO(item,TO);
      case 3: weapon=CO(SPWEAPON+"pda.c"); MO(weapon,TO);
        break;
      case 4: item=CO(SPOBJ+"bell.c"); MO(item,TO);
      case 5: boots=CO(SPARMOR+"boots.c"); MO(boots,TO);
      case 6: misc=CO(SPARMOR+"coat.c"); MO(misc,TO);
        break;
   }
    ::reset(arg);
    rnd = random(6);
    if(name_desc || alias_desc) {
      alias_num=random(sizeof(alias_desc)-1);
      name_num=random(sizeof(name_desc)-1);
      set_name(name_desc[name_num]);
      set_alias(alias_desc[alias_num]);
    }
    set_race("human");
    set_short("A N.U.T.S. "+alias+" named "+CAP(name));
    set_long("  "+short_desc+".\n\
"+short_desc+" is a typical of the "+alias+"s found inside the \n\
Spaceport. People like "+CAP(name)+" like to wander around while waiting for \
the \nright shuttle or person to come along.\n");
    set_level(11+rnd);
    switch(rnd) {
      case 0: set_hp(165); set_wc(15); set_ac(9); break;
      case 1: set_hp(180); set_wc(16); set_ac(9); break;
      case 2: set_hp(195); set_wc(17); set_ac(10); break;
      case 3: set_hp(220); set_wc(18); set_ac(11); break;
      case 4: set_hp(250); set_wc(20); set_ac(12); break;
      case 5: set_hp(300); set_wc(22); set_ac(13); break;
      case 6: set_hp(350); set_wc(24); set_ac(14); break;
    }
    set_al(-40*rnd);
    set_dead_ob(TO);
    add_money(TO->query_level()*(rnd+1));
call_out("move_mob",15);
}

move_mob() {
  if(!kill_ob) {
    switch(random(8)) {
      case 0: command("west"); break;
      case 1: command("east"); break;
      case 2: command("north"); break;
      case 3: command("south"); break;
      case 4: command("southwest"); break;
      case 5: command("northwest"); break;
      case 6: command("northeast"); break;
      case 7: command("southeast"); break;
      case 8: command("out"); break;
    }
  remove_call_out("move_mob");
  call_out("move_mob",15+random(5));
  return;
  }
  else 
  remove_call_out("move_mob");
  call_out("move_mob",15+random(5));
  return;
}

