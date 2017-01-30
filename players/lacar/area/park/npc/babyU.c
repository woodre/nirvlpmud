/*
*      File:             /players/lacar/area/park/npc/babyU.c
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
set_name("Baby unicorn");
set_alt_name("baby");
set_race("unicorn");
set_alias("unicorn");
set_short("A grey baby unicorn");
set_long("A small baby unicorn with a tan horn, flowing mane and tail.\n"+
"He is lying on his cushion.\n");
set_level(100);
set_hp(200);
set_al(-250);
set_wc(11);
set_ac(10);
  set_chat_chance(2);
  load_chat("Baby unicorn raises his head to watch you\n");
  load_chat("Baby Unicorn neighs,\"what you doing?\"\n");
  load_chat("\"Are you going to search?\", says Unicorn.\n");
  load_chat("Baby unicorn puts his head down and sneaks looks at you.\n");
}


/* make this npc completely non-fightable */
query_ghost(){ return 1; }
  
