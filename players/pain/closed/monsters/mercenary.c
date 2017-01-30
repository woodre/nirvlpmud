inherit "obj/monster";

reset(arg)
{
  object weapon, armor;
  ::reset(arg);
  if(arg) return;
  set_name("mercenary");
   set_race("human");
  set_alias("mercenary");
  set_short("A Mercenary of Terror and Suffering");
  set_long("This is an intellegent, and competent warrior\n"+
  "He is a strong, evil man who deals out death and suffering for his own pleasure\n"+
  "He is not one to be messed with unless you have to\n");
  set_level(20);
  set_hp(500);
  set_al(-500);
  set_wc(30);
  set_ac(17);
  set_money(700);
/*
   set_spell_dam(30);
   set_spell_mess("The Mercenary tears into your very soul with his Blade of Suffering");
   set_chance(5);
*/
   weapon=clone_object("players/pain/closed/weapons/merweap.c");
  move_object(weapon,this_object());
  armor=clone_object("players/pain/closed/armor/merarmor.c");
  move_object(armor,this_object());
}
