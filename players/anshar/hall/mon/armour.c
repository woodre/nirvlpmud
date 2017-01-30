inherit "obj/monster";

reset(arg)
{
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("armour");
  set_race("golem");
  set_alias("suit");
  set_short("An animated suit of armour");
  set_long("   A huge animated suit of silvery armour. Runes flicker\n"+
	   "with a harsh light about the helm and breast, and a deep\n"+
	   "red glow gleams from the visor.\n");
  set_level(19);
  set_hp(475);
  set_al(0);
  set_wc(28);
  set_ac(16);
  set_aggressive(1);

  set_chance(30);
  set_spell_dam(25);
  set_spell_mess1("The armour's surface glows red hot!\n");
  set_spell_mess2("The armour's surface glows red hot!\n"+
    "You are seared by the intense heat!\n");

}
