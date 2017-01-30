inherit "obj/monster";

reset(arg)
{
  if (arg) return;
  ::reset(arg);
  set_name("bird");
  set_short("A small bird");
  set_long("A small colorfull bird.\n");
  set_level(5);
  set_ac(5);
  set_wc(9);
  set_chat_chance(40);
  load_chat("Chirp, Chirp !\n");
  load_chat("Tweet, Tweet !\n");
  set_whimpy();
}
