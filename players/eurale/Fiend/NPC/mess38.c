/*
	This is an invisible monster used to emote messages in
	a room.  Just change the 'load_chat' messages.  */

inherit "obj/monster";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
set_alias("questman");
set_long("A quest object..\n");
  set_level(1);
  set_hp(1000);
  set_al(-1000);
  set_wc(0);
  set_ac(1000);
  set_aggressive(0);

set_chat_chance(10);
  load_chat("The roar of a huge beast can be heard to the south...\n");
  load_chat("Something screeches from off to the north....\n");
  load_chat("You hear a whisper: I want your wishes....\n");
  load_chat("Your palms begin to sweat....\n");
}
