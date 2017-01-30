/*                                                                    *
 *    File:             /players/angel/area/thanagar/room/hleggings.c *
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

id(str) { return str == "hleggings" || str == "leggings"; }

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("leggings");
   set_alias("legging");
   set_short(HIY+"Hawkman's+NORM HIG+Green+NORM YEL+Leggings"+NORM);
   set_long("Hawkman's Green Leggings made of      from his home planet! green\n");
   set_ac(1);
   set_type("pants");
   set_weight(1);
   set_value(500);
}

do_special(owner) {
   if(!owner || !owner->query_attack()) return 1;
   if(!owner->is_player()) return 1;
   if(random(owner->query_attrib("str")) > random(70)) {
      tell_object(owner, HIY+"The strength of Manhawk's Leggings protecet you!\n"+NORM);
      owner->add_hit_point(random(5));
      return 5;
      }
}