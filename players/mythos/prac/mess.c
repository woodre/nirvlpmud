inherit "obj/monster";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("messenger");
  set_short();
  set_level(1);
  set_hp(1000);
  set_al(-1000);
  set_wc(18);
  set_ac(10);
  set_aggressive(0);
  set_chat_chance(8);
    load_chat("The birds chatter quietly... it is sweet and the air is fresh.\n");
    load_chat("The Cicadas cry - a Japanese Summer\n");
    load_chat("The wind sighs.....\n");
}
