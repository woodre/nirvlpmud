/******************************************************************************
 *  File:           dfpen.c
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  Source:			Started 1/4/01.
 *  Notes:
 *  Change History: 1/5/01
 *****************************************************************************/
#pragma strict_types
#include <ansi.h>

inherit "/obj/newtreasure.c";

void
reset(status arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("pen");
  set_alias("gold pen");
  set_short("A Gold Plated Pen");
  set_long("This beautiful "+HIY+"gold"+NORM+" plated pen is engraved \n\
a message that you could read. \(read pen\)\n");
  set_weight(0);
  set_value(75+random(760));
  set_read("Given in Honor of 25 years of service.\n");
}
