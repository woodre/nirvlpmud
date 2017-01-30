inherit "obj/monster";

reset(arg)
{
  if (arg) return;
  ::reset(arg);
  set_name("Wyrme");
set_alias("wyrme");
set_short("Wyrme, Guardian of the Sword of Wind");
  set_long("Wyrme, Guardian of the Sword of Wind.  Wyrme is as swift\n"+
           "as the winds themselves !  He holds the mythical Sword of Wind.\n");
  set_level(22);
  set_ac(19);
  set_wc(34);
  set_hp(2000);
  set_chat_chance(7);
  load_chat("Wyrme says: Dak, barkdu pnu ?\n");
  load_chat("Wyrme says: GHITHDU AKD FAKTRAI !!!\n");
  load_chat("Wyrme looks at you with a menacing expression\n");
  set_chance(35);
  set_spell_mess1("Wyrme strikes with the force of a thousand tornados!!!\n");
  set_spell_mess2("Wyrme strikes with the force of a thousand tornados !!\n");
  set_spell_dam(40);
}
