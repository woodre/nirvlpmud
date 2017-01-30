/*
 *      File:                 /players/star/npcs/gnun.c
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
  set_alias("giggling nun");
  set_gender("female");
  set_short("A Giggling Nun");
  set_long("   The nun is average height and is thin.  She has curly red hair and\n"+
    "freckles and is wearing a yellow dress.  She's smiling and chatting\n"+
    "with her friends as they enjoy the last bit of their vacation.\n");
  set_level(10);
  set_hp(150);
  set_al(160);
  set_wc(14);
  set_ac(8);
  set_chat_chance(3);
  load_chat("The nun giggles with her friends.\n");
  add_money(random(100)+250);
  move_object(clone_object(HOTEL+"objs/y_dress.c"));
  init_command("wear dress");
}
