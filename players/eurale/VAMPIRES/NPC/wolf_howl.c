/*
	This is an invisible monster used to emote messages in
	a room.  Just change the 'load_chat' messages.  */

inherit "obj/monster";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
set_alias("yakker");
set_long("An invisible emoter for the room\n");
  set_level(1);
  set_hp(1000);
  set_al(-1000);
  set_wc(0);
  set_ac(1000);
  set_aggressive(0);

set_chat_chance(10);
  load_chat("The howl of a wolf comes from the forest to the west.\n");
  load_chat("A wolf howls nearby...\n");
}
