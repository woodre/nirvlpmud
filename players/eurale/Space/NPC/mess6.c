/*
	This is an invisible monster used to emote messages in
	a room.  Just change the 'load_chat' messages.  */

inherit "obj/monster";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
set_alias("messenger");
  set_level(1);
  set_hp(1000);
  set_al(-1000);
  set_wc(0);
  set_ac(1000);
  set_aggressive(0);

set_chat_chance(20);
  load_chat("You hear soft shallow breathing coming from the east..\n");
  load_chat("You sense movement coming from the darkness to the south..\n");
  load_chat("A slight scraping sound comes from the west..\n");
  load_chat("You sense danger nearby....\n");
  load_chat("Your heart pounds in your chest....\n");
  load_chat("Was that something else breathing, or you?\n");
}
