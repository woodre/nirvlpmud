/******************************************************************************
 *  
 *  File:           boots.c
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
 *  Change History: 3/3/01(added set_info());
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
    set_alias("vitredur boots");
    set_short("Vitredur Boots");
    set_long("\
  These boots are formed from the standard material found around the \n\
universe. The boots are light brown and very hard to the touch. They \n\
are lined with a soft, smooth material to cushion the soles.\n");
    set_ac(1);
    set_info("Vitredur is a smooth, hard material used in everything from \n\
surgery tools to vehicle parts. It is extremely durable and firm.\n");
    set_type("boots");  /* armor,helmet,boots,ring,amulet,shield,misc  */
    set_weight(2);
    set_value(150);
}
