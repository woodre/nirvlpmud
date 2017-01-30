/*
*      File:             /players/lacar/area/park/npc/giant.c
*      Function:         npc
*      Author(s):        Lacar@nirvana
*      Copyright:        Copyright (c) 2006 Lacar (Carla J Merrill)
*                                All Rights Reserved
*      Source:    
*      Notes:            area
*      Change History:
*/
inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
set_name("Ralph");
set_alt_name("ralph");
set_race("giant");
set_short("A male giant");
set_long("A ten foot tall male giant looks down at you. He has a\n"+
"scruffy mustach and beard. His scowl looks really scary.\n");
set_level(8);
set_hp(120);
set_al(-250);
set_wc(12);
set_ac(7);
  set_chat_chance(4);
  load_chat(query_name()+" says, \"Leave before you get hurt!\"\n");
  load_chat("Ready to get squashed?!, yells Ralph\n");
  load_chat("You look good enough to add to wife's stew.\n");
  gold=clone_object("obj/money");
  gold->set_money(250);
  move_object(gold,this_object());
  weapon=clone_object("/players/lacar/area/park/obj/club2");
  move_object(weapon,this_object());
  
}