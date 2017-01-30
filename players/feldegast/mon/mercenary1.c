
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  add_money(700+random(100));
  set_name("hamir");
  set_alt_name("mercenary");
  set_short("Hamir the Mercenary");
  set_long(
    "This mercenary looks suspiciously familiar.  He has a prominent\n"+
    "nose, a moustache, and appears to have a virile and athletic\n"+
    "body.  There's something quite friendly about this mercenary.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(14);
  set_wc(18);
  set_ac(11);
  set_hp(220);
  set_al(400);
  set_chat_chance(5);
  load_chat("Hamir says: I kiss you!\n");
  load_chat("Hamir says: I like sex.\n");
  load_chat("Hamir says: I like travel I go 3-4 country every year.\n");
  load_chat("Hamir says: I like to paint (amimals, towns, nice nude models).\n");
  load_chat("Hamir says: I like to be friendship from different country.\n");
  load_chat("Hamir says: I can invitate you to my home.\n");
  set_a_chat_chance();
  load_a_chat("Hamir says: I kill you!\n");
  load_a_chat("Hamir says: Why do want to hurt I?\n");
  load_a_chat("Hamir says: I wanted only sex!\n");
}
