/******************************************************************************
 *  File:           scorpion.c
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  Source:         12/3/01
 *  Notes:          
 *  Change History: 
 *****************************************************************************/

#include "/players/vital/closed/headers/vital.h"
inherit "/players/vital/closed/std/monster.c";

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("scorpion");
    set_alias("Scorpion");
    set_short("A little " + MAG + "scorpion" + NORM);
    set_long("\
This tiny, little scorpion is very strong, but very slow.  The " + MAG + "\n\
scorpion" + NORM + " has no wings, several short legs and it's tail is \n\
" + MAG + "purple" + NORM + " and " + HIW + "white" + NORM + ".\n");
    set_level(random(3) + 2);
    set_attrib("sta",15);
    set_info("This " + MAG + "scorpion" + NORM + " is fairly harmless.\n");
    set_dead_ob(this_object());
}

monster_died(){
    object corpse, tail;
    corpse = present("corpse", environment());
    corpse->set_name(MAG + "scorpion" + NORM);
    corpse->set_value(6);
    say("The " + MAG + "scorpion" + NORM + " shudders and collapses.\n");
    tail = CO("/players/vital/closed/std/obj.c");
    tail->set_name("tail");
    tail->set_short(MAG + "scorpion" + NORM + " " + HIW + "tail" + NORM);
    tail->set_long("\
  This little " + MAG + "purple " + HIW + "tail" + NORM + " is the only thing between a " + MAG + "scorpion" + NORM + "  \n\
and an enemy.\n");
    tail->set_value(25 + random(50));
    tail->set_info("\
  The tails of dead scorpions may be worth some money but often \n\
they are simply thrown away.\n");
    tail->set_id( ({
        "scorpion tail", "tail", "tails", "Tail", "Scorpion Tail"
    }) );
    MO(tail,corpse);
    return 1;
}
