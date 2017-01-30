/*
*      File:             /players/lacar/area/park/npc/fwizardT.c
*      Function:        npc
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
set_name("tori");
set_alias("wizard");
set_race("human");
set_short("Female wizard");
set_long("Tori is a five foot tall young lady. She is wearing a long\n"+
"blue cloak that covers her from head to foot. She has blond hair that\n"+
"flows just past her shoulders. She is slender and looks young to be\n"+
"a wizard. Her blue eyes take you in all at once with a glance.\n");
set_level(100);
set_hp(200);
set_al(-250);
set_wc(11);
set_ac(10);
  set_chat_chance(5);
  load_chat(query_name()+" says, \"I am the care taker here.\"\n");
  load_chat(query_name()+" says, \"You can't go any father.\"\n");
  load_chat(query_name()+" says, \"There seems to be some problems.\"\n");
  load_chat(query_name()+" says, \"It is being looked into.\"\n");
  load_chat(query_name()+" asks, \"Would you like to come in and have tea?\n");
 
  
}


/* make this npc completely non-fightable */
query_ghost(){ return 1; }

