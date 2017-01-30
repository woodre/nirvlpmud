/*
        This is an invisible monster used to emote messages in
        a room.  Just change the 'load_chat' messages.  */

inherit "obj/monster";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("riverfire");
  set_alias("riverfire");
  set_short("");
  set_level(1);
  set_hp(1000);
  set_al(-1000);
  set_wc(0);
  set_ac(1000);
  set_aggressive(0);

  set_chat_chance(13);
  load_chat("It almost sounds as if the flames were talking...\n");
  load_chat("Something about the flames bothers you.....\n");
  load_chat("The flames dance in the darkness...\n");
  load_chat("The flames mezmerize you, beckoning...come in...\n");
}

short() { return 0; }