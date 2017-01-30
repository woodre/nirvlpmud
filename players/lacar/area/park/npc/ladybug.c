/*
*      File:             /players/lacar/area/park/npc/ladybug.c
*      Function:         npc
*      Author(s):        Lacar@nirvana
*      Copyright:        Copyright (c) 2006 Lacar (Carla J Merrill)
*                                All Rights Reserved
*      Source:    
*      Notes:            area
*/
inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
set_name("lady");
set_race("ladybug");
set_short("A spotted ladybug");
set_long("A three foot round ladybug. She is red with black spots that\n"+
"hide her wings.\n");
set_level(7);
set_hp(110);
set_al(-250);
set_wc(11);
set_ac(6);
  set_chat_chance(10);
  load_chat(query_name()+" asks, \"Want to fly away with me?\"\n");
  load_chat(query_name()+" says, \"Come fly around the trees.\"\n");
  weapon=clone_object("/players/lacar/area/park/obj/lwings.c");
  move_object(weapon,this_object());
  
}