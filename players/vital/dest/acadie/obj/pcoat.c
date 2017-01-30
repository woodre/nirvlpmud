/******************************************************************************
 *  
 *  File:           pcoat.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 2001 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:         Started 9/21/01.
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
   set_name("suit");
   set_alias("pimp suit");
   set_short(MAG+"Pimp Suit"+NORM);
   set_long("\
  This is a classic original. The definitive coat for the \n\
descriminating perved-out freakazoid on the poontang trip. Get your \n\
pimp stick ready and roll.\n");
   set_ac(1);
   set_info("Not just any pimp suit, this one has style.\n");
   set_type("misc");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(2);
   set_value(random(600)+200);
}

do_special(owner) {
   switch(random(100)) {
       case   0..9: return -1; break;
       case 10..90: return 0; break;
       case 91..94: tell_object(owner, "The "+MAG+"Pimp Suit"+NORM+" is ace!\n"); return 1; break;
       case 95..98: tell_object(owner, "This fashion owns you.\n"); return 2; break;
       case 99:     tell_object(owner, "The "+MAG+"Pimp Suit"+NORM+" is jimmy-jacked in the throw down.\n"); return 10; destruct(TO);
   }
}
