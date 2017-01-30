inherit"/obj/monster.c";

void reset(status arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("raindrop");
  set_race("creature");
  set_short("a raindrop");
  set_long(
  "A small raindrop is pooled here. Sunlight\n"+
  "reflects off it's surface creating a rainbow.\n");

  add_money(140);
  set_level(5);
  set_hp(75);
  set_al(1);
  set_ac(4);
  set_wc(10);
  set_aggressive(0);
  set_chance(35);
  set_spell_dam(5);
  set_spell_mess1(
  "The raindrop splashes water on the ground making you slip!\n");

  set_spell_mess2(
  "\nYou slip and fall to the ground!\n");
}
