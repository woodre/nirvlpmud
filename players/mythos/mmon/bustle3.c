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
    load_chat("Injected With A Poison plays...\n");
    load_chat("James Brown Is Dead plays...\n");
    load_chat("Lights flash and the air is hot...\n");
    load_chat("Move On Baby plays...\n");
    load_chat("Rough Sex plays...\n");
    load_chat("Drink My Honey plays...\n");
    load_chat("No Limit plays...\n");
    load_chat("You feel the beat smash into you!\n");
    load_chat("Love is Just a Game plays...\n");
    load_chat("Is It Love plays...\n");
    load_chat("Flesh moves, bodies sway, music pulses, and sweat flies...\n");
    load_chat("Take it to the Top plays...\n");
    load_chat("You feel hot, you feel cool...\n");
    load_chat("Laser light plays across the moving masses...\n");
    load_chat("People jostle each other...\n");
}
