/*
*      File:             /players/lacar/area/park/npc/fairyf.c
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
set_name("Winks");
set_alt_name("winks");
set_race("fairy");
set_short("Female glowing fairy");
set_long("A four feet five inches tall winged female fairy. She smiles\n"+
"and seems to light up the room.\n");
set_level(7);
set_hp(110);
set_al(-250);
set_wc(11);
set_ac(4);
  set_chat_chance(5);
  load_chat(query_name()+" says, \"How may I direct you?\"\n");
  load_chat(query_name()+" asks, \"What direction are you going in?\n");
  load_chat(query_name()+" asks, \"Have you climbed any trees today?\n");
  gold=clone_object("obj/money");
  gold->set_money(50);
  move_object(gold,this_object());
  weapon=clone_object("/players/lacar/area/park/obj/fairywingsf.c");
  move_object(weapon,this_object());
  
}