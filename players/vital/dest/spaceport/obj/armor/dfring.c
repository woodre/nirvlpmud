/******************************************************************************
 *  File:           dfring.c
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  Source:         Started 2001.01.05
 *  Notes:          
 *  Change History: 2005.10.23 [strict_type'd and fixed id's]
 *****************************************************************************/
#pragma strict_types
#include <ansi.h>

inherit "obj/armor";

void
reset(status arg)
{
  if(arg) return;
  ::reset(arg);
  set_name("ring");
  set_alias("diamond ring");
  set_short("A " + HIW + "Diamond" + NORM + " ring");
  set_long("This ring is gorgeous. It reflects and refracts the light \n\
around within it like a magnificent " + RED + "fire" + NORM +" that draws your \
eyes \nto it like a magnet.\n");
  set_ac(0);
  set_params("other|fire", 2,  20, "fire_resist");
  set_type("ring");
  set_weight(4);
  set_value(275 + random(700));
}

int
fire_resist(object owner)
{
  if(!random(12))
  {
    tell_object(this_player(),
      "The flash of the ring " + HIW + "blinds" + NORM + " the attacker.\n");
    return 1000; /* additional 10% resistance */
  }
}
