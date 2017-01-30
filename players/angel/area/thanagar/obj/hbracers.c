/*                                                                    *
 *    File:             /players/angel/area/thanagar/room/hbracers.c  *
 *    Function:         obj                                           *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2008 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           08/08/08                                      *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "/obj/armor";

id(str) { return str == "hbracers" || str == "bracers"; }

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("bracers");
   set_alias("");
   set_short();
   set_long(  gold\n");
   set_ac(1);
   set_type("bracelet");
   set_weight(1);
   set_value(500);
}



"Nth Metal" to defy gravity and allow them to fly. The metal is in their costume's belt,
 boots and wings. Its abilities are controlled mentally. Their wings allow them to control
  their flight, though they can be "flapped" through use of shoulder motions.
  
  f Nth metal is the ability to negate gravity, allowing a person wearing an object, such as a belt,
   made of Nth Metal to fly. In addition, Nth metal also protects the wearer from the elements and 
   speeds the healing of wounds, increases their strength, and protects them from extremes in temperature.