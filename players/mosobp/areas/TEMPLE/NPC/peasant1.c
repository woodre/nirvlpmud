inherit "/obj/monster";
reset(arg) {
  ::reset(arg);
  if(arg) return;
set_name("peasant");
set_short("A poor peasant");
set_race("namekian");
set_long(
"This is a typical beggar sitting in the temple trying to get money\n"+
"from people. He looks to be gathering quite a bit of change on \n"+
"him from passer bys. He is wearing scraggly old rags worse even \n"+
"than servant rags. He just looks old, wrinkly, and frail. He is shouting\n"+
"meaningless phrases to everyone that passes by him.\n");
set_level(7);
set_ac(7);
set_wc(4);
set_hp(150);
set_al(0);
set_aggressive(0);
set_chat_chance(10);
load_chat("Peasant SHOUTS: Slowly walk away to be real again.\n");
load_chat("Peasant SHOUTS: Will you now run from the life you've given to me?\n");
load_chat("Peasant SHOUTS: Protect the ones who hold your inner child.\n");
}
