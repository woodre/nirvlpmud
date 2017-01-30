/*                                                                    *
 *    File: valen  /players/valen/area/catacombs/armors/d_belt.c      *
 *    Function:         belt                                          *
 *    Author(s):        valen@Nirvana                                 *
 *    Copyright:        Copyright (c) 2009 valen                      *
 *                              All Rights Reserved.                  *
 *    Source:           08/12/09                                      *
 *    Notes:            belt object                                   *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "obj/armor";

reset(arg)
{
  ::reset(arg);
   if(arg) return;
   set_name("belt");
   set_alias("black belt");
   set_short("A black belt "+RED+"<Demon Cursed>"+NORM);
   set_long("a black leather belt "+RED+"<Demon Cursed>"+NORM+"\n"+
   "The belt glows with a red aura.\n");
   set_ac(1);
   set_type("belt");
   set_weight(1);
   set_value(random(500)+500);
}

do_special(owner)
{
  if(!worn) return;
  if (!owner || !owner->query_attack())
  return;
  if(random(20) < 6)
  {
    tell_object(owner, "The "+RED+"red aura"+NORM+" around the belt flashes "+HIR+BLINK+"bright red"+NORM+"\n");
    tell_room(environment(owner),
    owner->query_name()+" is surrounded by a "+RED+"red aura"+NORM+" flashing "+HIR+BLINK+"bright red!"+NORM+"\n"+
    "The "+RED+"red aura"+NORM+" begins to disappear.\n", ({ owner }));
    owner->add_hit_point(random(5));
    return 1;
  }
  return;
}
