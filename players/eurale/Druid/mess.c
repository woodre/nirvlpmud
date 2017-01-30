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

set_chat_chance(6);
  load_chat("A gentle breeze rustles the leaves of the trees...\n");
  load_chat("The fragrant smell of wild flowers drifts past your nose..\n");
  load_chat("A bird sings softly from up in the trees..\n");
}
