/******************************************************************************
 *  
 *  File:           lacboots.c
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
 *  Change History: 3/3/01,10/19/01,
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
    set_alias("laconian boots");
    set_short("Laconian Boots");
    set_long("\
  These boots are rumored to be very special. Their construction is \n\
without seam or stitches. The fit is nearly perfect as the material \n\
expands and contracts around your foot when you wear it, but \n\
providing excellent protection.\n");
    set_ac(1);
    set_info("\
  These are ancient, alien boots. The legends speak of how these \n\
boots were worn by the greatest heroes of the world.\n");
    set_type("boots");  /* armor,helmet,boots,ring,amulet,shield,misc  */
    set_weight(2);
    set_value(100+random(500));
}

do_special(owner) {
    string msg;
    if(!random(5)) {
        switch(random(10)) {
            case 0: msg = " dance and move around with speed"; break;
            case 1: msg = " kick the enemy in the gut"; break;
            case 2: msg = " move quickly out of the way"; break;
            case 3: msg = "r feet are like lightning"; break;
            case 4: msg = " avoid the attack"; break;
            case 5: msg = " spin quickly on your heel"; break;
            case 6: msg = " feint to the left and dodge right"; break;
            case 7: msg = "r speed is increased"; break;
            case 8: msg = " slide to the left"; break;
            case 9: msg = " slide to the right"; break;
        }
        tell_object(owner,"You"+msg+".\n");
    }
    if(!random(35)) return 4;
}
