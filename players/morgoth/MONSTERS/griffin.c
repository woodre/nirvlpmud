inherit "obj/monster";

reset(arg)
{
  if (arg) return;
  ::reset(arg);
  set_name("Griffin");
  set_alias("griffin");
  set_short("A Griffin");
  set_long("The griffin is a fierce creature, a lion with wings.  He can\n"+
           "fly while attacking his victim.  His eyes glow red....\n");
  set_level(20);
  set_hp(500);
  set_ac(17);
  set_wc(30);
  set_al(-100);
  set_aggressive(1);
  set_chat_chance(20);
  load_chat("The griffin bares his teeth and stares at you menacingly...\n");
  set_chance(35);
  set_spell_mess2("The griffin flies into you tearing your flesh with his claws and teeth !!!\n");
  set_spell_dam(200);
}
