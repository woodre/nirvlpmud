/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Realm:        Caves of the Salamite
 *  Function:     NPC
 *  Create Date:  2004.06.05
 *  Last Edit:    2004.06.10 -Forbin
 *  Notable Changes:            
 */ 

#include "/players/forbin/realms/salam/salamdefine.h"
#include "/players/forbin/logging.h"
#pragma combine_strings
inherit "/players/vertebraker/closed/std/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("Salamite Brute");
  set_alt_name("salamite brute");
  set_alias("brute");
  set_race("salamite");
  set_gender("male");
  set_short("A "+HIR+"Sala"+NORM+RED+"mite"+HIW+" Brute"+NORM);
  set_long(
    "  Towering high above other Salamites, the Brute bristles\n"+
    "with muscles.  Its ruddy red and bright red scales are covered\n"+ 
    "with scars and it has an downward pointing triangle branded just\n"+
    "above and between its eyes.  Its arms and lower extremities seem\n"+
    "to be covered in a hard black armor; its upper torso remains\n"+
    "exposed.  Its clawed hands hang down at his side.  He looks ready\n"+
    "for a fight.\n");
  set_level(20);
  set_hp(700);
  set_al(-777);
  set_wc(35);
  set_ac(19);
  set_dead_ob(this_object());  
  set_chat_chance(5);
    load_chat("The Salamite flexes its muscles...\n");
    load_chat("The Salamite hisses at you...\n");
  set_a_chat_chance(20);
    load_a_chat("The Salamite flings you across the room effortlessly...\n");
    load_a_chat("With lightning reflexes, the Salamite punches you in the face....\n");
    load_a_chat("With a quick step, the Salamite kicks you square in the chest....\n");
    load_a_chat("The Salamite picks you up and slams you to the floor...\n");  
  set_chance(25);
  set_spell_dam(55);
  set_spell_mess1(
    "\nThe Brute "+HIR+"xXx "+HIW+"SMACKS "+HIR+"xXx"+NORM+" his opponent with his tail...\n");
  set_spell_mess2(
    "\nThe Brute "+HIR+"xXx "+HIW+"SMACKS "+HIR+"xXx"+NORM+" you with his tail!\n");
}

init(){
  ::init();
}

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

monster_died() {
  object treasure;
  object corpse;
  corpse = present("corpse", environment());   
#ifdef KILLLOG
  mon_log(KILLLOG);
#endif
  tell_room(environment(this_object()),
    "\n\nWith the killing blow, a chunk of scales is knocked from the Salamite.\n\n");
  treasure = clone_object(OBJ+"salamite_scales.c");
  move_object(treasure,environment(this_object()));
    return 1;
}

