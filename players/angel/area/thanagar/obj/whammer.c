/*                                                                    *
 *    File:             /players/angel/area/thanagar/room/whammer.c   *
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

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("war hamner");
   set_alias("");
   set_short();
   set_long(\n");
   set_ac(1);
   set_type("hammer");
   set_weight(1);
   set_value(500);
}