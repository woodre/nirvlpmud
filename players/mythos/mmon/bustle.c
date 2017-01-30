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
  set_chat_chance(15);
    load_chat("A man in a gray suit walks past you.\n");
    load_chat("A young woman and her two friends walk by.\n");
    load_chat("Two children run about.\n");
    load_chat("An elderly couple walk by.\n");
    load_chat("A young man hurries past.\n");
    load_chat("Loud music plays in the background.\n");
    load_chat("The sound of chatter can be heard.\n");
}
