/* A drunken sailor, Created <5/12/00> by Jara */

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

  add_money(750);
  set_name("sailor");
  set_short("A drunken sailor");
  set_race("human");
  set_long("The sailor is a young man in his mid-twenties, with brown eyes\n"+
    "and light colored hair. He wears loose fitting clothes and he\n"+
    "smells of rum.\n");
  set_level(14);
  set_ac(11);
  set_wc(18);
  set_hp(220);
  set_al(-100);
  set_aggressive(0);
  set_chat_chance(15);
  set_a_chat_chance(10);
  load_chat("The sailor stumbles over his feet.\n");
  load_chat("The drunken sailor smiles wryly at you.\n");
  load_chat("The sailor hiccups.\n");
  load_a_chat("The drunken sailor lurches at you.\n");
  load_a_chat("The sailor hits you with a solid blow.\n");
   }
}
