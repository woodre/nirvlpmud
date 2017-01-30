/******************************************************************************
 *  File:           fireling.c
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  Source:         Started 3/7/01.
 *  Notes:			
 *  Change History: 9/25/01,9/26/01,
 *****************************************************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"

inherit "/players/vital/closed/std/monster.c";

reset(arg)
{
    ::reset(arg);
    if(arg) return;
    set_name("fireling");
    set_alias("dragon");
    set_short("A little " + RED + "fireling" + NORM);
    set_long("\
This tiny, little dragon is not strong, but very fast.  \n\
The fireling is glowing with " + RED + "f" + HIR + "l" + NORM + YEL + "a" + HIY + "m" + NORM + RED + "e" + NORM + " and it's scales \n\
are " + RED + "red" + NORM + " and " + HIY + "gold" + NORM + ".\n");
    set_level(random(3) + 3);
    set_info("This " + RED + "fireling" + NORM + 
        " is called by higher powers to aid in it's bidding.\n");
    set_dead_ob(this_object());
}

monster_died(){
    object corpse, scale;
    corpse = present("corpse", environment());
    corpse->set_name(RED + "fireling" + NORM);
    corpse->set_value(6);
    say("The " + RED + "fireling" + NORM + " shudders and collapses.\n");
    scale = CO("/players/vital/closed/std/obj.c");
    scale->set_name("scale");
    scale->set_short(RED + "fireling" + NORM + " " + HIW + "scale" + NORM);
    scale->set_long("\  This little " + RED + "red " + HIW + "scale" + NORM + 
        " is the only thing between a " + RED + "fireling" + NORM + 
        " and a \nquick death exposed to the elements.\n");
    scale->set_value(25 + random(100));
    scale->set_info("\
  The scales of dead, demon dragons are sought by some shops for \n\
medicinal and aphrodesical purposes.\n");
    scale->set_id( 
    ({
        "fireling scale", "scale", "scales", "Scale", "Fireling Scale"
    }) );
    MO(scale,corpse);
    return 1;
}
