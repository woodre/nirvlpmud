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
load_chat("The stench of decaying meat almost makes you ill. \n");
load_chat("Your muscles tense involuntarily.... \n");
load_chat("You break out in a cold sweat.. \n");
}
