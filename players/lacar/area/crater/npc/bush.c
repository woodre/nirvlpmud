/*
*      File:             /players/lacar/area/crater/npc/bush.c
*      Function:      npc
*      Author(s):        Lacar@nirvana
*      Copyright:        Copyright (c) 2007 Lacar (Carla J Merrill)
*                                All Rights Reserved
*      Source:    
*      Notes:            area
*      Change History:
*/
#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
set_name("Bush");
set_alt_name("bush");
set_race("plant");
set_short(HIG+"green bush"+NORM);
set_long("A thick green bush with many braches and leaves on it. It\n"+
"rises to four feet from the ground. The leaves give it a round\n"+
"shape making it look really big.\n");
set_level(7);
set_hp(110);
set_al(-250);
set_wc(11);
set_ac(4);
  set_chat_chance(5);
  load_chat(query_name()+" states, \"Get out or else!\"\n");
  load_chat(query_name()+" inquires, \"What are you doing here?\n");
  load_chat(query_name()+" says, \"My branches may look nice but can hurt.\n");
  gold=clone_object("obj/money");
  gold->set_money(50);
  move_object(gold,this_object());
  weapon=clone_object("/players/lacar/area/crater/obj/branch.c");
  move_object(weapon,this_object());
  
}