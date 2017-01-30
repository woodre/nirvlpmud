/******************************************************************************
 *  File:           misc.c
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
   set_name("cloak");
   set_alias("a cloak");
   set_short("A Cloak");
   set_long("This is an utterly simple cloak.\n");
   set_ac(2);
   set_type("misc");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(1);
   set_value(0);
}
