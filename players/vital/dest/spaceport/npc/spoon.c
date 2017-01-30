/******************************************************************************
 *  
 *  File:           spoon.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
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

inherit "/players/vital/closed/std/obj.c";

reset(arg) {
   if(arg) return;
   set_name("plastic spoon");
   set_alias("spoon");
   set_short("A spoon");
   set_long("This is a small plastic spoon that hates you.\n");
   set_weight(0);
   set_value(0);
   set_read("The current value of this chit is "+HIC+query_value()+NORM+" coins.\n");
    set_info("Nothing but plastic dinnerware here.\n");
}
