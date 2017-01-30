/*
 *      File:                 /players/star/npcs/lnun.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2005 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               11/30/2005
 *      Notes:
 *      Change History:
 */

#include <ansi.h>
#include </players/star/defs.h>

inherit "obj/monster";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name ("nun");
  set_race("human");
  set_alias("laughing nun");
  set_gender("female");
  set_short("A Laughing Nun");
  set_long("   The nun is short and stout.  She has blonde hair and is wearing a\n"+
    "blue dress.  She's laughing and chatting with her friends as they\n"+
    "enjoy the last bit of their vacation.\n");
  set_level(10);
  set_hp(150);
  set_al(160);
  set_wc(14);
  set_ac(8);
  set_chat_chance(3);
  load_chat("The nun laughs with her friends.\n");
  add_money(random(100)+250);
  move_object(clone_object(HOTEL+"objs/b_dress.c"));
  init_command("wear dress");
}
