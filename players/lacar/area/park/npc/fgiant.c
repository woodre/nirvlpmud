/*
*      File:             /players/lacar/area/park/npc/fgiant.c
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
set_name("Gloria");
set_alt_name("gloria");
set_race("giant");
set_short("A female giant");
set_long("A nine foot tall female giant looks down at you. She looks\n\
like a warm inviting giant, but her eyes seem to be scanning you.\n" );
set_level(8);
set_hp(120);
set_al(-250);
set_wc(12);
set_ac(7);
  set_chat_chance(4);
  load_chat(query_name()+" says, \"Come in and sit down\"\n");
  load_chat("Would you like some ale? asks Gloria\n");
  load_chat("Need to fatten you up for stew\n");
  gold=clone_object("obj/money");
  gold->set_money(150);
  move_object(gold,this_object());
  weapon=clone_object("/players/lacar/area/park/obj/rollingpin");
  move_object(weapon,this_object());
  
}