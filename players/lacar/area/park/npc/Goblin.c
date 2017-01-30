/*
*      File:             /players/lacar/area/park/npc/Goblin.c
*      Function:         npc
*      Author(s):        Lacar@nirvana
*      Copyright:        Copyright (c) 2006 Lacar (Carla J Merrill)
*                                All Rights Reserved
*      Source:    
*      Notes:            area
*                                                                  
*      Change History:
*/
inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
set_name("goblin");
set_race("goblin");
set_short("A ugly goblin");
set_long("A four foot high goblin glares at you. His eyes seem to\n"+
"pierce through anything.\n");
set_level(7);
set_hp(110);
set_al(-250);
set_wc(11);
set_ac(6);
  set_chat_chance(10);
  load_chat(query_name()+" says, \"Ready to fight someone half your size?\"\n");
  load_chat("Let me at those knee caps!, yells Goblin.\n");
  gold=clone_object("obj/money");
  gold->set_money(50);
  move_object(gold,this_object());
  weapon=clone_object("/players/lacar/area/park/obj/club.c");
  move_object(weapon,this_object());
  
}