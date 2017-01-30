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
  set_chat_chance(5);
    load_chat("A pair of beautiful white seagulls soar on the breeze overhead.\n");
    load_chat("A jumping fish momentarily shatters the illusion of sheer crystal.\n");
}
