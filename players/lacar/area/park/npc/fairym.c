/*
*      File:             /players/lacar/area/park/npc/fairym.c
*      Function:      npc
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
set_name("Zeek");
set_alt_name("zeek");
set_race("fairy");
set_short("Male glowing fairy");
set_long("A four feet five inches tall winged male fairy. He seems to\n"+
"make you feel so happy.\n");
set_level(7);
set_hp(110);
set_al(-250);
set_wc(11);
set_ac(4);
  set_chat_chance(5);
  load_chat(query_name()+" asks, \"How may I help you?\"\n");
  load_chat(query_name()+" inquires, \"What are you doing today?\n");
  gold=clone_object("obj/money");
  gold->set_money(50);
  move_object(gold,this_object());
  weapon=clone_object("/players/lacar/area/park/obj/fairywingsm.c");
  move_object(weapon,this_object());
  
}