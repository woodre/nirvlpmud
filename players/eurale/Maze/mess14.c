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
  set_chat_chance(10);
load_chat("The stillness here is very unnerving..... \n");
load_chat("A small cockroach scurries across the cave floor. \n");
}
