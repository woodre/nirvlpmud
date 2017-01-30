/******************************************************************************
 *  
 *  File:           boots.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:			Started 9/20/01.
 *  
 *  Notes:			
 *  
 *  Change History: 
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
   set_alias("snakeskin boots");
   set_short(MAG+"Snakeskin Boots"+NORM);
   set_long("\
  This pair of boots are crafted from rattlesnake skin boots died a \n\
bright "+MAG+"purple"+NORM+". No self-respecting, street-smart, cool dude would \n\
venture out without a pair of boots like these.\n");
   set_ac(1);
   set_info("Snakeskin boots stolen from a thief. \nWear with pride.\n");
   set_type("boots");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(2);
   set_value(200);
}

do_special(owner) {
   switch(random(50)) {
       case 0..45: return 0;
       case 46..48: 
           tell_object(owner, "The "+MAG+"Snakeskin Boots"+NORM+" slow you down.\n");
           return -1; break;
       case 49: tell_object(owner, "The "+MAG+"Snakeskin Boots"+NORM+" really \"Kick Butt\" in battle.\n");
           return 2; break;
   }
}

