/******************************************************************************
 *  File:           waterling.c
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  Source:         9/26/01.
 *  Notes:			
 *  Change History: 
 *****************************************************************************/

#include "/players/vital/closed/headers/vital.h"

inherit "/players/vital/closed/std/monster.c";

reset(arg)
{
    ::reset(arg);
    if(arg) return;
    set_name("waterling");
    set_alias("dragon");
    set_short("A little " + BLU + "waterling" + NORM);
    set_long("\
This tiny, little dragon is very fluid and lithe.  \n\
The " + BLU + "waterling" + NORM + " has large fins, a sail and it's scales \n\
are " + BLU + "blue" + NORM + " and " + HIW + "white" + NORM + ".\n");
    set_level(random(3) + 3);
    set_info("This " + BLU + "waterling" + NORM + " is called by higher powers to aid in it's bidding.\n");
    set_dead_ob(this_object());
}

monster_died(){
    object corpse, scale;
    corpse = present("corpse", environment());
    corpse->set_name(BLU + "waterling" + NORM);
    corpse->set_value(6);
    say("The " + BLU + "waterling" + NORM + " shudders and collapses.\n");
    scale = CO("/players/vital/closed/std/obj.c");
    scale->set_name("scale");
    scale->set_short(BLU + "waterling" + NORM + " " + HIW + "scale" + NORM);
    scale->set_long("\
  This little " + BLU + "blue " + HIW + "scale" + NORM + " is the only thing between a " + BLU + "waterling" + NORM + " and a \n\
quick death exposed to the elements.\n");
    scale->set_value(25 + random(100));
    scale->set_info("\
  The scales of dead, demon dragons are sought by some shops for \n\
medicinal and aphrodesical purposes.\n");
    scale->set_id( ({
        "waterling scale", "scale", "scales", "Scale", "Waterling Scale"
    }) );
    MO(scale,corpse);
    return 1;
}
