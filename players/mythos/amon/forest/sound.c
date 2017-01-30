inherit "obj/monster";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_alias("messenger");
  set_level(1);
  set_hp(1000);
  set_al(-1000);
  set_wc(18);
  set_ac(10);
  set_aggressive(0);
  set_chat_chance(25);
  load_chat("The wind moans.\n");
  load_chat("The Tower has an aura of deep anger.\n");
  load_chat("Something tells you,'Odd things happen at the Tower'\n");
  load_chat("Something makes you uneasy.\n");
}
