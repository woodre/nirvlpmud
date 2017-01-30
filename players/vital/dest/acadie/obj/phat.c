/******************************************************************************
 *  
 *  File:           phat.c
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
   set_name("hat");
   set_alias("floppy hat");
   set_short(MAG+"Floppy "+NORM+HIW+"Hat"+NORM);
   set_long("\
  This hat is a large "+HIW+"white"+NORM+" hat with a wide brim and a wide "+MAG+"purple"+NORM+" \n\
band. There is a very ragged "+YEL+"feather"+NORM+" stuck in the band that waves \n\
in the breeze.\n");
   set_ac(1);
   set_info("Women swoon when they see a man in a hat like this.\n");
   set_type("helmet");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(2);
   set_value(random(200)+100);
}

do_special(owner) {
   if(!random(15))
      {
      tell_object(owner, "The "+MAG+"Floppy "+NORM+HIW+"Hat"+NORM+" slides down in your eyes.\nYou hastily tip it back onto your head.\n");
      return -1;
   }
}

