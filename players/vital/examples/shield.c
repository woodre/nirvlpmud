/******************************************************************************
 *  File:           shield.c
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  Source:			Started 1/4/01.
 *  Notes:			
 *  Change History: 
 *****************************************************************************/

inherit "obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("shield");
   set_alias("a shield");
   set_short("A Shield");
   set_long("This is an utterly simple shield.\n");
   set_ac(2);
   set_type("shield");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(1);
   set_value(0);
}

