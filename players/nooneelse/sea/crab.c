/*
 crab.c
*/

inherit "obj/monster";

reset(arg){
  if (arg) return;
  ::reset(arg);

  set_name("giant crab");
  set_alt_name("crab");
  set_alias("red crab");
  set_short("A giant red crab");
  set_long("This is a giant red crab with large pincers.\n" +
           "Its pincers snap open and closed nervously.\n");
  set_wc(20);
  set_ac(11);
  set_level(15);
  set_hp(1100);
  set_al(0);
  set_aggressive(0);
  set_chance(15);
  set_spell_mess2("The crab grabs you with its pincers and squeezes you\n"+
                  "with great force and throws you to the ground.\n");
  set_spell_mess1("The crab grabs "+
                   call_other(this_player(), "query_name", 0)+"\n"+
                   "and throws its opponent to the ground.\n");
  set_spell_dam(15);
  set_chat_chance(20);
  load_chat("**SNAP**\n");
  load_chat("The crab skitters across the sand.\n");
  load_chat("The crab snaps its pincers shut!\n");
  load_chat("You tremble from fear as the crab looks at you.\n");
}
