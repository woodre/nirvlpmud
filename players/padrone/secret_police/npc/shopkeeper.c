/*
 * shopkeeper.c
 * Secret Police shopkeeper
 */

inherit "obj/monster";

void
reset(status arg)
{
  object wep, wep2, membership, key;
#if 0
  monster::reset(arg);
#else
  ::reset(arg);
#endif
  if (arg)
    return;
  set_name("shopkeeper");
  set_alias("the shopkeeper");
  set_short("The shopkeeper");
  set_long("At first glance, this shopkeeper looks like an ordinary\n"+
           "shopkeeper - fat, middle-aged, big and strong. But as\n"+
           "you take a closer look at this particular shopkeeper\n"+
           "you notice some very un-shopkeeper-like features, like\n"+
           "a set of more or less hidden daggers and a pair of dark\n"+
           "sunglasses...\n");
  set_gender("male");
  set_level(4);
#if 0 /* Adjusting for Nirvana monster.guide - Rumplemintz */
  set_hp(250);
#else
  set_hp(60);
  set_ac(4);
  set_wc(7);
#endif
  set_al(80);
  set_chance(20);
  set_spell_dam(10);
  set_spell_mess1("The shopkeeper kicks his opponent very hard.");
  set_spell_mess2("The shopkeeper kicks you very hard. You are hurt!");
  set_chat_chance(20);
  load_chat("The shopkeeper looks at you suspiciously.\n");
  load_chat("The shopkeeper says: Psst! We might have a job for you. Go north, quickly!\n");
  load_chat("The shopkeeper says: Psst! You can earn 10000 gold coins!\n");
  load_chat("The shopkeeper says: You can earn 10000 gold coins!\n");
  load_chat("The shopkeeper says: Psst! We'll give you ten thousand for a small job!\n");
  load_chat("The shopkeeper tries to look like a shopkeeper.\n");
  load_chat("The shopkeeper pretends to be counting some money.\n");

  wep = clone_object("obj/weapon");
  wep->set_name("long, sharp dagger");
  wep->set_alt_name("dagger");
  wep->set_class(7);
  wep->set_value(15);
  wep->set_weight(1);
  wep->set_short("A long, sharp dagger");
  move_object(wep, this_object());
  init_command("wield dagger");

  wep2 = clone_object("/players/padrone/secret_police/npc/obj/sp_dagger");
  move_object(wep2, this_object());

  membership = clone_object("/players/padrone/secret_police/membership");
  move_object(membership, this_object());

  key = clone_object("/obj/key");
  key->set_type("iron");
  key->set_code("interrogation");
  move_object(key, this_object());
}
