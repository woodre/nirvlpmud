/******************************************************************************
 *  
 *  File:           malt.c
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
 *  Change History: 9/14/01 [made it malt liquor], 9/16/01,
 *  
 *  
 *****************************************************************************/

#include "/players/vital/vital.h"
#include "/players/vital/dest/dest.h"

inherit "/players/vital/closed/std/heal.c";

reset(arg) {
  if(arg) return;
  set_name("malt");
  set_alias("liquor");
  set_alt_name("bottle");
  set_id( ({
    name, alias, alt_name, "bottle of malt liquor", "hooch", "liquor", "drink", "job"
  }) );
  set_short("J.O.B. Malt Liquor");
  set_long("\
  Women swoon and get funky, men dance faster and smell cleaner, \n\
all because they have a J.O.B. Malt Liquor. Next time you are down \n\
and out just remember to say, \"I need a J.O.B.!\"\n");
  set_intox(5);
  set_weight(1);
  set_player_msg("You tip back your nappy head and drink it dry.\n");
  set_room_msg(" decides to get a J.O.B.\n");
  set_value(15);
  set_heal(10+random(10),5+random(15));
  set_charges(3);
  set_type("drink");
  set_too_drunk("You really don't need another J.O.B. Go sleep it off.\n");
  set_info("The brother's choice drink.\n");
  set_cmds( ({
    "swig","drink","guzzle","get a job"
  }) );
}

long() {
    if(charges > 1) write(long_desc+"You still have "+RED+charges+NORM+" "+type+"s left.\n");
    else write(long_desc+"There is just "+RED+charges+NORM+" "+type+" left.\n");
}
