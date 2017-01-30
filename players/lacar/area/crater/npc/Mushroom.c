/*
*      File:            	 	/players/lacar/area/crater/npc/Mushroom.c
*      Function:    	npc
*      Author(s):   	Lacar@nirvana
*      Copyright:  	Copyright (c) 2007 Lacar (Carla J Merrill)
*                          	All Rights Reserved
*      Source:    
*      Notes:            area
*      Change History:
*/
inherit "obj/monster";

reset(arg)
{
  object heal;
  ::reset(arg);
  if(arg) return;
set_name("Mushroom");
set_alt_name("mushroom");
set_race("plant");
set_short("A large mushroom");
set_long("A five foot grey mushroom covered with green spores. It has\n"+
"been changed from a regular mushroom to a scary one.\n");
set_level(8);
set_hp(120);
set_al(-250);
set_wc(12);
set_ac(7);
  set_chat_chance(4);
  load_chat(query_name()+" says, \"Leave before I squish you!\"\n");
  load_chat("Want some more of this?!\n");
  heal=clone_object("/players/lacar/area/crater/obj/spore");
  move_object(heal,this_object());
  add_spell("spew","#MN# spews $HR$posion$N$ at you.\n",
	"#MN# spews $HR$posion$N$ at #TN#.\n",
	75,30,"other|poison");
}