/******************************************************************************
 *  
 *  File:           plasmashield.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 2002 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:			Started 8/28/02.
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
   set_name("plasma");
   set_alias("plasma shield");
   set_short("A plasma shield");
   set_long("This is a standard issue, FPS. It will offer some limited protection in combat. Also useful as a sled in the snow.\n");
   set_ac(1);
   set_info("FPS: Fusion Plasma Shield.\n");
   set_type("shield");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(3);
   set_value(200);
}
