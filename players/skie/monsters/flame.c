inherit"/obj/monster.c";

void reset(status arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("flame");
  set_race("creature");
  set_short("A tiny flame");
  set_long(
  "A tiny flame flickers about. It almost\n"+
  "seems like it is dancing.\n");

  add_money(200);
  set_level(5);
  set_hp(80);
  set_al(0);
  set_ac(7);
  set_wc(12);
  set_aggressive(0);
set_chance(10);
  set_spell_dam(8);
  set_spell_mess1(
  "The tiny flame reaches out and grabs you. !\n");

  set_spell_mess2(
  "You yell and jump back as you get burnt!\n");
}
