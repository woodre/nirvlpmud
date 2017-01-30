inherit "obj/monster";

reset(arg)
{
  if (arg) return;
  ::reset(arg);
  set_name("monster");
  set_alias("vax");
  set_short("Vax, The Network Monster");
  set_long("Vax, the Network monster.  A hideous vax-like creature\n"+
           "covered with a mass of twisting, probing wire cable tendrils\n"+
           "The tendrils grope out and cover the walls and ceilings.\n");
  set_level(24);
  set_ac(20);
  set_wc(36);
  set_hp(700);
  set_chance(35);
  set_spell_mess1("");
  set_spell_mess2("The tissues of your mind scream as the Network monster's tendrils enter your brain !\n");
  set_spell_dam(50);
}
