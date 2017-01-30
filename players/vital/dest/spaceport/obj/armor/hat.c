/******************************************************************************
 *  File:           hat.c
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  Source:         Started 2001.01.04
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
  set_name("hat");
  set_alias("small hat");
  set_short("A small hat");
  set_long("This small hat offers minimal protection and coverage from \n\
elements and adventure.\n");
  set_ac(1);
  set_params( "other|water", 1, 10, "rain_stop" );
  set_params( "other|wind",  1, 10, "wind_stop" );
  set_type("helmet");         /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(2);
  set_value(140+random(40));
}


int
rain_stop(object owner)
{
  if ( !random(20) )
  {
    write("You adjust your hat to keep out the water.\n");
    if (environment() && environment(owner) )
      tell_room(environment(owner), owner->query_name() +
        " adjusts " + possessive(owner) + " hat to keep out the water.\n");
    return 1002; /* additional 10% resistance and 2 water ac */
  }
}

int
wind_stop(object owner)
{
  if ( !random(20) )
  {
    write("You pull your hat down to block the wind.\n");
    if (environment() && environment(owner) )
      tell_room(environment(owner), owner->query_name() +
        " pulls " + possessive(owner) + " hat down to block the wind.\n");
    return 1002; /* additional 10% resistance and 2 water ac */
  }
}