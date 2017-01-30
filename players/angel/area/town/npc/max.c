/*                                                                            *
 *      File:             /players/angel/area/town/npc/max.c                  *
 *      Function:         NPC                                                 *
 *      Author(s):        Angel@Nirvana                                       *
 *      Copyright:        Copyright (c) 2007 Angel                            *
 *                                All Rights Reserved.                        *
 *      Source:           06/20/07                                            *
 *      Notes:                                                                *
 *                                                                            *
 *                                                                            *
 *      Change History:                                                       *
 */

#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("max");
  set_race("human");
  set_alias("barber");
  set_short("MAX [Barber ]");
  set_long("\An older man who appears to be in his late 50's.\n\
He looks well groomed and vary wise!\n");
  set_level(30);
  set_hp(10000);
  set_wc(60);
  set_ac(60);
  set_al(1000);
  set_chat_chance(12);
  load_chat(query_name()+" asks, \"What can I do for you today?\"\n");
}