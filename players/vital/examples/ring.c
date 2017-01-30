/******************************************************************************
 *  File:           ring.c
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  Source:			Started 1/5/01.
 *  Notes:			
 *  Change History: 
 *****************************************************************************/

inherit "obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("ring");
   set_alias("aring");
   set_short("A Ring");
   set_long("This is an utterly simple ring.\n");
   set_ac(2);
   set_type("ring");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(1);
   set_value(0);
}
