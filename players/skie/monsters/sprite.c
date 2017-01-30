inherit"/obj/monster.c";

void reset(status arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("sprite");
  set_race("creature");
  set_short("a water sprite");
  set_long(
  "a water sprite is here. her\n"+
  "skin and dress shimmer as if they were liquid.\n");

  add_money(120);
  set_level(3);
  set_hp(40);
  set_al(0);
  set_ac(5);
  set_wc(4);
  set_aggressive(0);
  set_chance(5);
  set_spell_dam(3);
  set_spell_mess1(
  "the sprite tosses dirty water in your eyes!!\n");

  set_spell_mess2(
  "You wince as your eyes sting!\n");
}
