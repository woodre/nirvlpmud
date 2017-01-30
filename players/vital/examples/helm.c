/******************************************************************************
 *  File:           helm.c
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
   set_name("helm");
   set_alias("a helm");
   set_short("A Helm");
   set_long("This is an utterly simple helm.\n");
   set_ac(2);
   set_type("helmet");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(1);
   set_value(0);
}

