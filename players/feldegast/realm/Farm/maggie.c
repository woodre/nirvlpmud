/*
I love living in Wv.  You meet such interesting people...
*/

inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(!present("crossbow",this_object())) {
    object bow;
    bow=clone_object("/obj/weapon");
    bow->set_class(17);
    bow->set_name("crossbow");
    bow->set_short("Crossbow");
    bow->set_weight(3);
    bow->set_type("bow");
    bow->set_value(850);
    bow->set_long(
"This is a well-maintained heavy crossbow with a black lacquer\n"+
"finish and a smooth stock from frequent use.\n");
    move_object(bow,this_object());
    init_command("wield crossbow");
  }
  if(arg) return;
  set_name("maggie");
  set_alt_name("hick");
  set_alias("woman");
  set_short("Maggie");
  set_long(
"Maggie is a white-haired old farmwoman with a hostile\n"+
"and frighteningly unintelligent expression upon her face.\n"+
"She wears a brown tunic and a baggy pair of pants.  Maggie\n"+
"holds a cocked and readied crossbow in her hands.\n"
);
  set_gender("female");
  set_race("human");
  set_level(14);
  set_wc(18);
  set_ac(11);
  set_hp(210);
  set_al(100);
  set_chat_chance(5);
  load_chat("Maggie says: We don't allow no trespassers on our land.\n");
  load_chat("Maggie says: Git!\n");
  load_chat("Maggie says: Can't you read the sign?\n");
  set_a_chat_chance(5);
  load_a_chat("Maggie yells: Thief!  Liar!  Murderer!\n");
  load_a_chat("Maggie yells: Trespasser!\n");
  set_chance(15);
  set_spell_mess1(
"Maggie cackles gleefully as she hits her target with a bolt\n"+
"from her crossbow.\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"Maggie cackles gleefully as she hits you with a bolt from\n"+
"her crossbow.\n"
  ); /* 1ST PERSON */
  set_spell_dam(10);
}
