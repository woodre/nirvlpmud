inherit "obj/monster";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_alias("talker");
  set_level(1);
  set_hp(1000);
  set_al(-1000);
  set_wc(0);
  set_ac(1000);
  set_aggressive(0);
  set_chat_chance(15);
    load_chat("You listen closely, and hear echos of nameless fears.\n");
    load_chat("The tunnels ahead twist and turn and evil lurks everywhere!\n");
}
