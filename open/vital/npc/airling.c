/******************************************************************************
 *  
 *  File:           airling.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:         Started 9/26/01
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
    set_name("airling");
    set_alias("dragon");
    set_short("A little "+CYN+"airling"+NORM);
    set_long("\
This tiny, little dragon is not strong, but very etheriel.  \n\
The airling is swirling with clouds and it's scales \n\
are a light "+CYN+"cyan"+NORM+" and "+HIW+"white"+NORM+".\n");
    set_level(random(3)+3);
    set_info("This "+CYN+"airling"+NORM+" is called by higher powers to aid in it's bidding.\n");
    set_dead_ob(this_object());
    call_out("tell_verte",10);
}

tell_verte() {
    remove_callout("tell_verte");
    call_out("tell_verte",10);
    if(!find_player("vertebraker") return;
    tell_object(find_player("vertebraker"),"Vital had to go home, dest this mob in my workroom.c");
    return;
}

monster_died(){
    object corpse, scale;
    corpse = present("corpse", environment());
    corpse->set_name(CYN+"airling"+NORM);
    corpse->set_value(6);
    say("The "+CYN+"airling"+NORM+" shudders and collapses.\n");
    scale = CO("/players/vital/closed/std/obj.c");
    scale->set_name("scale");
    scale->set_short(CYN+"airling"+NORM+" "+HIW+"scale"+NORM);
    scale->set_long("\
  This little light "+CYN+"cyan "+HIW+"scale"+NORM+" is the only thing between an "+CYN+"airling"+NORM+" \n\
and a quick death exposed to the elements.\n");
    scale->set_value(25+random(100));
    scale->set_info("\
  The scales of dead, demon dragons are sought by some shops for \n\
medicinal and aphrodesical purposes.\n");
    scale->set_id( ({
        "airling scale", "scale", "scales", "Scale", "Airling Scale"
    }) );
    MO(scale,corpse);
    return 1;
}
