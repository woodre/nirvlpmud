inherit"/obj/monster.c";

void reset(status arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("spark");
  set_race("creature");
  set_short("A little spark");
  set_long(
  "A little sparkle is floating here. It flashes\n"+
  "with various colors.\n");

  add_money(200);
  set_level(5);
  set_hp(80);
  set_al(0);
  set_ac(7);
  set_wc(12);
  set_aggressive(0);
  set_chance(15);
  set_spell_dam(5);
  set_spell_mess1(
  "The spark zaps you with static electricy!\n");

  set_spell_mess2(
  "A shock runs thru your body!\n");
}
