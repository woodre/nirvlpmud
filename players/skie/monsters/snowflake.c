inherit"/obj/monster.c";

void reset(status arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("snowflake");
  set_race("creature");
  set_short("a small snowflake");
  set_long(
  " A small snowflake is floating here . It sparkles\n"+
  "with many different colors.\n");

  add_money(120);
  set_level(5);
  set_hp(60+random(10));
set_al(-1);
  set_ac(5+random(2));
  set_wc(12);
  set_aggressive(0);
  set_chance(20);
  set_spell_dam(3);
  set_spell_mess1(
  "The light reflects off the snowflake hurting your eyes!\n");

  set_spell_mess2(
  "\nYou grab your eyes in pain!\n");
}
