/******************************************************************************
 *  
 *  File:           dimate.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 1997-2002 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:			Started 9/13/01.
 *  
 *  Notes:			
 *  
 *  Change History: 9/14/01, 4/25/02
 *  
 *  
 *****************************************************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/spaceport.h"

inherit "/players/vital/closed/std/heal.c";

reset(arg) {
  if(arg) return;
  set_name("dimate");
  set_alias("di");
  set_alt_name("di mate");
  set_id( ({
    name, alias, alt_name, "heal", "vial"
  }) );
  set_short("Dimate");
  set_long("\
  This small vial has a built in trigger mechanism that, when pressed \n\
against the skin, releases several microscopic needles into the skin \n\
which pushes the thick green liquid into your body.\n");
  set_intox(1);
  set_stuff(2);
  set_weight(1);
  set_player_msg("You grab the vial and press the end against your skin.\n");
  set_room_msg(" uses a small vial.\n");
  set_value(150+random(300));
  set_heal(11+random(20),11+random(20));
  set_charges(1);
  set_type("shot");
  set_too_drunk("You cannot handle the effects of another shot.\n");
  set_too_full("You are too full to take another shot.\n");
  set_info("This is a medium level heal that varies in strength.\n");
  set_cmds( ({
    "press", "pressed", "use"
  }) );
}

long() {
    if(charges > 1) write(long_desc+"You still have "+GRN+charges+NORM+" "+type+"s left.\n");
    else write(long_desc+"There is just "+GRN+charges+NORM+" "+type+" left.\n");
}
