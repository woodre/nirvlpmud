inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Master Intolar");
  set_alt_name("intolar");
  set_alias("master");
  set_short("Master Intolar");
  set_long(
"Master Intolar is an aged healer of advancing years with wispy\n"+
"hair and liver-spots on his face.  He wears a simple brown robe\n"+
"tied with a rope belt.  Intolar is a master of the herbal arts\n"+
"and a long-time plant enthusiast
);
  set_gender("male");
  set_race("human");
  set_level(14);
  set_wc(20);
  set_ac(16);
  set_hp(300);
  set_al(1000);
  set_chat_chance(5);
  load_chat("Intolar putters about with his herbs.");
  load_chat("Intolar gently waters a small plant.\n");
  load_chat("Intolar looks at a plant, strokes his chin and says,\"Hmm...\"\n");
  set_chance(15);
  set_spell_mess1(
"Intolar strikes with a devastating blow.\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"Intolar strikes you with the flat of his palm.\n"
  ); /* 1ST PERSON */
  set_spell_dam(35);
}
