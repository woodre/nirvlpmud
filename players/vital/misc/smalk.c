/******************************************************************************
 *  File:           smalk.c
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  Source:         11/29/01.
 *  Notes:          another small mob for newbies to kill	
 *  Change History: 
 *****************************************************************************/

#include "/players/vital/closed/headers/vital.h"
inherit "/players/vital/closed/std/monster.c";

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("smalk");
    set_alias("dragon");
    set_short("A " + MAG + "smalk" + NORM);
    set_long("\
This is a type of dragon unique to the arid, rocky lands around you. \n\
It has thin, spindly legs and a narrow body, covered in the same \n\
purple scales as many of the other rock denizens. The small, black \n\
eyes seem to peer directly into your soul.\n");
    set_level(random(3) + 3);
    set_attrib("sta",15);
    set_info("This " + MAG + "smalk" + NORM + " is a cunning hunter of heat.\n");
    set_dead_ob(this_object());
}

monster_died(){
    object corpse, eye;
    corpse = present("corpse", environment());
    corpse->set_name(MAG + "smalk" + NORM);
    corpse->set_value(6);
    say("The " + MAG + "smalk" + NORM + " shudders and falls to the ground.\n");
    eye = CO("/players/vital/closed/std/obj.c");
    eye->set_name("eye");
    eye->set_short(MAG + "smalk" + NORM + " " + HIB + "eye" + NORM);
    eye->set_long("\
  These dark, black orbs look smooth and very hard. They remind you of \n\
pearls or perhaps carbonado.\n");
    eye->set_value(25 + random(100));
    eye->set_info("\
  The eyes of dead, demon dragons are sought by some shops for \n\
jewellery and good luck.\n");
    eye->set_id( ({
        "smalk eye", "eye", "eyes", "Eye", "Smalk Eye"
    }) );
    MO(eye,corpse);
    return 1;
}
