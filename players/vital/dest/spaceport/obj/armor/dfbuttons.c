/******************************************************************************
 *  File:           dfbuttons.c
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  Source:         Started 2001.01.05
 *  Notes:          
 *  Change History: 2005.10.23 [strict_type'd and fixed ids]
 *****************************************************************************/
#pragma strict_types
#include <ansi.h>

inherit "obj/armor";

void
reset(status arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("buttons");
  set_alias("cashmere buttons");
  set_short(HIR+"Cashmere" + NORM + " " + HIB + "Buttons" + NORM);
  set_long(format("These beautiful buttons are like none you have ever \
seen. They feel soft and luxurious beneath your fingers. They hold your \
clothes up with the precision of finely crafted materials and workmanship."));
  set_ac(0);
  set_params("other|good", 2, 30);
  set_type("misc");
  set_weight(1);
  set_value(995+random(700));
}

int
do_special(object owner)
{
  if(!random(20))
  {
    tell_object(owner, "The soft fuzzy buttons absorb a blow.\n");
    return 2;
  }
}
