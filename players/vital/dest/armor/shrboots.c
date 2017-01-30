/******************************************************************************
 *  
 *  File:           shrboots.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 2001 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:			Started 1/4/01.
 *  
 *  Notes:			
 *  
 *  Change History: 3/3/01(added set_info());10/19/01,
 *  
 *  
 *****************************************************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/spaceport.h"

inherit "obj/armor";

reset(arg) {
    if(arg) return;
    ::reset(arg);
    set_name("boots");
    set_alias("sheir boots");
    set_short("Shier Boots");
    set_long("\
  The Shier boots are metallic, white boots that have a layer of \n\
metal mesh laid over the top of a soft inner lining.\n");
    set_ac(1);
    set_info("\
  The Shier boots are named for Alys Shier, the fourth queen of \n\
Dalridia. They were popular style many years ago, but have since \n\
passed into history.\n");
    set_type("boots");  /* armor,helmet,boots,ring,amulet,shield,misc  */
    set_weight(2);
    set_value(200+random(400));
}

do_special(owner) {
    if(!random(12)) {
        switch(random(5)) {
            case 0: say(owner->query_name()+" spins around and lashes out with "+owner->query_possessive()+" boot.\n");
                    write("You spin around and lash out with your boot.\n");
                    break;
            case 1: say(owner->query_name()+" kicks the enemy's left side.\n");
                    write("You kick the enemy's left side.\n");
                    break;
            case 2: say(owner->query_name()+" moves with alacrity.\n");
                    write("You move swiftly in and out of battle.\n");
                    break;
            case 3: say(owner->query_name()+" dances around in battle.\n");
                    write("You dance around in battle.\n");
                    break;
            case 4: say(owner->query_name()+" moves like the wind while fighting.\n");
                    write("You fight with speed and fight like the wind.\n");
                    break;
        }
        return 1;
    }
    return 0;
}

