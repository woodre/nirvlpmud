/*                                                                    *
 *    File:             /players/angel/closed/lucifer.c               *
 *    Function:         npc                                           *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2009 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           06/22/09                                      *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("lucifer");
  set_alt_name("devil");
  set_race("demon");
  set_alias("demon");
  set_short(""+RED+"Lucifer"+NORM+"");
  set_long("\This is Lucifer. You are his BITCH from this point on!\n");
  set_level(29);
  set_hp(2000 + random (100));
  set_ac(28 + random (5));
  set_wc(55 + random (5));
  set_al(0);
  set_heal(5,10);
  set_chat_chance(5);
  load_chat(" \n");
  load_chat(" \n");
}