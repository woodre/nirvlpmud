/*
*      File:             /players/lacar/area/park/npc/gryffon.c
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
set_name("Ember");
set_alt_name("ember");
set_race("gryffon");
set_short("A tan gryffon");
set_long("A eight foot tall gryffon. She has the head of an eagle, front\n"+
"claws of a bird. Her back legs and body are of a lion. Her wing span\n"+
"is eight feet wide.\n");
set_level(8);
set_hp(110);
set_al(-250);
set_wc(11);
set_ac(6);
  set_chat_chance(10);
  load_chat(query_name()+" asks, \"Can I have you as a snack?\"\n");
  load_chat(query_name()+" says,\"It is my time to eat!.\"\n");
  gold=clone_object("obj/money");
  gold->set_money(150);
  move_object(gold,this_object());
  weapon=clone_object("/players/lacar/area/park/obj/club.c");
  move_object(weapon,this_object());
  
}