/*
*      File:             /players/lacar/area/park/npc/pixief.c
*      Function:        npc
*      Author(s):        Lacar@nirvana
*      Copyright:        Copyright (c) 2006 Lacar (Carla J Merrill)
*                                All Rights Reserved
*      Source:    
*      Notes:            area
*                                                                  
*                                                                  
*      Change History:
*/
inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
set_name("Pixie");
set_race("pixie");
set_short("Female pixie");
set_long("Pixies have the ability to change their size at will. They \n"+
"are a cousin to the fairies but look cuter. \n");
set_level(7);
set_hp(110);
set_al(-250);
set_wc(11);
set_ac(4);
  set_chat_chance(5);
  load_chat(query_name()+" says, \"Don't go that way.\"\n");
  load_chat(query_name()+" says, \"Don't you dare sit in MY pond!\"\n");
  load_chat(query_name()+" asks, \"What are you doing here?\n");
  weapon=clone_object("/players/lacar/area/park/obj/pixiestick.c");
  move_object(weapon,this_object());
  
}