/******************************************************************************
 *  
 *  File:           hboots.c
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
 *  Change History: 3/3/01(added set_info()),10/26/01,
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
    set_alias("hiking boots");
    set_short("Hiking Boots");
    set_long("\
  This pair of hiking boots are very strong and sturdy, without being \n\
bulky and heavy.\n");
    set_ac(1);
    set_info("Sturdy, lightweight boots that provide a stable footing.\n");
    set_type("boots");  /* armor,helmet,boots,ring,amulet,shield,misc  */
    set_weight(1);
    set_value(150+random(200));
}
