/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Realm:        City of Keats
 *  Function:     NPC
 *  Create Date:  2004.06.03
 *  Last Edit:    2004.06.11 -Forbin
 *  Notes:        Adapted from: 
 *                  /players/maledicta/templar/mobs/templar_guard.c
 *                  Orignal Copyright (c) Maledicta@Nirvana
 *  Notable Changes:            
 */ 

#include "/players/forbin/realms/keats/keatsdefine.h"
#pragma combine_strings
inherit "/players/vertebraker/closed/std/monster.c";

object Gold, Helmet, Armor, Weapon;

id(str) { 
  return (::id(str) || str == "knight" || str == "guard" || 
                       str == "poet guard" || str == "keats_pgk"); 
}

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  Helmet = clone_object(OBJ+"greathelm");
  move_object(Helmet, this_object());
  command("wear helm", this_object());
  Armor = clone_object(OBJ+"fullplate");
  move_object(Armor, this_object());
  command("wear platemail", this_object());
  Weapon = clone_object(OBJ+"coldsteellongsword"); 
  move_object(Weapon, this_object());
  command("wield longsword", this_object()); 
  set_name("[Poet Guard] Knight");
  set_race("human");
  set_gender("male");
  set_short(HIC+"["+HIW+"Poet Guard"+HIC+"] "+HIW+"Knight"+NORM);
  set_long(
    "  From his birth, this knight has been a retainer to the Magistrate of\n"+
    "the City of Keats.  Trained throughout life as a virtuous warrior of\n"+
    "good, he is a member of the city's elite Poet Guard.  Since the\n"+
    "closing of the city gate, he holds vigil here with others of his\n"+ 
    "order.  He is well armed and would protect the City at all cost.\n");
  set_level(20);
  set_hp(650);
  set_al(1000);
  set_wc(30);
  set_ac(20);
  set_dead_ob(this_object());  
  set_aggressive(0);
  set_heart_beat(1);
  set_chance(15);
  set_spell_dam(20);
  set_spell_mess1(
    "With lightning quickness, the knight leaps forward, slicing his opponent!\n");
  set_spell_mess2(
    "Blood runs free as you are sliced by the knight's katana!\n");
  Gold = clone_object("obj/money");
  Gold->set_money(500);
  move_object(Gold,this_object());
}

init(){
  ::init();
}

query_poetguard() { return 1; }

/* 
 *  ***********************************************************************
 *  Function:    fake_hb
 *  Description: fake heart_beat()
 *  Arguments:   none
 *  ***********************************************************************
 */

heart_beat() {
  object ob;
  object att;
  object next;
  if(!environment()) return;
  ::heart_beat();
  if(environment(this_object())) {
    ob = first_inventory(environment(this_object()));
    if(query_wc() < 30) set_wc(30);
    if(query_ac() < 20) set_ac(20);
    if(!query_attack()) {
      while(ob) {
        att = ob->query_attack();
        next = next_inventory(ob);
        if(att && ob->query_poetguard()) {
          tell_room(environment(), "The knight rushes to the attack!\n\n");
          attack_object(att);
        }
      ob = next;
      }
    }
  }
}

monster_died() {
#ifdef KILLLOG
  mon_log(KILLLOG);
#endif
  return 1;
}

