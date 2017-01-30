/*                                                                    *
 *    File:             /players/angel/tools/belt.c                    *
 *    Function:         room                                          *
 *    Author(s):        Angel & Katya @Nirvana                        *
 *    Copyright:        Copyright (c) 2007                            *
 *                              All Rights Reserved.                  *
 *    Source:           07/25/07                                      *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "obj/container.c";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("belt");
  set_short(HIB+"Money Belt"+NORM);
  set_long(
  " This is a Money belt pack to store extra money so it doesn't\n"+
  "get lost.  This is a small fabric pouch secured with a zipper\n"+
  "and worn at the waist by a strap around the hips.  Belt packs\n"+
  "are used by travelers to secure important items such as there\n"+
  "money.  Designed by Angel and Katya.\n");
  set_weight(0);
  set_value(0);
  set_no_clean(0);
  set_max_weight(26);

}

drop() { return 1; }

query_auto_load() { return "players/angel/tools/belt.c:"; }