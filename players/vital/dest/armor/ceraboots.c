/******************************************************************************
 *  
 *  File:           ceraboots.c
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
    set_alias("ceramic boots");
    set_short("Ceramic Boots");
    set_long("\
  This pair of boots is woven out of synthetic polymers that have \n\
ceramic molecules bonded to them.\n");
    set_ac(1);
    set_info("These ceramic boots are designed to be a first step in armors.\n");
    set_type("boots");  /* armor,helmet,boots,ring,amulet,shield,misc  */
    set_weight(3);
    set_value(200+random(210));
}

wear(str) {
    int lev;
    if(TP->query_level() < 5) set_ac(2);
    else set_ac(1);
    ::wear();
}