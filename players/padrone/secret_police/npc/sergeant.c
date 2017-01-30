/* 
 * sergeant.c
 * Secret Police Sergeant
 */

inherit "obj/monster";

void
reset(status arg)
{
  object key, membership, wep;
  monster::reset(arg);
  if (arg)
    return;
  set_name("police sergeant");
  set_alias("sergeant");
  set_short("A police sergeant from the Secret Police");
  set_long("This is a Secret Police sergeant.\n"+
           "He looks big and ugly and brutal.\n");
  set_level(5);
#if 0 /* Adjusting for Nirvana monster.guide -- Rumplemintz */
  set_hp(200);
#else
  set_hp(60);
  set_ac(4);
  set_wc(8);
#endif
  set_al(50);
  set_gender("male");
  set_chance(20);
  set_spell_dam(10);
  set_spell_mess1("The secret police sergeant kicks his opponent very hard.");
  set_spell_mess2("The secret police sergeant kicks you very hard. You are hurt!\n");
  set_aggressive(1);
  membership = clone_object("/players/padrone/secret_police/membership");
  move_object(membership, this_object());
  wep = clone_object("/obj/weapon");
  wep->set_name("short sword");
  wep->set_alias("shortsword");
  wep->set_alt_name("sword");
  wep->set_class(15);
  wep->set_value(700);
  wep->set_weight(2);
  wep->set_short("A short sword");
  move_object(wep, this_object());
  init_command("wield short sword");
  key = clone_object("/obj/key");
  key->set_type("cell");
  key->set_code("celldoor");
  move_object(key, this_object());
}
