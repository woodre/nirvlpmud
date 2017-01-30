/******************************************************************************
 *  
 *  File:           fwiz.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:			Started 9/13/01.
 *  
 *  Notes:			
 *  
 *  Change History: 9/14/01[Pure Essence of Fred]
 *  
 *  
 *****************************************************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/spaceport.h"

inherit "/players/vital/closed/std/heal.c";

reset(arg) {
  if(arg) return;
  set_name("fredwiz");
  set_alias("beer");
  set_alt_name("bottle");
  set_type("drink");
  set_short(HIY+"FredWiz"+NORM+" Beer");
  set_long("\
  This is the pure essence of Fred. Daily distilled from the stream \n\
that runs out behind his house. This stuff is pure gold. Like the \n\
old miners say, \"There's Fred in them thar hllls.\"\n");
  set_intox(3);
  set_weight(2);
  set_player_msg("You drink the "+HIY+"FredWiz"+NORM+".\nYou feel the "+RED+"BURN"+NORM+".\n");
  set_room_msg(" is a fool for drinkin' that "+HIY+"FredWiz"+NORM+" Beer!\n");
  set_value(500+random(500));
  set_heal(20+random(10),-5-random(10));
  set_charges(5);
  set_too_drunk("You are a sodden drunk. Clean up your act.\n");
  set_info("This is good stuff Maynard. Drink up!\n");
  set_cmds( ({
    "swig","drink","guzzle","try a drink of"
  }) );
}

long() {
    if(charges > 1) write(long_desc+"There are "+YEL+charges+NORM+" "+type+"s left.\n");
    else write(long_desc+"There is only "+YEL+charges+NORM+" "+type+" left.\n");
}
