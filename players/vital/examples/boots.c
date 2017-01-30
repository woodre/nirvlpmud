/******************************************************************************
 *  File:           boots.c
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  Source:			
 *  Notes:			
 *  Change History: 04/09/2005 - example
 *****************************************************************************/
#include <ansi.h>
inherit "/obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("boots");
   set_alias("a boots");
   set_short("A Boots");
   set_long("This is an utterly simple boots\n");
   set_ac(1);
   set_type("boots");   /* armor,helmet,boots,ring,amulet,shield,misc,  */
   set_weight(2);       /* chest,necklace,cloak,bracelet,pants,gloves,  */
   set_value(0);        /* earing,underwear                             */
}

