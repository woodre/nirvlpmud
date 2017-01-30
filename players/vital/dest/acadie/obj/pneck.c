/******************************************************************************
 *  
 *  File:           pneck.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 2001 Vital@Nirvana
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
   set_name("chain");
   set_alias("gold chain");
   set_short(HIY+"G"+NORM+YEL+"o"+HIY+"l"+NORM+YEL+"d"+HIY+" C"+NORM+YEL+"h"+NORM+YEL+""+NORM+YEL+""+HIY+"a"+NORM+YEL+"i"+HIY+"n"+NORM);
   set_long("\
  This is a "+HIW+"large, "+HIY+"gold"+NORM+" chain that weighs nearly 10 kilos. The money \n\
for this chain probably wasn't earned legally. With a chain like \n\
this you could strain your neck or at least deflect a stray blow.\n");
   set_ac(1);
   set_info("Gold, gold, gold. Mr. T. would be very proud of you.\n");
   set_type("amulet");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(3);
   set_value(random(400)+100);
}

do_special(owner) {
   if(!random(12))
      {
      tell_object(owner, "The "+HIY+"Gold Chain"+NORM+" deflects your enemies blows.\n");
      return 1;
   }
}
