/*                                                                    *
 *    File:             /players/angel/area/thanagar/room/hunderwear.c*
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

id(str) { return str == "hunderwear" || str == "underwear"; }

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("underwear");
   set_alias("");
   set_short();
   set_long(  red\n");
   set_ac(1);
   set_type("underwear");
   set_weight(1);
   set_value(500);
}