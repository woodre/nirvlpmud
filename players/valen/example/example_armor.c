/*                                                                    *
 *    File: (EXAMPLE)  /players/angel/area/thanagar/obj/armor.c       *
 *    Function:         full plate                                    *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2007 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           11/15/07                                      *
 *    Notes:            Area Entrance                                 *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

inherit "obj/armor";

reset(arg)
{
   if(arg) return;
   ::reset(arg);
   set_name("armor");
   set_alias("an armor");
   set_short("An Armor");
   set_long("This is an utterly simple armor.\n");
   set_ac(3);
   set_type("armor");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(1);
   set_value(0);
}

