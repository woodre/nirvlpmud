inherit "obj/monster";

reset(arg)
{
  if (arg) return;
  ::reset(arg);
  set_name("guard");
  set_short("A Castle Guard");
  set_long("A tall guard.  He stands motionless....unsmiling.\n");
  set_level(15);
  set_ac(12);
  set_hp(200);
  set_wc(18);
  set_chance(35);
  set_spell_mess1("");
  set_spell_mess2("You hear the whistle of the guard's staff just before you feel it smash into you !!\n");
  set_spell_dam(10);
}
