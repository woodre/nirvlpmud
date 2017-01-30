/******************************************************************************
 *  
 *  File:           rockling.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:         9/26/01.
 *  
 *  Notes:			
 *  
 *  Change History: 
 *  
 *  
 *****************************************************************************/

#include "/players/vital/vital.h"
inherit "/players/vital/closed/std/monster.c";

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("rockling");
    set_alias("dragon");
    set_short("A little "+MAG+"rockling"+NORM);
    set_long("\
This tiny, little dragon is very strong, but very slow.  \n\
The "+MAG+"rockling"+NORM+" has no wings, short legs and it's scales \n\
are "+MAG+"purple"+NORM+" and "+HIW+"white"+NORM+".\n");
    set_level(random(3)+3);
    set_attrib("sta",15);
    set_info("This "+MAG+"rockling"+NORM+" is called by higher powers to aid in it's bidding.\n");
    set_dead_ob(this_object());
}

monster_died(){
    object corpse, scale;
    corpse = present("corpse", environment());
    corpse->set_name(MAG+"rockling"+NORM);
    corpse->set_value(6);
    say("The "+MAG+"rockling"+NORM+" shudders and collapses.\n");
    scale = CO("/players/vital/closed/std/obj.c");
    scale->set_name("scale");
    scale->set_short(MAG+"rockling"+NORM+" "+HIW+"scale"+NORM);
    scale->set_long("\
  This little "+MAG+"purple "+HIW+"scale"+NORM+" is the only thing between a "+MAG+"rockling"+NORM+" and a \n\
quick death exposed to the elements.\n");
    scale->set_value(25+random(100));
    scale->set_info("\
  The scales of dead, demon dragons are sought by some shops for \n\
medicinal and aphrodesical purposes.\n");
    scale->set_id( ({
        "rockling scale", "scale", "scales", "Scale", "Rockling Scale"
    }) );
    MO(scale,corpse);
    return 1;
}
