
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Featherwing");
  set_alt_name("eagle");
  set_alias("featherwing");
  set_short("Featherwing");
  set_long(
"Featherwing is a giant eagle with a wingspan of approximately\n"+
"ten feet.  Her soft feathers are white and a grey verging on\n"+
"dark blue. \n"
);
  set_gender("female");
  set_race("bird");
  set_level(10);
  set_wc(18);
  set_ac(8);
  set_hp(200);
  set_al(0);
  set_chat_chance(5);
  load_chat("Featherwing circles above your head.\n");
  set_a_chat_chance(5);
  load_a_chat("Featherwing swoops down at you.\n");
  load_a_chat("Featherwing buffets you with a gale of wind.\n");
  set_chance(15);
  set_spell_mess1("Featherwing scratches at her opponent"+
"'s eyes with her mighty talons.\n");
  set_spell_mess2(
"Featherwing scratches at your eyes with her mighty talons!\n"
  ); /* 1ST PERSON */
  set_spell_dam(5);
}

heart_beat() {
  ::heart_beat();
  if(attacker_ob && present("elven archer")) {
    if(!present("elven archer")->query_attack())
      present("elven archer")->attacked_by(attacker_ob);
  }
}
