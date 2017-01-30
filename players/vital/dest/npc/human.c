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
 *  Change History: 1/4/01, 5/15/01, 
 *  
 *  
 *****************************************************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/spaceport.h"

inherit "/players/vital/closed/std/monster";

object item, weapon, helmet, boots, misc;
string *name_desc, *alias_desc, grace;
int name_num, alias_num;
int rnd;

reset(arg){
   if(arg) return;
   name_desc = ({"marc","leptis","xang","leruv","shiv","erkcen","vau","pugap","peeltor","aknububa","zeflel","gongar","psystic","balton","faib","korypal","andabado","antlol","duplin","dwayne","typra","tommy","sluror","winnona","myrkyr","kirk","lisa","mona","jesse","andripal","mol","smarks","nugt","onfyl","whipple","lutzporg"});
   alias_desc = ({"guy","traveler","adventurer","regular","passenger","worker","engineer","executive","porter","clerk","attendant"});
    switch(random(6)) {
      case 0: helmet=CO(SPARMOR+"hat.c"); MO(helmet,TO);
      case 1: item=CO(SPOBJ+"suitcase.c"); MO(item,TO);
        break;
      case 2: item=CO(SPOBJ+"chit.c"); MO(item,TO);
      case 3: weapon=CO(SPWEAPON+"info_pda.c"); MO(weapon,TO);
        break;
      case 4: item=CO(SPOBJ+"bell.c"); MO(item,TO);
      case 5: boots=CO(SPARMOR+"boots.c"); MO(boots,TO);
      case 6: misc=CO(SPARMOR+"coat.c"); MO(misc,TO);
        break;
   }
    ::reset(arg);
    rnd = random(6);
    if(name_desc || alias_desc) {
      alias_num=random(sizeof(alias_desc));
      name_num=random(sizeof(name_desc));
      set_name(name_desc[name_num]);
      set_alias(alias_desc[alias_num]);
    }
    set_race(get_race());
    set_gender(random(2) ? "male" : "female");
    set_short("A Milieu "+alias+" named "+capitalize(name));
    set_long("  "+short_desc+".\n\
"+short_desc+" is a typical of the "+alias+"s found all over the \n\
Milieu. People like "+capitalize(name)+" like to wander around while waiting\n\
for something to happen.\n");
    set_level(11+rnd);
    set_wander(5+random(10),0,({}));
    set_al(-40*rnd);
    set_dead_ob(TO);
    add_money(TO->query_level()*(rnd+1));
}

id(str) { return str == name || str == alias || str == race || str == alt_name; }

get_race() {
    switch(random(5)) {
        case 0: grace = "human"; break;
        case 1: grace = "simbari"; break;
        case 2: grace = "krondaku"; break;
        case 3: grace = "poltroyan"; break;
        case 4: grace = "gi"; break;
    }
    return grace;
}
