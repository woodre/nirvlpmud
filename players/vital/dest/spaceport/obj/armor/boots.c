/******************************************************************************
 *  File:           shoes.c
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  Source:         Started 2001.04.01
 *  Notes:
 *  Change History: 2001.03.03 (added set_info());
 *                  2005.10.23 [strict_type'd and fixed ids]
 *****************************************************************************/
#pragma strict_types
#include <ansi.h>

inherit "obj/armor";

void
reset(status arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("boots");
  set_alias("soft boots");
  set_short("A pair of soft boots");
  set_long("This pair of soft boots will start you out on many adventures. \n\
The soles are soft and the material is "+BLINK+HIM+"spacey"+NORM+".\n");
  set_ac(1);
  set_info("Simple, ordinary boots you could wear if you so desired.\n");
  set_type("boots");          /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(3);
  set_value(200);
}
