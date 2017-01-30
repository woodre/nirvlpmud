/******************************************************************************
 *  File:           bell.c
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  Source:         Started 2001.04.01
 *  Notes:
 *  Change History: 2005.10.23 [strict_type'd and fixed ids]
 *****************************************************************************/
#pragma strict_types
#include <ansi.h>
#include "/players/vital/dest/include/spaceport.h"

inherit "/obj/newtreasure.c";

void
reset(status arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("bell");
  set_alias("silver bell");
  set_alt_name("inscription");
  set_short("A "+HIW+"silver"+NORM+" bell");
  set_long("This is a small "+HIW+"silver"+NORM+" bell that is used to ring \n\
for a servant. On the inside is an inscription.\n");
  set_weight(1);
  set_value(75+random(76));
  set_info("This bell is dedicated to the life of Tierra.\n");
  set_read("In Honor of One Who Went Before.\n");
}
