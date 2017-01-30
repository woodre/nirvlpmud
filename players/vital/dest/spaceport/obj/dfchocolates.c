/******************************************************************************
 *  File:           dfchocolates.c
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  Source:         Started 2001.01.05
 *  Notes:          
 *  Change History: 2005.10.23 [strict_type'd and fixed ids]
 *****************************************************************************/
#pragma strict_types
#include <ansi.h>

inherit "/obj/generic_heal.c";

void
reset(status arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("chocolates");
  add_alias("box");
  add_alias("box of chocolates");
  set_short("A Box of Chocolates");
  set_long("These chocolates fairly make your mouth water. You have an \n\
urge to sneak one from the box.\n");
  set_type("chocolate");
  set_msg("You snake your and into the box and swipe a Chocolate.\n");
  set_msg2(" sneaks a Chocolate from the box.\n");
  add_cmd("sneak");
  set_heal(30,15); /* hp,sp */
  set_charges(4);
  set_stuff(19);
  set_value(650); /* This is per charge */
}
