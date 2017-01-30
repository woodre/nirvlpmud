/*                                                                    *
 *    File:             /players/angel/area/stargate/npc/private.c    *
 *    Function:         npc                                           *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2006 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           1/1/06                                        *
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
  set_name("private first class");
  set_alt_name("solider");
  set_race("military");
  set_alias("private");
  set_short(""+CYN+"Private First Class"+NORM+"");
  set_long("\
  The private is a well trained. It would be foolish to fight him!\n\
He can do alot more for you alive than dead!!\n");
  set_level(14);
  set_hp(220 + random (100));
  set_ac(11 + random (7));
  set_wc(18 + random (7));
  set_al(0);
  set_chat_chance(3);
  load_chat(query_name()+" says,\n\
\n\
 \"I can strip a P90 down in 20 seconds!\n\
\n\
  I have a connection that wants P90's.\n\
\n\
  I'll make you a great deal!!\n\
\n\
  Any P90's you give to me, I'll strip out the ammo for you.\"\n");
}