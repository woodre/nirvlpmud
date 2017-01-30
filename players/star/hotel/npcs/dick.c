/*
 *      File:                 /players/star/npcs/dick.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2006 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               01/13/2006
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
  set_name("dick");
  set_race("human");
  set_gender("male");
  set_short("Dick Halloran");
  set_long("Dick Halloran is the Overlook's cook.  He is a huge black man, wearing\n"+
    "cook's whites and a poofy chef's hat.  His smile makes his eyes\n"+
    "twinkle happily.\n");
  set_level(13);
  set_hp(195);
  set_al(45);
  set_wc(17);
  set_ac(10);
  set_chat_chance(3);
  load_chat("Dick's booming laugh echoes through the kitchen.\n");
  add_money(random(100)+350);
  move_object(clone_object(HOTEL+"objs/whites.c"));
  init_command("wear whites");
  move_object(clone_object(HOTEL+"objs/c_hat.c"));
  init_command("wear hat");
}
