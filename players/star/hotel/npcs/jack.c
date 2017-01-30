/*
 *      File:                 /players/star/npcs/jack.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2006 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               01/03/2006
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
  set_name("jack");
  set_race("human");
  set_gender("male");
  set_short("Jack Torrance");
  set_long("This is the Overlook's new winter caretaker.  When the last of the\n"+
    "guests leave he and his family will remain here to be snowed in.  He\n"+
    "honestly does not look stable enough for the job.\n");
  set_level(14);
  set_hp(220);
  set_al(-50);
  set_wc(18);
  set_ac(11);
  set_chat_chance(3);
  load_chat("Jack rubs his lips with a handkerchief.\n");
  load_chat("Jack pops an Excedrin tablet into his mouth and chews it up.\n");
  load_chat("Jack swings his roque mallet menacingly.\n");
  add_money(random(100)+200);
  move_object(clone_object(HOTEL+"objs/mallet.c"));
  init_command("wield mallet");
  move_object(clone_object(HOTEL+"objs/hanky.c"));
  move_object(clone_object(HOTEL+"objs/apt_key.c"));
}
