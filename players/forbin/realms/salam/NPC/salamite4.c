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

object Hat;

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  Hat = clone_object(OBJ+"jestershat.c"); 
  move_object(Hat, this_object());
  command("wear hat", this_object());  
  set_name("Salamite Jester");
  set_alt_name("salamite jester");
  set_alias("jester");
  set_race("salamite");
  set_gender("male");
  set_short("A "+HIR+"Sala"+NORM+RED+"mite "+HIC+"Je"+HIY+"st"+HIG+"er"+NORM);
  set_long(
    "  This Salamite looks quite strange and rather ridiculous wearing\n"+
    "its jester hat.  Three floppy tips, each a different color, hang\n"+
    "down around the hat.  Unlike the others, this Salamite has no\n"+ 
    "armor, only bright red scales and ruddy skin.  It seems very\n"+ 
    "nervous with your presence here.\n");
  set_level(14);
  set_hp(222);
  set_al(-111);
  set_wc(18);
  set_ac(11);
  set_dead_ob(this_object());  
  set_chat_chance(5);
    load_chat("The Salamite looks for a way to escape...\n");
    load_chat("The Salamite nervously eyes the exit...\n");
  set_a_chat_chance(20);
    load_a_chat("The Salamite runs around the room screaming...\n");
    load_a_chat("Before you can stop it, the Salamite pulls your hair....\n");
    load_a_chat("The Salamite collapses into the fetal position and cries...\n");  
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
    tell_room(environment(), "The salamite begs you to stop!\n");
    return 1;
  }
  ::heal_self(i);
  return 1;
}

monster_died() {  
#ifdef KILLLOG
  mon_log(KILLLOG);
#endif
    return 1;
}

