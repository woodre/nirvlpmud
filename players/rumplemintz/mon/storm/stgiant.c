inherit "obj/monster";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("Sotrm Giant");
  set_race("giant");
  set_alias("giant");
  set_short("A Storm Giant");
  set_long("A massive giant with white hair, and a black beard.\n");
  set_level(15);
  set_hp(225);
  set_al(-350);
  set_wc(20);
  set_ac(12);
  set_chat_chance(2);
  load_chat("Giant mumbles: Fee Fi Fo Fum!\n");
  load_chat("Giant shouts: Time to die little one!\n");
}
