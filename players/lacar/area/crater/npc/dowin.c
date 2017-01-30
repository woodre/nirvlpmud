/*
*      File:             /players/lacar/area/park/npc/dowin.c
*      Function:      npc
*      Author(s):        Lacar@nirvana
*      Copyright:        Copyright (c) 2007 Lacar (Carla J Merrill)
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
set_name("Dowin");
set_alt_name("dowin");
set_race("dowin");
set_short("A Dowin");
set_long("A  dowin is a cross between a squirrel and chipmunk.  A\n"+
"dowin stands three feet high on its back legs. They are light brown\n"+
"in color with black rings on  its tail and a black stripe down its\n"+
"back.\n");
set_level(7);
set_hp(110);
set_al(-250);
set_wc(11);
set_ac(4);
  set_chat_chance(5);
  load_chat(query_name()+" asks, \"Got any food?\"\n");
  load_chat(query_name()+" inquires, \"Who are you?\n");
  load_chat(query_name()+" says, \"Don't cross me or you'll get hurt.\n");
  gold=clone_object("obj/money");
  gold->set_money(50);
  move_object(gold,this_object());
  weapon=clone_object("/players/lacar/area/crater/obj/pinecone.c");
  move_object(weapon,this_object());
  
}