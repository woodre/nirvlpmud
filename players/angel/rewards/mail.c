/*                                                                    *
 *    File:             /players/angel/rewards/mail.c                 *
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

inherit "obj/armor";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("mithril mail");
  set_alias("mithril");
  set_short(CYN+"Legendary Mithril Mail"+NORM);
  set_long("\
The legendary Mithril Mail.  It lays so smoothly and lightly\n\
on you that you can wear it with any other armor.\n");
  set_ac(3);
  set_type("misc");
  set_weight(1);
  set_value(0);
}

drop() { return 1; }

query_auto_load() { return "players/angel/rewards/mail.c:"; }