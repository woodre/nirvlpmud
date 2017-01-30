/******************************************************************************
 *  
 *  File:           pga.c
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
 *  Change History: 
 *  
 *  
 *****************************************************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/spaceport.h"

inherit "/players/vital/closed/std/heal.c";

reset(arg) {
  if(arg) return;
  set_name("pga");
  set_alias("alcohol");
  set_alt_name("bottle");
  set_short("A little bottle of PGA");
  set_long("\
  This is a little bottle of Pure Grain Alcohol. Becareful with this \n\
hair-raising, organ-killing, engine-cleaning, fire-breathing, 190 \n\
proof, wildfire. It is a whole-lotta-hooch in an itty-bitty package. \n\
If you're brave, you might try a drink.\n");
  set_intox(3*(TP->query_level()));
  set_weight(1);
  set_player_msg("You heedlessly tip back the bottle of PGA.\n");
  set_room_msg(" throws caution to the wind and guzzles a swig of 190 proof.\n");
  set_value(3);
  set_heal(-15-random(40),-5-random(60));
  set_charges(1);
  set_type("drink");
  set_too_drunk("You are a sodden drunk. Clean up your act.\n");
  set_info("This is good stuff Maynard. Drink up!\n");
  set_cmds( ({
    "swig","drink","guzzle","try a drink of"
  }) );
}

long() {
    if(charges > 1) write(long_desc+"You still have "+BOLD+charges+NORM+" "+type+"s left.\n");
    else write(long_desc+"There is just "+BOLD+charges+NORM+" "+type+" left.\n");
}
