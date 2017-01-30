/* Trixie the Hooker
 * Replacement for Trixie code in /room/alley.c
 * Rumplemintz
 */

inherit "obj/monster.talk";

void reset(int arg) {
  if(arg) return;
  ::reset(arg);

  set_name("trixie");
  set_alias("hooker");
  set_alt_name("trixie_zz");
  set_short("Trixie the hooker");
  set_long("She is rather old, and has not aged well.\n");
  set_ac(0);
  set_level(1);
  set_al(125);
  set_ep(30);
  set_hp(20);
  set_wc(5);
  set_aggressive(0);

  set_chat_chance(10);
