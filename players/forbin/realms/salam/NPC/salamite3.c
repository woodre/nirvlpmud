/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Realm:        Caves of the Salamite
 *  Function:     NPC
 *  Create Date:  2004.06.05
 *  Last Edit:    2004.06.11 -Forbin
 *  Notable Changes:            
 *    2004.06.11 -Forbin: switched from heart_beat() to a fake_hb()
 */ 


#include "/players/forbin/realms/salam/salamdefine.h"
#include "/players/forbin/logging.h"
#pragma combine_strings
inherit "/players/vertebraker/closed/std/monster.c";

object Weapon;

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  Weapon = clone_object(OBJ+"obsidianspear.c"); 
  move_object(Weapon, this_object());
  command("wield spear", this_object());   
  set_name("Salamite Guardsman");
  set_alt_name("salamite guardsman");
  set_alias("guardsman");
  set_race("salamite");
  set_gender("male");
  set_short("A "+HIR+"Sala"+NORM+RED+"mite"+HIR+" Guardsman"+NORM);
  set_long(
    "  Ruddy red and covered with bright red scales, this creature \n"+
    "looks like a salamander, yet stands on its back two feet - while\n"+ 
    "balancing with a long tail.  Reaching six feet tall, its body is\n"+
    "smeared with a black substance that seems to have hardened into a\n"+
    "natural armor.  A large red triangle, pointing down, has been\n"+
    "painted onto its chest.\n");
  set_level(20);
  set_hp(500);
  set_al(-500);
  set_wc(33);
  set_ac(16);
  set_dead_ob(this_object());  
  set_chat_chance(5);
    load_chat("The Salamite tenses up...ready to fight...\n");
    load_chat("The Salamite hisses at you...\n");
  set_a_chat_chance(20);
    load_a_chat("The Salamite tosses you to the ground...\n");
    load_a_chat("With lightning reflexes, the Salamite punches you in the face....\n");
    load_a_chat("The Salamite swings hard...barely missing you...\n");  
  set_chance(30);
  set_spell_dam(30);
  set_spell_mess1(
    "\nThe Salamite "+HIR+"xXx "+HIW+"SMACKS "+HIR+"xXx"+NORM+" its opponent with its tail...\n");
  set_spell_mess2(
    "\nThe Salamite "+HIR+"xXx "+HIW+"SMACKS "+HIR+"xXx"+NORM+" you with its tail!\n");
}

init(){
  ::init();
}

query_salamite_guardsman() { return 1; }

/* 
 *  ***********************************************************************
 *  Function:    heal_self
 *  Description: no heal_self damage allowed
 *  Arguments:   none
 *  ***********************************************************************
 */

heal_self(int i) {
  if(i < 0){
    tell_room(environment(), "The salamite hisses loudly, shrugging off your attack!\n");
    return 1;
  }
  ::heal_self(i);
  return 1;
}

heart_beat() {
  int x;
  object ob;
  object att;
  object next;
  ::heart_beat();
  if(environment(this_object())) {
    ob = first_inventory(environment(this_object()));
    if(!query_attack()) {
      while(ob) {
        att = ob->query_attack();
        next = next_inventory(ob);
        if(att && (ob->query_salamite_king() || ob->query_salamite_guardsman())) {
          tell_room(environment(), "The Salamite Guardsman leaps to the attack!\n\n");
          attack_object(att);
        }
      ob = next;
      }
    }
  }
}

monster_died() {
  object treasure;
#ifdef KILLLOG
  mon_log(KILLLOG);
#endif
  tell_room(environment(this_object()),
    "\n\nWith the killing blow, a chunk of scales is knocked from the Salamite.\n\n");
  treasure = clone_object(OBJ+"salamite_scales.c");
  move_object(treasure,environment(this_object()));
    return 1;
}

