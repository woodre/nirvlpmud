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
  load_chat("The pool shimmers in the odd light...\n");
  load_chat("The light flickers...\n");
  load_chat("Something is very very strange....\n");
}
