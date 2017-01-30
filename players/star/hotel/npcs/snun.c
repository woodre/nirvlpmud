/*
 *      File:                 /players/star/npcs/snun.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2005 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               12/01/2005
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
  set_name("nun");
  set_race("human");
  set_alias("smiling nun");
  set_gender("female");
  set_short("A Smiling Nun");
  set_long("   The nun is tall and thin.  She has black hair and is wearing a\n"+
    "green dress.  She's laughing and chatting with her friends as they\n"+
    "enjoy the last bit of their vacation.\n");
  set_level(10);
  set_hp(150);
  set_al(160);
  set_wc(14);
  set_ac(8);
  set_chat_chance(3);
  load_chat("The nun smiles at you.\n");
  add_money(random(100)+250);
  move_object(clone_object(HOTEL+"objs/g_dress.c"));
  init_command("wear dress");
}
